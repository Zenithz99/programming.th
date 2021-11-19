#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    int maps[n][m];
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) cin >> maps[i][j];
    }
    int best = INT_MIN;

    for (int i=0;i<=n-k;i++) {
        for (int j=0;j<=m-k;j++) {
            int sum =0;
            for (int col=0;col<k;col++) {
                for (int row=0;row<=col;row++) {
                    sum += maps[i+col][j+row];
                }
            }
            best = max(best,sum);
        }
    }

    for (int i=0;i<=n-k;i++) {
        for (int j=k-1;j<m;j++) {
            int sum =0;
            for (int col=0;col<k;col++) {
                for (int row=0;row<=col;row++) {
                    sum += maps[i+col][j-row];
                }
            }
            best = max(best,sum);
        }
    }

    cout << best;

    return 0;
}
