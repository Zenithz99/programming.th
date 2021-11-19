#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ll n,k;
    cin >> n >> k;
    vector<ll> q(n);
    for (ll i=0;i<n;i++) cin >> q[i];
    sort(q.begin(),q.end(),greater<ll> ());
    cout << q[k-1];
    return 0;
}
