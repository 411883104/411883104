/*
 * @Author       : Outsider
 * @Date         : 2023-03-19 15:44:36
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-19 15:44:43
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\other\Rotbot.cc
 */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Task {
    int x, y; // 坐标
    int type; // 0 表示生产任务，1 表示消费任务
};

struct Robot {
    int x, y; // 坐标
    int assigned_task_index; // 分配的任务编号，-1 表示未分配任务
};

// 计算两点之间的欧几里得距离
double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

// 找到未分配的最近的任务
int find_nearest_unassigned_task(Task* tasks, int num_tasks, Robot* robot) {
    int nearest_task_index = -1;
    double min_distance = INFINITY;
    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].type == robot->assigned_task_index || robot->assigned_task_index != -1) {
            continue; // 跳过已分配任务和消费任务
        }
        double d = distance(tasks[i].x, tasks[i].y, robot->x, robot->y);
        if (d < min_distance) {
            min_distance = d;
            nearest_task_index = i;
        }
    }
    return nearest_task_index;
}

// 多机器人任务分配算法
void assign_tasks(Task* tasks, int num_tasks, Robot* robots, int num_robots) {
    for (int i = 0; i < num_robots; i++) {
        int task_index = find_nearest_unassigned_task(tasks, num_tasks, &robots[i]);
        robots[i].assigned_task_index = task_index;
    }
}

int main() {
    int num_tasks, num_robots, source_x, source_y, sink_x, sink_y;
    cin >> num_tasks >> num_robots >> source_x >> source_y >> sink_x >> sink_y;

    Task tasks[num_tasks];
    for (int i = 0; i < num_tasks; i++) {
        cin >> tasks[i].x >> tasks[i].y >> tasks[i].type;
    }

    Robot robots[num_robots];
    for (int i = 0; i < num_robots; i++) {
        cin >> robots[i].x >> robots[i].y;
        robots[i].assigned_task_index = -1;
    }

    assign_tasks(tasks, num_tasks, robots, num_robots);

    for (int i = 0; i < num_robots; i++) {
        cout << "Robot " << i << " assigned task: " << robots[i].assigned_task_index << endl;
    }

    return 0;
}
