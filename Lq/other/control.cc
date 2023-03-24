#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
// 定义节点类
class Node
{
public:
    int x;        // 节点x坐标
    int y;        // 节点y坐标
    int g;        // 起始点到该节点的移动代价
    int h;        // 该节点到终点的启发式估价
    int f;        // 该节点的总代价
    Node* parent; // 该节点的父节点指针
    Node(int x, int y, int g, int h, Node* parent)
        : x(x), y(y), g(g), h(h), parent(parent)
    {
        f = g + h;
    }
};

// 定义比较函数
class Compare
{
public:
    bool operator()(Node* n1, Node* n2) { return n1->f > n2->f; }
};

// 定义A*算法函数
std::vector<Node*> AStar(Node* start, Node* goal)
{
    std::vector<Node*> path; // 存放路径的向量
    std::priority_queue<Node*, std::vector<Node*>, Compare> open_list; // 开放列表
    std::vector<Node*> closed_list;                                    // 关闭列表

    open_list.push(start);
    while (!open_list.empty())
    {
        Node* current = open_list.top();
        open_list.pop();

        if (current == goal)
        {
            while (current != nullptr)
            {
                path.insert(path.begin(), current);
                current = current->parent;
            }
            return path;
        }

        closed_list.push_back(current);

        // 扩展当前节点
        for (int i = -1; i <= 1; ++i)
        {
            for (int j = -1; j <= 1; ++j)
            {
                if (i == 0 && j == 0) continue;
                int new_x = current->x + i;
                int new_y = current->y + j;
                int new_g = current->g + std::abs(i) + std::abs(j);
                int new_h = std::abs(new_x - goal->x) + std::abs(new_y - goal->y);
                Node* neighbor = new Node(new_x, new_y, new_g, new_h, current);
                bool in_closed_list = false;
                for (auto node : closed_list)
                {
                    if (neighbor->x == node->x && neighbor->y == node->y)
                    {
                        in_closed_list = true;
                        break;
                    }
                }
                if (in_closed_list) continue;
                bool in_open_list = false;
                std::vector<Node*> ss;
                while (!open_list.empty())
                {
                    ss.push_back(open_list.top());
                    open_list.pop();
                }
                for (auto node : ss)
                {
                    if (neighbor->x == node->x && neighbor->y == node->y)
                    {
                        if (neighbor->f < node->f)
                        {
                            node->f = neighbor->f;
                            node->g = neighbor->g;
                            node->parent = neighbor->parent;
                        }
                        in_open_list = true;
                        break;
                    }
                }
                if (!in_open_list)
                {
                    open_list.push(neighbor);
                }
                for (auto node : ss)
                {
                    open_list.push(node);
                }
            }
        }
    }

    return path;
}

#include <iostream>

double pid_control(double error, double pre_error, double integral, double kp, double ki,
                   double kd, double dt, double max_output)
{
    double derivative = (error - pre_error) / dt;
    double output = kp * error + ki * integral + kd * derivative;
    if (output > max_output) output = max_output;
    if (output < -max_output) output = -max_output;
    return output;
}

void velocity_control(double max_speed, double dt, double current_pos, double target_pos,
                      double current_speed, double target_speed, double kp, double ki,
                      double kd)
{
    double error = target_pos - current_pos;
    double pre_error = error;
    double integral = 0.0;
    double output;
    while (std::abs(error) > 0.01)
    {
        double target_output =
            pid_control(error, pre_error, integral, kp, ki, kd, dt, max_speed);
        double error_output = target_output - current_speed;
        integral += error * dt;
        output = pid_control(error_output, pre_error, integral, kp, ki, kd, dt, 1.0);
        current_speed += output * dt;
        if (current_speed > max_speed) current_speed = max_speed;
        if (current_speed < 0.0) current_speed = 0.0;
        current_pos += current_speed * dt;
        std::cout << "Current Position: " << current_pos
                  << ", Current Speed: " << current_speed << std::endl;
        pre_error = error;
        error = target_pos - current_pos;
    }
}

int main()
{
    double max_speed = 10.0;         // 最大速度
    double dt = 0.1;                 // 控制周期
    double current_pos = 0.0;        // 当前位置
    double target_pos = 100.0;       // 目标位置
    double current_speed = 0.0;      // 当前速度
    double target_speed = max_speed; // 目标速度
    double kp = 0.5;                 // 比例系数
    double ki = 0.0;                 // 积分系数
    double kd = 0.1;                 // 微分系数

    velocity_control(max_speed, dt, current_pos, target_pos, current_speed, target_speed,
                     kp, ki, kd);

    return 0;
}
