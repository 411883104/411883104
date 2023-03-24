#include <iostream>
#include <cmath>

struct Point
{
    double x, y;
};

struct Path
{
    Point start, end;
};

class Controller
{
public:
    Controller(double kP, double maxSpeed) : kP_(kP), maxSpeed_(maxSpeed) {}

    double calcAngularVelocity(const Point& currPos, double currHeading,
                               const Point& targetPos)
    {
        double targetHeading = atan2(targetPos.y - currPos.y, targetPos.x - currPos.x);
        double angularError = targetHeading - currHeading;
        if (angularError > M_PI) angularError -= 2.0 * M_PI;
        if (angularError < -M_PI) angularError += 2.0 * M_PI;
        double angularVelocity = kP_ * angularError;
        return angularVelocity;
    }

    double calcLinearVelocity(const Point& currPos, double currHeading,
                              const Point& targetPos)
    {
        double dist =
            sqrt(pow(targetPos.x - currPos.x, 2) + pow(targetPos.y - currPos.y, 2));
        double linearVelocity = std::min(dist, maxSpeed_);
        return linearVelocity;
    }

private:
    double kP_;
    double maxSpeed_;
};

class PathPlanner
{
public:
    PathPlanner(double pathResolution) : pathResolution_(pathResolution) {}

    std::vector<Point> planPath(const Point& startPos, const Point& endPos)
    {
        std::vector<Point> path;
        double dist = sqrt(pow(endPos.x - startPos.x, 2) + pow(endPos.y - startPos.y, 2));
        int numSteps = std::max(1, static_cast<int>(std::round(dist / pathResolution_)));
        double dx = (endPos.x - startPos.x) / numSteps;
        double dy = (endPos.y - startPos.y) / numSteps;
        for (int i = 0; i < numSteps; i++)
        {
            double x = startPos.x + i * dx;
            double y = startPos.y + i * dy;
            path.push_back({x, y});
        }
        path.push_back(endPos);
        return path;
    }

private:
    double pathResolution_;
};

int main()
{
    Point startPos = {0.0, 0.0};
    Point endPos = {10.0, 5.0};
    double pathResolution = 0.5;
    double maxSpeed = 1.0;
    double kP = 1.0;
    double currHeading = 0.0;
    Point currPos = startPos;

    PathPlanner planner(pathResolution);
    std::vector<Point> path = planner.planPath(startPos, endPos);
    Controller controller(kP, maxSpeed);

    for (auto targetPos : path)
    {
        double angularVelocity =
            controller.calcAngularVelocity(currPos, currHeading, targetPos);
        double linearVelocity =
            controller.calcLinearVelocity(currPos, currHeading, targetPos);
        std::cout << "Target Pos: (" << targetPos.x << ", " << targetPos.y << ") ";
        std::cout << "Angular Velocity: " << angularVelocity << " ";
        std::cout << "Linear Velocity: " << linearVelocity << std::endl;
        // 这里可以将机器人的速度和角度控制反馈给硬件或者仿真
        // 更新当前机器人的位置和朝向，这里为了简化假设机器人匀速直线运动
        double dx = targetPos.x - currPos.x;
        double dy = targetPos.y - currPos.y;
        currPos.x += dx / dist * linearVelocity;
        currPos.y += dy / dist * linearVelocity;
        currHeading = atan2(dy, dx);
    }

    return 0;
}