#include <iostream>
#include <vector>
#include <cmath>

class Point
{
public:
    double x;
    double y;

    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    double distance(Point other) const
    {
        double dx = x - other.x;
        double dy = y - other.y;
        return std::sqrt(dx * dx + dy * dy);
    }
};

class Path
{
public:
    std::vector<Point> points;

    Path() {}

    void add_point(Point point) { points.push_back(point); }

    double length() const
    {
        double length = 0.0;
        for (int i = 0; i < points.size() - 1; i++)
        {
            length += points[i].distance(points[i + 1]);
        }
        return length;
    }
};

class Controller
{
public:
    double max_speed;
    double max_acceleration;

    Controller(double max_speed = 1.0, double max_acceleration = 0.1)
        : max_speed(max_speed), max_acceleration(max_acceleration)
    {
    }

    double calculate_speed(double distance, double time) const
    {
        double target_speed = 2.0 * distance / time;
        double speed = std::min(target_speed, max_speed);
        double acceleration = 2.0 * (target_speed - speed) / time;
        acceleration =
            std::max(std::min(acceleration, max_acceleration), -max_acceleration);
        speed += acceleration * time;
        speed = std::max(std::min(speed, max_speed), 0.0);
        return speed;
    }
};

int main()
{
    // Define the starting and ending points
    Point start(0.0, 0.0);
    Point end(5.0, 5.0);

    // Plan the path between the start and end points
    Path path;
    path.add_point(start);
    path.add_point(Point(2.0, 3.0));
    path.add_point(Point(4.0, 4.0));
    path.add_point(end);

    // Compute the length of the path
    double path_length = path.length();

    // Initialize the controller
    Controller controller(1.0, 0.1);

    // Simulate the motion along the path
    double time = 0.0;
    Point position = start;
    double distance_traveled = 0.0;
    while (position.distance(end) > 0.01)
    {
        // Find the current segment of the path
        int segment_index = 0;
        double segment_length =
            path.points[segment_index].distance(path.points[segment_index + 1]);
        while (distance_traveled + segment_length < path_length * time)
        {
            distance_traveled += segment_length;
            segment_index++;
            segment_length =
                path.points[segment_index].distance(path.points[segment_index + 1]);
        }

        // Compute the distance to the end of the current segment
        double segment_progress =
            (path_length * time - distance_traveled) / segment_length;
        double remaining_distance = segment_length * (1.0 - segment_progress);

        // Calculate the desired speed based on the remaining distance
        double speed = controller.calculate_speed(remaining_distance, 0.1);

        // Move the position along the path at the desired speed
        double dx = path.points[segment_index + 1].x - path.points[segment_index].x;
        double dy = path.points[segment_index + 1].y - path.points[segment_index].y;
        double segment_distance = std::sqrt(dx * dx + dy * dy);
        double segment_time = segment_distance / speed;
        double segment_progress_delta = 0.1 / segment_time;
        segment_progress += segment_progress_delta;
        if (segment_progress > 1.0)
        {
            segment_index++;
            segment_progress = 0.0;
        }
        position.x = path.points[segment_index].x + segment_progress * dx;
        position.y = path.points[segment_index].y +
                     segment_progress * dy; // Print the current position and speed
        std::cout << "Position: (" << position.x << ", " << position.y << ")"
                  << std::endl;
        std::cout << "Speed: " << speed << std::endl;

        // Update the time
        time += 0.1;
    }

    return 0;
}
