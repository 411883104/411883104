#include <iostream>
#include <queue>
using namespace std;

const int c = 1005;
int n, k;
char mm[c][c];
struct status
{
    int x, y, w, s;
    status(int x, int y, int w) : x(x), y(y), w(w), s(s) {}
};
queue<status> q;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int x, int y)
{
    q.emplace(x, y, 5, 0);
    while (!q.empty())
    {
        auto now = q.front();
        for (int i = 0; i < 4; i++)
        {
            int xx = now.x + dx[i];
            int yy = now.y + dy[i];
            if(xx<n&&xx>=0&&yy<n&&yy>=0){
                
            }
        }
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mm[i][j];
        }
    }
}