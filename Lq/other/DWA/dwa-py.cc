//
// Created by chh3213 on 2022/11/26.
//

#include "dwa.h"

DWA::DWA(double dt, double vMin, double vMax, double wMin, double wMax,
         double predictTime, double aVmax, double aWmax, double vSample, double wSample,
         double alpha, double beta, double gamma, double radius, double judgeDistance)
    : dt(dt),
      v_min(vMin),
      v_max(vMax),
      w_min(wMin),
      w_max(wMax),
      predict_time(predictTime),
      a_vmax(aVmax),
      a_wmax(aWmax),
      v_sample(vSample),
      w_sample(wSample),
      alpha(alpha),
      beta(beta),
      gamma(gamma),
      radius(radius),
      judge_distance(judgeDistance)
{
}

/**
 * 计算速度边界限制Vm
 * @return 速度边界限制后的速度空间Vm
 */
vector<double> DWA::calVelLimit() { return {v_min, v_max, w_min, w_max}; }

/**
 * 计算加速度限制Vd
 * @return
 */
vector<double> DWA::calAccelLimit(double v, double w)
{
    double v_low = v - a_vmax * dt;
    double v_high = v + a_vmax * dt;
    double w_low = w - a_wmax * dt;
    double w_high = w + a_wmax * dt;
    return {v_low, v_high, w_low, w_high};
}

/**
 * 环境障碍物限制Va
 * @param state 当前机器人状态
 * @param obstacle 障碍物位置
 * @return 移动机器人不与周围障碍物发生碰撞的速度空间Va
 */
vector<double> DWA::calObstacleLimit(VectorXd state, vector<Vector2d> obstacle)
{
    double v_low = v_min;
    double v_high = sqrt(2 * _dist(state, obstacle) * a_vmax);
    double w_low = w_min;
    double w_high = sqrt(2 * _dist(state, obstacle) * a_wmax);
    return {v_low, v_high, w_low, w_high};
}

/**
 * 速度采样,得到速度空间窗口
 * @param v 当前时刻线速度
 * @param w 当前时刻角速度
 * @param state 当前机器人状态
 * @param obstacle 障碍物位置
 * @return [v_low,v_high,w_low,w_high]: 最终采样后的速度空间
 */
vector<double> DWA::calDynamicWindowVel(double v, double w, VectorXd state,
                                        vector<Vector2d> obstacle)
{
    vector<double> Vm = calVelLimit();
    vector<double> Vd = calAccelLimit(v, w);
    // vector<double> Va = calObstacleLimit(state, obstacle);
    // double a = max({Vm[0], Vd[0], Va[0]});
    // double b = min({Vm[1], Vd[1], Va[1]});
    // double c = max({Vm[2], Vd[2], Va[2]});
    // double d = min({Vm[3], Vd[3], Va[3]});
    double a = max(Vm[0], Vd[0]);
    double b = min(Vm[1], Vd[1]);
    double c = max(Vm[2], Vd[2]);
    double d = min(Vm[3], Vd[3]);
    return {a, b, c, d};
}

/**
 * 计算当前移动机器人距离障碍物最近的几何距离
 * @param state 当前机器人状态
 * @param obstacle 所有障碍物位置
 * @return 移动机器人距离障碍物最近的几何距离
 */
double DWA::_dist(VectorXd state, vector<Vector2d> obstacle)
{
    double min_dist = 100000;
    for (Vector2d obs : obstacle)
    {
        double distance = sqrt((obs._0 - state._0) * (obs._0 - state._0) +
                               (obs._1 - state._1) * (obs._1 - state._1));
        min_dist = distance > min_dist ? min_dist : distance;
    }
    return min_dist;
}

/**
 * 机器人运动学模型
 * @param state 状态量---x,y,yaw,v,w
 * @param control 控制量---v,w,线速度和角速度
 * @param dt 采样时间
 * @return 下一步的状态
 */
VectorXd DWA::kinematicModel(VectorXd state, vector<double> control, double dt)
{
    state._2 += control[1] * dt;
    state._0 += control[0] * cos(state._2) * dt;
    state._1 += control[0] * sin(state._2) * dt;
    // while (state._2 > PI)
    // {
    //     state._2 -= PI * 2;
    // }
    // while (state._2 < -PI)
    // {
    //     state._2 += PI * 2;
    // }
    state._3 = control[0];
    state._4 = control[1];

    return state;
}

/**
 * 轨迹推算
 * @param state 当前状态---x,y,yaw,v,w
 * @param v 当前时刻线速度
 * @param w 当前时刻线速度
 * @return 推算后的轨迹
 */
vector<VectorXd> DWA::trajectoryPredict(VectorXd state, double v, double w)
{
    vector<VectorXd> trajectory;
    trajectory.push_back(state);
    double time = 0;
    while (time <= predict_time)
    {
        state = kinematicModel(state, {v, w}, dt);
        trajectory.push_back(state);
        time += dt;
    }
    return trajectory;
}

