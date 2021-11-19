#include <bits/stdc++.h>

using namespace std;

int maps[2010][2010];
bool visit[2010][2010];
int n,m;

typedef pair<int,int> pii;

void BFS(int i,int j) {
    queue<pii> q;
    q.push(make_pair(i,j));
    while(!q.empty()) {
        int tx = q.front().first, ty = q.front().second;
        q.pop();
        for (int h=-1;h<=1;h++) {
            for (int k=-1;k<=1;k++) {
                if (!(h==0 && k==0)) {
                    int nx = tx + h;
                    int ny = ty + k;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && maps[nx][ny] == 1) {
                        visit[nx][ny] = true;
                        q.push(make_pair(nx,ny));
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            scanf("%1d",&maps[i][j]);
            visit[i][j] = false;
        }
    }
    int cnt = 0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (!visit[i][j] && maps[i][j] == 1) {
                cnt++;
                visit[i][j] = true;
                BFS(i,j);
            }
        }
    }
    cout << cnt;
    return 0;
}
