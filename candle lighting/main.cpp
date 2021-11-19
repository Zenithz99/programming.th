#include <bits/stdc++.h>
using namespace std;
vector<int >dx = {1,1,1,0,0,-1,-1,-1}, dy = {1,0,-1,1,-1,1,0,-1};
void DFS(vector<vector<char>> &maps,int i,int j,int n,int m) {
    maps[i][j] = 0;
    for (int l=0;l<8;l++) {
        int newx = i + dx[l];
        int newy = j + dy[l];
        if (newx < n && newx >= 0 && newy < m && newy >= 0 && maps[newx][newy] == '1') DFS(maps,newx,newy,n,m);
    }
}
int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<char>> maps(n);
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            char x;
            cin >> x;
            maps[i].push_back(x);
        }
    }
    int counts = 0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (maps[i][j] == '1') {
                counts++;
                DFS(maps,i,j,n,m);
            }
        }
    }
    cout << counts;
}