/**
 * 轨迹评价函数,评价越高，轨迹越优
 * @param state 当前状态---x,y,yaw,v,w
 * @param goal 目标点位置，[x,y]
 * @param obstacle 障碍物位置，dim:[num_ob,2]
 * @return 最优控制量、最优轨迹
 */
pair<vector<double>, vector<VectorXd>> DWA::trajectoryEvaluation(
    VectorXd state, Vector2d goal, vector<Vector2d> obstacle)
{
    double G_max = 10000000;         // 最优评价
    vector<VectorXd> trajectory_opt; // 最优轨迹
    trajectory_opt.push_back(state);
    vector<double> control_opt = {0., 0.}; // 最优控制
    vector<double> dynamic_window_vel =
        calDynamicWindowVel(state._3, state._4, state, obstacle); // 第1步--计算速度空间

    double sum_heading = 0.0, sum_dist = 0.0,
           sum_vel = 0.0; // 统计全部采样轨迹的各个评价之和，便于评价的归一化
    double v = dynamic_window_vel[0];
    double w = dynamic_window_vel[2];
    // while (v < dynamic_window_vel[1])
    // {
    //     while (w < dynamic_window_vel[3])
    //     {
    //         vector<VectorXd> trajectory = trajectoryPredict(state, v, w);
    //         double heading_eval = alpha * _heading(trajectory, goal);
    //         double dist_eval = beta * _distance(trajectory, obstacle);
    //         double vel_eval = gamma * _velocity(trajectory);
    //         sum_vel += vel_eval;
    //         sum_dist += dist_eval;
    //         sum_heading += heading_eval;
    //         w += w_sample;
    //     }
    //     v += v_sample;
    // }
    sum_heading = 1.0, sum_dist = 1.0, sum_vel = 1.0; // 不进行归一化
    v = dynamic_window_vel[0];
    w = dynamic_window_vel[2];
    while (v < dynamic_window_vel[1])
    {
        while (w < dynamic_window_vel[3])
        {
            vector<VectorXd> trajectory =
                trajectoryPredict(state, v, w); // 第2步--轨迹推算

            double heading_eval = alpha * _heading(trajectory, goal) / sum_heading;
            double dist_eval = beta * _distance(trajectory, obstacle) / sum_dist;
            double vel_eval = gamma * _velocity(trajectory) / sum_vel;
            double G = heading_eval + dist_eval + vel_eval; // 第3步--轨迹评价

            if (G_max >= G)
            {
                G_max = G;
                trajectory_opt = trajectory;
                control_opt = {v, w};
                if (fabs(control_opt[0]) < 0.001 && fabs(state._3) < 0.001)
                {
                    control_opt[1] = -a_wmax;
                }
            }
            w += w_sample;
        }
        v += v_sample;
        w = dynamic_window_vel[2];
    }
    return {control_opt, trajectory_opt};
}

/**
 * 方位角评价函数
 * 评估在当前采样速度下产生的轨迹终点位置方向与目标点连线的夹角的误差
 * @param trajectory 轨迹，dim:[n,5]
 * @param goal 目标点位置[x,y]
 * @return 方位角评价数值
 */
double DWA::_heading(vector<VectorXd> trajectory, Vector2d goal)
{
    // Vector2d dxy = goal - trajectory[trajectory.size() - 1].head(2);
    double dx = goal._0 - trajectory[trajectory.size() - 1]._0;
    double dy = goal._1 - trajectory[trajectory.size() - 1]._1;
    double error_angle = atan2(dy, dx);
    double cost_angle = error_angle - trajectory[trajectory.size() - 1]._2;
    // double cost = PI - abs(cost_angle);
    // return cost;
    return fabs(atan2(sin(cost_angle), cos(cost_angle)));
}

double DWA::_goal(vector<VectorXd> trajectory, Vector2d goal)
{
    double dx = goal._0 - trajectory[trajectory.size() - 1]._0;
    double dy = goal._1 - trajectory[trajectory.size() - 1]._1;
    return -(sqrt(dx * dx + dy * dy));
}

/**
 * 速度评价函数
 * 表示当前的速度大小，可以用模拟轨迹末端位置的线速度的大小来表示
 * @param trajectory 轨迹，dim:[n,5]
 * @return 速度评价值
 */
double DWA::_velocity(vector<VectorXd> trajectory)
{
    // return fabs(trajectory[trajectory.size() - 1]._3);
    return v_max - trajectory[trajectory.size() - 1]._3;
}

/**
 * 距离评价函数
 * 表示当前速度下对应模拟轨迹与障碍物之间的最近距离；
 * 如果没有障碍物或者最近距离大于设定的阈值，那么就将其值设为一个较大的常数值。
 * @param trajectory 轨迹，dim:[n,5]
 * @param obstacle 障碍物位置，dim:[num_ob,2]
 * @return 距离评价值
 */
