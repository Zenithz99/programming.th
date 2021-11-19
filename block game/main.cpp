#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> h = {1,0,-1,0} , k = {0,1,0,-1};

void recur(vector<vector<char>> &maps,int x,int y,int &score,char check) {
    for (int i=0;i<4;i++) {
        int nx = x + h[i];
        int ny = y + k[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && maps[nx][ny] == check) {
            score += 5;
            maps[nx][ny] = '-';
            recur(maps,nx,ny,score,check);
        }
    }
}

void updateg(vector<vector<char>> &maps) {
    for (int i=0;i < n-1;i++) {
        for (int j=0;j < m;j++) {
            if (maps[i][j] != '#' && maps[i][j] != '-' && maps[i+1][j] == '-') {
                int x = i , y = j;
                while (x < n-1 && maps[x+1][y] == '-') {
                    swap(maps[x][y],maps[x+1][y]);
                    x++;
                }
            }
        }

    }
}

bool anybeside(vector<vector<char>> maps,int &x,int &y) {
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (maps[i][j] != '#' && maps[i][j] != '-') {
                for (int d=0;d<4;d++) {
                    int nx = i + h[d];
                    int ny = j + k[d];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && maps[i][j] == maps[nx][ny]) {
                        x = nx;
                        y = ny;
                        return true;
                    }
                }
            }

        }
    }
    return false;
}

void print(vector<vector<char>> maps) {
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) cout << maps[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    cin >> n >> m;
    vector<vector<char>> maps(n);
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            char c;
            cin >> c;
            maps[i].push_back(c);
        }
    }
    int score = 0;
    int t;
    cin >> t;
    for (int i=0;i<t;i++) {
        int x,y;
        char direc;
        cin >> x >> y >> direc;
        if (direc == 'L') {
            if (maps[x][y-1] != '-' || maps[x][y] == '#' || maps[x][y] == '-') score -= 5;
            else {
                swap(maps[x][y],maps[x][y-1]);
                updateg(maps);
                while (anybeside(maps,x,y)) {
                    recur(maps,x,y,score,maps[x][y]);
                    updateg(maps);
                }
            }
        }
        if (direc == 'R') {
            if (maps[x][y+1] != '-' || maps[x][y] == '#' || maps[x][y] == '-') score -= 5;
            else {
                swap(maps[x][y],maps[x][y+1]);
                updateg(maps);
                while (anybeside(maps,x,y)) {
                    recur(maps,x,y,score,maps[x][y]);
                    updateg(maps);
                }
            }
        }
    }
    cout << score << endl;
    print(maps);
    return 0;
}
/*
4 5
# A - - #
# # - B #
# A B # #
# # # # #
2
1 3 L
0 1 R
*/
