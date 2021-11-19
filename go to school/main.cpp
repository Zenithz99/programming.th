#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int k;
    cin >> k;
    int maps[n+1][m+1];
    memset(maps,0,sizeof(maps[0][0]) * (n+1) * (m+1));
    for (int i=0;i<k;i++) {
        int x,y;
        cin >> x >> y;
        maps[x][y] = -1;
    }
    maps[1][0] = 1;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (maps[i][j] == -1) maps[i][j] = 0;
            else maps[i][j] = maps[i-1][j] + maps[i][j-1];
        }
    }
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=m;j++) {
            cout << maps[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
