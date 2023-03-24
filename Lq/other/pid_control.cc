#include <iostream>
#include <cmath>

using namespace std;

// 二维点
struct Point {
    double x;
    double y;
};

// 两点之间的距离
double distance_between_points(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx*dx + dy*dy);
}

// 路径规划
void plan_path(Point start, Point end, double speed, double angular_speed, double dt) {
    double distance = distance_between_points(start.x, start.y, end.x, end.y);
    double time = distance / speed;
    int num_steps = ceil(time / dt);

    double x_step = (end.x - start.x) / num_steps;
    double y_step = (end.y - start.y) / num_steps;

    double current_x = start.x;
    double current_y = start.y;

    for (int i = 0; i < num_steps; i++) {
        Point current_point = {current_x, current_y};

        // 计算当前目标点
        double target_x = start.x + (i+1) * x_step;
        double target_y = start.y + (i+1) * y_step;
        Point target_point = {target_x, target_y};

        // 计算当前距离目标点的距离和角度
        double distance_to_target = distance_between_points(current_x, current_y, target_x, target_y);
        double angle_to_target = atan2(target_y - current_y, target_x - current_x);

        // 控制机器人速度和角速度
        double linear_velocity = speed;
        double angular_velocity = angular_speed * angle_to_target;

        // 输出当前状态
        cout << "Step: " << i+1 << "/" << num_steps << endl;
        cout << "Position: (" << current_x << ", " << current_y << ")" << endl;
        cout << "Target: (" << target_x << ", " << target_y << ")" << endl;
        cout << "Distance to target: " << distance_to_target << endl;
        cout << "Angle to target: " << angle_to_target << endl;
        cout << "Linear velocity: " << linear_velocity << endl;
        cout << "Angular velocity: " << angular_velocity << endl;
        cout << endl;

        // 更新当前位置
        current_x += x_step;
        current_y += y_step;
    }
}

int main() {
    Point start = {0, 0};
    Point end = {10, 10};
    double speed = 1.0;
    double angular_speed = 1.0;
    double dt = 0.1;

    plan_path(start, end, speed, angular_speed, dt);

    return 0;
}
