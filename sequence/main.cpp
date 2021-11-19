#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll> dp(1000010,-1);

ll dpm(vector<ll> a,ll x) {
    if (x < 4) return a[x];
    if (dp[x] != -1) return dp[x];
    else {
        if (dp[x-1] == -1) dp[x-1] = dpm(a,x-1);
        if (dp[x-2] == -1) dp[x-2] = dpm(a,x-2);
        if (dp[x-3] == -1) dp[x-3] = dpm(a,x-3);
        if (dp[x-4] == -1) dp[x-4] = dpm(a,x-4);
        dp[x] =( a[4]*dp[x-1] + a[5]*dp[x-2] + a[6]*dp[x-3] + a[7]*dp[x-4] ) % 2553;
        return dp[x];
    }
}
int main()
{
    int n;
    vector<ll> a(8);
    for (ll i=0;i<8;i++) cin >> a[i];
    cin >> n;
    for (ll i=0;i<n;i++) {
        ll x;
        cin >> x;
        cout << dpm(a,x-1)<< endl;
    }
    return 0;
}
