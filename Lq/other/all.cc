#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// 机器人位置结构体
struct Pose
{
    double x;     // x坐标
    double y;     // y坐标
    double theta; // 朝向角度
};

// 障碍物结构体
struct Obstacle
{
    double x;      // x坐标
    double y;      // y坐标
    double radius; // 半径
};

// 路径规划函数，返回机器人到达终点的路径
vector<Pose> planPath(Pose start, Pose end, vector<Obstacle> obstacles)
{
    // TODO: 使用路径规划算法，找到无障碍物的路径
    vector<Pose> path;
    path.push_back(start);
    path.push_back(end);
    return path;
}

// 速度规划函数，返回机器人在路径上的速度
vector<double> planVelocity(vector<Pose> path, double maxAcceleration, double maxSpeed)
{
    // TODO: 使用Trajectory planning算法，规划速度曲线
    vector<double> velocity;
    velocity.push_back(0);
    for (int i = 1; i < path.size(); i++)
    {
        double dist =
            sqrt(pow(path[i].x - path[i - 1].x, 2) + pow(path[i].y - path[i - 1].y, 2));
        double maxVel = sqrt(2 * maxAcceleration * dist);
        if (maxVel > maxSpeed)
        {
            maxVel = maxSpeed;
        }
        velocity.push_back(maxVel);
    }
    return velocity;
}

// 控制器函数，实现机器人的运动控制
void controller(vector<Pose> path, vector<double> velocity)
{
    // TODO: 使用PID控制器等算法，实现机器人的运动控制
    cout << "Start moving" << endl;
    for (int i = 0; i < path.size(); i++)
    {
        cout << "Moving to pose (" << path[i].x << ", " << path[i].y << ", "
             << path[i].theta << ") with velocity " << velocity[i] << endl;
    }
    cout << "Arrived at the destination" << endl;
}
const double M_PI = 3.1415926;
int main()
{
    Pose start = {0, 0, 0};                   // 起点
    Pose end = {10, 10, M_PI / 4};            // 终点
    vector<Obstacle> obstacles = {{5, 5, 2}}; // 障碍物，一个圆形障碍物
    double maxAcceleration = 1.0;             // 最大加速度
    double maxSpeed = 2.0;                    // 最大速度

    // 路径规划
    vector<Pose> path = planPath(start, end, obstacles);

    // 速度规划
    vector<double> velocity = planVelocity(path, maxAcceleration, maxSpeed);

    // 控制器
    controller(path, velocity);

    return 0;
}

// // 机器人路径规划和速度控制函数
// // 输入参数：
// // start_pose: 起始位姿
// // goal_pose: 目标位姿
// // max_velocity: 最大速度
// // max_acceleration: 最大加速度
// // max_angular_velocity: 最大角速度
// // output: 机器人控制指令，包括线速度和角速度
// void plan_and_control(Pose2D start_pose, Pose2D goal_pose, 
//                       double max_velocity, double max_acceleration,
//                       double max_angular_velocity, ControlCommand& output) 
// {
//     // TODO: 路径规划算法，根据起始位姿和目标位姿计算机器人的运动轨迹
    
//     // TODO: 速度规划算法，根据运动轨迹和最大速度、加速度、角速度等参数计算机器人的速度控制指令
    
//     // TODO: 控制器实现，根据速度控制指令，计算机器人实际的线速度和角速度，并输出到控制器
//     // 控制器可以是PID控制器、模型预测控制器或其他类型的控制器
// }
