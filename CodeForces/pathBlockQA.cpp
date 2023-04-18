#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

vector<vector<int>> g;

int bfs(int x1, int x2, int y1, int y2)
{
    int n = g.size();
    int m = g[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    q.push(make_pair(x1, y1));
    visited[x1][y1] = true;
    dist[x1][y1] = 0;

    while (!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();
        int x = node.first;
        int y = node.second;

        if (x == x2 && y == y2)
        {
            return dist[x][y];
        }

        // explore neighbors
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == 0 && !visited[nx][ny])
            {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }

    // if we reach here, there's no path from (x1,y1) to (x2,y2)
    // count the number of obstacles needed to block the path
    int obstacles = 0;
    int x = x2;
    int y = y2;
   while (x != x1 || y != y1)
{
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool blocked = true;
    int temp = -1;
    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == dist[x][y] - 1 && g[nx][ny] == 1)
        {
            x = nx;
            y = ny;
            blocked = false;
            temp = k;
            break;
        }
    }
    if (blocked)
    {
        obstacles++;
        g[x][y] = 1;
        int newO = bfs(x1 - 1, x2 - 1, y1 - 1, y2 - 1);
        if (newO < minO)
        {
            minO = newO;
        }
    }
    else
    {
        x = x + dx[temp];
        y = y + dy[temp];
    }
}

    return obstacles;
}
int main()
{
    int t;
    int n, m;

    cin>>t;
    while(t--)
    {
        int x1, x2, y1, y2;
        cin>>n>>m;
        cin>>x1>>y1>>x2>>y2;
        vector<vector<int>> v(n, vector<int>(m, 0));
        g=v;
        // two point
        g[x1-1][y1-1]=0;
        g[x2-1][y2-1]=0;
    
    int minO = bfs(x1 - 1, x2 - 1,y1 - 1,  y2 - 1);
    cout << minO << endl;
    }
    return 0;

}
