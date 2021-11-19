#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

vector<int> h = {0,1,0,-1} , k = {1,0,-1,0};

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<char>> maps(n);
    vector<bool> tmp (m,false);
    vector<vector<bool>> visit(n,tmp);
    vector<int> tmp2 (m,INT_MAX);
    vector<vector<int>> dist(n,tmp2);
    queue<pii> target;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            char x;
            cin >> x;
            if (x == 'X') {
                target.push(make_pair(i,j));
                dist[i][j] = 0;
            }

            maps[i].push_back(x);
        }
    }
    int counts = 0,sum=0;

    while (!target.empty()) {
        int x=target.front().first, y=target.front().second;
        target.pop();
        if (!visit[x][y]) {
            visit[x][y] = true;
            if (maps[x][y] == 'A') {
                counts++;
                sum += dist[x][y] * 2;
            }
            for (int i=0;i<4;i++) {
                int u = x + h[i];
                int v = y + k[i];
                if (u >= 0 && v >= 0 && u < n && v < m && !visit[u][v] && maps[u][v] != 'W' && dist[x][y] + 1 < dist[u][v]) {
                    dist[u][v] = dist[x][y] + 1;
                    target.push(make_pair(u,v));
                }
            }
        }
    }
    cout << counts << " " << sum;
    return 0;
}
