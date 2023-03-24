#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// 运动学参数
const double L = 2.5; // 车轮轴距
#define M_PI 3.1415926
// DWA算法参数
const double MAX_SPEED = 5.0;           // 最大速度
const double MIN_SPEED = 0.0;           // 最小速度
const double MAX_ACCEL = 1.0;           // 最大加速度
const double MAX_YAWRATE = M_PI / 3.0;  // 最大转向角速度
const double MAX_DYAWRATE = M_PI / 6.0; // 最大转向角加速度
const double DT = 0.1;                  // 时间步长
const double PREDICT_TIME = 2.0;        // 预测时间
const double TO_GOAL_COST_GAIN = 0.15;  // 到达目标的成本系数
const double OBSTACLE_COST_GAIN = 1.0;  // 避障的成本系数

// 二维点结构体
struct Point2D
{
    double x;
    double y;

    Point2D(double x_, double y_) : x(x_), y(y_) {}
};

// 二维向量结构体
struct Vector2D
{
    double x;
    double y;

    Vector2D(double x_, double y_) : x(x_), y(y_) {}

    // 重载加号运算符
    Vector2D operator+(const Vector2D& v) const { return Vector2D(x + v.x, y + v.y); }

    // 重载减号运算符
    Vector2D operator-(const Vector2D& v) const { return Vector2D(x - v.x, y - v.y); }

    // 重载乘法运算符
    Vector2D operator*(double s) const { return Vector2D(x * s, y * s); }

    // 重载除法运算符
    Vector2D operator/(double s) const { return Vector2D(x / s, y / s); }

    // 计算向量长度
    double length() const { return sqrt(x * x + y * y); }

    // 计算向量角度
    double angle() const { return atan2(y, x); }

    // 计算向量的单位向量
    Vector2D unit() const
    {
        double len = length();
        if (len > 0.0)
        {
            return *this / len;
        }
        return *this;
    }
};

// 车辆状态结构体
struct CarState
{
    Point2D pos;    // 车辆位置
    double v;       // 车辆速度
    double yaw;     // 车辆航向角
    double yawrate; // 车辆转向角速度

    CarState(Point2D pos_, double v_, double yaw_, double yawrate_)
        : pos(pos_), v(v_), yaw(yaw_), yawrate(yawrate_)
    {
    }
};

// 轨迹点
// 轨迹点结构体
struct TrajectoryPoint
{
    vector<Vector2D> path; // 路径点
    double v;              // 速度
    double yaw;            // 转向角
    double yawrate;        // 转向角速度
    double time;           // 时间
    TrajectoryPoint(vector<Vector2D> path_, double v_, double yaw_, double yawrate_,
                    double time_)
        : path(path_), v(v_), yaw(yaw_), yawrate(yawrate_), time(time_)
    {
    }
};

// 计算下一个状态
CarState getNextState(const CarState& state, double v, double yawrate, double dt)
{
    CarState next_state(state);
    next_state.pos.x += state.v * cos(state.yaw) * dt;
    next_state.pos.y += state.v * sin(state.yaw) * dt;
    next_state.yaw += state.yawrate * dt;
    next_state.v += v * dt;
    next_state.yawrate += yawrate * dt;
    return next_state;
}

// 计算轨迹
TrajectoryPoint calculateTrajectory(const CarState& state, double v, double yawrate,
                                    double dt, double predict_time)
{
    vector<Vector2D> path;
    double time = 0.0;
    CarState current_state(state);
    while (time < predict_time)
    {
        path.push_back(Vector2D(current_state.pos.x, current_state.pos.y));
        current_state = getNextState(current_state, v, yawrate, dt);
        time += dt;
    }
    return TrajectoryPoint(path, v, current_state.yaw, current_state.yawrate, time);
}

// 计算距离
double distance(double x1, double y1, double x2, double y2)
{
    return hypot(x1 - x2, y1 - y2);
}

// 计算到达目标点的成本
double calculateToGoalCost(const CarState& state, const Point2D& goal)
{
    double dx = goal.x - state.pos.x;
    double dy = goal.y - state.pos.y;
    double distance_to_goal = hypot(dx, dy);
    double angle_to_goal = atan2(dy, dx);
    double yaw_diff = fabs(angle_to_goal - state.yaw);
    return distance_to_goal + yaw_diff * TO_GOAL_COST_GAIN;
}

// 计算避障成本
double calculateObstacleCost(const TrajectoryPoint& point,
                             const vector<Point2D>& obstacles)
{
    double obstacle_cost = 0.0;
    for (const auto& obstacle : obstacles)
    {
        for (const auto& p : point.path)
        {
            double d = distance(obstacle.x, obstacle.y, p.x, p.y);
            if (d < 2.0)
            {
                obstacle_cost += (2.0 - d) * OBSTACLE_COST_GAIN;
            }
        }
    }
    return obstacle_cost;
}

// DWA算法规划主函数
TrajectoryPoint dwa(const CarState& state, const Point2D& goal,
                    const vector<Point2D>& obstacles)
{
    TrajectoryPoint best_path({state.pos}, state.v, state.yaw, state.yawrate, 0.0);
    double best_cost = 1e9;
    for (double v = MIN_SPEED; v <= MAX_SPEED; v += 0.5)
    {
        for (double yawrate = -MAX_YAWRATE; yawrate <= MAX_YAWRATE; yawrate += M_PI / 40)
        {
            TrajectoryPoint point =
                calculateTrajectory(state, v, yawrate, DT, PREDICT_TIME);
            double to_goal_cost = calculateToGoalCost(point.path.back(), goal);
            double obstacle_cost = calculateObstacleCost(point, obstacles);
            double total_cost = to_goal_cost + obstacle_cost;
            if (total_cost < best_cost)
            {
                best_path = point;
                best_cost = total_cost;
            }
        }
    }
    return best_path;
}
// 主函数
int main()
{
    // 设置起点、终点、障碍物
    CarState start_state({0.0, 0.0}, 0.0, 0.0, 0.0);
    Point2D goal(5.0, 5.0);
    vector<Point2D> obstacles{{1.0, 1.0}, {3.0, 3.0}, {4.0, 4.0}};
    // 进行DWA规划
    TrajectoryPoint result = dwa(start_state, goal, obstacles);

    // 输出结果
    cout << "Final path:" << endl;
    for (const auto& p : result.path)
    {
        cout << "(" << p.x << ", " << p.y << ")" << endl;
    }
    cout << "Velocity: " << result.v << endl;
    cout << "Yaw: " << result.yaw << endl;
    cout << "Yawrate: " << result.yawrate << endl;
    cout << "Time: " << result.time << endl;

    return 0;
}