double DWA::_distance(vector<VectorXd> trajectory, vector<Vector2d> obstacle)
{
    double min_r = 10000000;
    for (Vector2d obs : obstacle)
    {
        for (VectorXd state : trajectory)
        {
            // Vector2d dxy = obs - state.head(2);
            double dx = obs._0 - state._0;
            double dy = obs._1 - state._1;
            double r = sqrt(dx * dx + dy * dy);
            min_r = min_r > r ? r : min_r;
        }
    }
    // if (min_r < radius + 0.2)
    // {
    //     return min_r;
    // }
    // else
    // {
    //     return judge_distance;
    // }
    return 1.0 / min_r;
}

/**
 * 滚动窗口算法控制器
 * @param state 机器人当前状态--[x,y,yaw,v,w]
 * @param goal 目标点位置，[x,y]
 * @param obstacle 障碍物位置，dim:[num_ob,2]
 * @return  最优控制量[v,w]、最优轨迹
 */
pair<vector<double>, vector<VectorXd>> DWA::dwaControl(VectorXd state, Vector2d goal,
                                                       vector<Vector2d> obstacle)
{
    pair<vector<double>, vector<VectorXd>> res =
        trajectoryEvaluation(state, goal, obstacle);
    return res;
}

int main()
{
    VectorXd state = VectorXd(24.75, 38.75, PI / 8.0, 0.0, 0.0);
    // state << ;             //[x(m), y(m), yaw(rad), v(m/s), omega(rad/s)]

    // Vector2d goal(24, 31); // 目标点
    // double dt = 0.1;      // 采样时间
    // double v_min = -0.5, v_max = 6.0, w_min = -PI,
    //        w_max = PI;                             // 线速度角速度边界
    // double predict_time = 3.0;                     // 轨迹推算时间长度
    // double a_vmax = 2, a_wmax = 2 * PI / 3;        // 线加速度和角加速度最大值
    // double v_sample = 0.1, w_sample = PI / 90;     // 采样分辨率
    // double alpha = 0.25, beta = 0.02, gamma = 0.8; // 轨迹评价函数系数

    Vector2d goal(24.75, 31.75); // 目标点
    double dt = 0.02;      // 采样时间
    double v_min = -2, v_max = 6.0, w_min = -PI,
           w_max = PI;                             // 线速度角速度边界
    double predict_time = 2.0;                     // 轨迹推算时间长度
    double a_vmax = 3, a_wmax = 2 * PI / 3;        // 线加速度和角加速度最大值
    double v_sample = 0.02, w_sample = PI / 90;    // 采样分辨率
    double alpha = 0.25, beta = 0.02, gamma = 1.0; // 轨迹评价函数系数

    double radius = 0.4; // 用于判断是否到达目标点
    double judge_distance =
        10; // 若与障碍物的最小距离大于阈值（例如这里设置的阈值为robot_radius+0.2）,则设为一个较大的常值
    vector<Vector2d> obstacle; // 障碍物位置
    // obstacle.push_back(Vector2d(-1, -1));
    // obstacle.push_back(Vector2d(0, 2));
    // obstacle.push_back(Vector2d(4, 2));
    // obstacle.push_back(Vector2d(5, 4));
    // obstacle.push_back(Vector2d(5, 5));
    obstacle.push_back(Vector2d(5, 6));
    // obstacle.push_back(Vector2d(5, 9));
    // obstacle.push_back(Vector2d(8, 9));
    // obstacle.push_back(Vector2d(7, 9));
    // obstacle.push_back(Vector2d(8, 10));
    // obstacle.push_back(Vector2d(9, 11));
    // obstacle.push_back(Vector2d(12, 13));
    // obstacle.push_back(Vector2d(12, 12));
    // obstacle.push_back(Vector2d(15, 15));
    obstacle.push_back(Vector2d(13, 13));

    vector<VectorXd> trajectory;
    trajectory.push_back(state);
    // 初始化
    DWA dwa(dt, v_min, v_max, w_min, w_max, predict_time, a_vmax, a_wmax, v_sample,
            w_sample, alpha, beta, gamma, radius, judge_distance);

    // 保存画图数据
    vector<double> x_, y_, predict_x, predict_y;
    while (true)
    {
        pair<vector<double>, vector<VectorXd>> res =
            dwa.dwaControl(state, goal, obstacle);
        state = dwa.kinematicModel(state, res.first, dt);
        cout << "x: " << state._0 << endl;
        cout << "y: " << state._1 << endl;
        cout << "a: " << state._2 << endl;
        cout << "v: " << state._3 << endl;
        cout << "w: " << state._4 << endl;
        cout << endl;
        trajectory.push_back(state);

        x_.push_back(state._0);
        y_.push_back(state._1);

        double dx = state._0 - goal._0;
        double dy = state._1 - goal._1;
        double dist_to_goal = sqrt(dx * dx + dy * dy);
        if (dist_to_goal <= radius) break;
    }

    return 0;
}