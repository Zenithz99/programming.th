#include <bits/stdc++.h>
using namespace std;

int main()
{
    string input;
    cin >> input;
    int n = input.size();
    int dp[n+1][9];
    for (int i=0;i<n;i++) {
        for (int j=0;j<9;j++) {
            dp[i][j] = 1000000;
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=8;j++) dp[i][j] = min(dp[i][j],dp[i-1][j] + 1);
        char c = input[i];
        if (c == 'c') {
            dp[i][1] = min(dp[i][1],1);
            dp[i][5] = min(dp[i][5],dp[i-1][4] + 1);
        }
        if (c == 'o') {
            dp[i][2] = min(dp[i][2],dp[i-1][1] + 1);
        }
        if (c == 'd') {
            dp[i][3] = min(dp[i][3],dp[i-1][2] + 1);
        }
        if (c == 'e') {
            dp[i][4] = min(dp[i][4],dp[i-1][3] + 1);
            dp[i][8] = min(dp[i][8],dp[i-1][7] + 1);
        }
        if (c == 'u') {
            dp[i][6] = min(dp[i][6],dp[i-1][5] + 1);
        }
        if (c == 'b') {
            dp[i][7] = min(dp[i][7],dp[i-1][6] + 1);
        }
    }
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=8;j++) cout << dp[i][j] << " ";
        cout << endl;
    }
    int minn = 10000000,st;
    for (int i=1;i<=n;i++) {
        if (dp[i][8] < minn) {
            minn = dp[i][8];
            st = i;
        }
    }
    if (minn == 1000000) cout << "-1";
    else cout << minn << " " << st;
    return 0;
}
