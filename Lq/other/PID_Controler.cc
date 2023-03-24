#include <iostream>
#include <cmath>

/*

在这个示例代码中，我们定义了一个PIDController类，它具有计算控制输出的方法。
然后我们定义了一个Robot类，它包含位置和角度信息，以及三个PID控制器，用于控制x，y和角度。
在move方法中，我们使用PID控制器计算出x和y方向上的速度，以及旋转到目标角度的速度。
最终，我们根据速度和时间更新机器人的位置和角度。

在主函数中，我们定义了起点和终点，并创建了一个机器人对象。
然后我们使用一个循环，不断调用机器人的move方法，直到机器人到达终点位置。

请注意，这只是一个简单的示例代码，并不考虑障碍物避免等问题。
在实际应用中，你需要考虑更多的因素，以确保机器人能够安全地到达目标位置。

*/
using namespace std;

class PIDController
{
public:
    double Kp, Ki, Kd;
    double error, integral, derivative, prev_error;

    PIDController(double kp, double ki, double kd)
        : Kp(kp), Ki(ki), Kd(kd), error(0), integral(0), derivative(0), prev_error(0)
    {
    }

    double compute(double setpoint, double actual_value)
    {
        error = setpoint - actual_value;
        integral += error;
        derivative = error - prev_error;
        prev_error = error;
        return Kp * error + Ki * integral + Kd * derivative;
    }
};

class Position
{
public:
    double x, y;
    Position(double x, double y) : x(x), y(y) {}

    double distanceTo(Position other)
    {
        double dx = other.x - x;
        double dy = other.y - y;
        return sqrt(dx * dx + dy * dy);
    }
};

class Robot
{
public:
    Position position;
    double angle;
    double max_speed;
    double max_turn_speed;

    double speed;
    double turn_speed;

    PIDController pid_x;
    PIDController pid_y;
    PIDController pid_theta;

    Robot(Position pos, double angle, double max_speed, double max_turn_speed,
          double kp_x, double ki_x, double kd_x, double kp_y, double ki_y, double kd_y,
          double kp_theta, double ki_theta, double kd_theta)
        : position(pos),
          angle(angle),
          max_speed(max_speed),
          max_turn_speed(max_turn_speed),
          pid_x(kp_x, ki_x, kd_x),
          pid_y(kp_y, ki_y, kd_y),
          pid_theta(kp_theta, ki_theta, kd_theta)
    {
    }

    void move(Position target, double dt)
    {
        double dx = pid_x.compute(target.x, position.x);
        double dy = pid_y.compute(target.y, position.y);
        double distance = position.distanceTo(target);
        double angle_to_target = atan2(target.y - position.y, target.x - position.x);
        double turn_angle = pid_theta.compute(angle_to_target, angle);
        double turn_speed = turn_angle > 0 ? min(turn_angle, max_turn_speed)
                                           : max(-turn_angle, -max_turn_speed);
        double speed = min(distance, max_speed);
        angle += turn_speed * dt;
        position.x += cos(angle) * speed * dt + dx;
        position.y += sin(angle) * speed * dt + dy;

        this->speed = speed;
        this->turn_speed = turn_speed;
    }
};

int main()
{
    Position start_pos(0, 0);
    Position end_pos(10, 10);
    Robot robot(start_pos, 0, 1, 1, 0.1, 0.01, 0.05, 0.1, 0.01, 0.05, 0.1, 0.1, 0.001);

    double dt = 0.1;
    double time = 0;
    while (robot.position.distanceTo(end_pos) > 0.1)
    {
        robot.move(end_pos, dt);
        time += dt;
        cout << "Time: " << time << ", Position: (" << robot.position.x << ", "
             << robot.position.y << "), Angle: " << robot.angle << endl;
        cout << robot.speed << " " << robot.turn_speed << endl;
    }

    cout << "Reached end position in " << time << " seconds." << endl;

    return 0;
}