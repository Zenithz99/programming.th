#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>> n >>m;
    char maps[n][m];
    vector<int> top_obs(m,n);
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> maps[i][j];
            if (maps[i][j] == 'O') top_obs[j] = min(top_obs[j],i);
        }
    }
    for (int i=0;i<m;i++) {
        int curr;
        cin >> curr;
        int top = top_obs[i];
        while (curr != 0 && top-1 >= 0) {
            top--;
            maps[top][i] = '#';
            curr--;
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) cout << maps[i][j];
        cout << endl;
    }
    return 0;
}
