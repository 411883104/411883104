/*
 * @Author       : Outsider
 * @Date         : 2023-03-03 10:20:16
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-04 09:53:34
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\Graph\P5318.cc
 */
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

pair<int, int> arc[1005];
struct Edge
{
    int idx;
    Edge* next;
    Edge(int x) : idx(x), next(nullptr) {}
};

struct Node
{
    int idx;
    Edge* edge;
    Node() : edge(nullptr) {}
};
Node ns[1005];

bool c1[1005];
bool c2[1005];
void dfs(int s)
{
    c1[s] = true;
    cout << s << " ";
    auto e = ns[s].edge;
    while (e)
    {
        if (!c1[e->idx])
        {
            c1[e->idx] = true;
            dfs(e->idx);
        }
        e = e->next;
    }
}

void bfs()
{
    queue<Node> q;
    q.push(ns[1]);
    c2[1] = true;
    while (!q.empty())
    {
        auto now = q.front();
        cout << now.idx << " ";
        auto e = now.edge;
        while (e)
        {
            if (!c2[e->idx])
            {
                q.push(ns[e->idx]);
                c2[e->idx] = true;
            }
            e = e->next;
        }
        q.pop();
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> arc[i].first >> arc[i].second;
    }
    sort(arc, arc + m, [](pair<int, int> a, pair<int, int> b) -> bool {
        if (a.first < b.first)
        {
            return true;
        }
        else if (a.first > b.first)
        {
            return false;
        }
        else
        {
            return a.second > b.second;
        }
    });

    for (int i = 1; i <= n; i++)
    {
        ns[i].idx = i;
    }

    for (int i = 0; i < m; i++)
    {
        auto n = new Edge(arc[i].second);
        n->next = ns[arc[i].first].edge;
        ns[arc[i].first].edge = n;
    }

    dfs(1);
    cout << endl;
    bfs();
    cout << endl;

    return 0;
}