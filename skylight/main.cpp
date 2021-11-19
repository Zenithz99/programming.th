#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ll n,m,l,k,c;
    cin >> n >> m >> l >> k >> c;
    ll sum = 0;
    for (ll i=0;i<n;i++) {
        for (ll j=0;j<m;j++) {
            ll x;
            cin >> x;
            sum += x;
        }
    }
    ll out = (sum + l*k*c) / c;
    if ((sum + l*k*c)%c != 0) out++;
    cout << out;
    return 0;
}
