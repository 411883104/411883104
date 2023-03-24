/*
 * @Author       : Outsider
 * @Date         : 2023-03-21 11:48:36
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-21 11:48:45
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\other\vc.cc
 */
#include <iostream>
#include <cmath>

struct Point {
    double x;
    double y;
};

struct Path {
    Point start;
    Point end;
};

double distance(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return std::sqrt(dx*dx + dy*dy);
}

double angle(Point a, Point b) {
    return std::atan2(b.y-a.y, b.x-a.x);
}

int main() {
    // 定义起点和终点
    Point start = {0, 0};
    Point end = {10, 10};

    // 定义路径
    Path path = {start, end};

    // 计算路径长度
    double pathLength = distance(path.start, path.end);

    // 定义机器人当前位置和速度
    Point robotPosition = start;
    double linearVelocity = 0;
    double angularVelocity = 0;

    // 定义控制参数
    double linearKp = 1;
    double angularKp = 1;

    // 定义循环次数和时间间隔
    int numSteps = 1000;
    double timeStep = 0.01;

    // 循环控制机器人移动
    for (int i = 0; i < numSteps; i++) {
        // 计算机器人与目标点的距离和角度
        double distanceToTarget = distance(robotPosition, end);
        double targetAngle = angle(robotPosition, end);

        // 计算线速度和角速度
        linearVelocity = linearKp * distanceToTarget;
        angularVelocity = angularKp * (targetAngle - angle(robotPosition, robotPosition) );

        // 控制机器人移动
        robotPosition.x += linearVelocity * std::cos(angularVelocity) * timeStep;
        robotPosition.y += linearVelocity * std::sin(angularVelocity) * timeStep;

        // 输出当前位置和速度
        std::cout << "Robot position: (" << robotPosition.x << ", " << robotPosition.y << ")\n";
        std::cout << "Linear velocity: " << linearVelocity << "\n";
        std::cout << "Angular velocity: " << angularVelocity << "\n\n";

        // 如果机器人到达目标点，则退出循环
        if (distance(robotPosition, end) < 0.1) {
            break;
        }
    }

    return 0;
}
