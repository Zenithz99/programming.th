#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n,0);
    for (ll i=0;i<m;i++) {
        ll s,e;
        cin >> s >> e;
        s--;
        e--;
        for (ll j=s;j<=e;j++) {
            a[j] = (a[j]+1) % 3;
        }
    }
    char req;
    cin >> req;
    ll trans;
    if (req == 'R') trans = 0;
    else if (req == 'G') trans = 1;
    else trans = 2;
    ll counts = 0;
    for (ll i=0;i<n;i++) {
        if (a[i] == trans) continue;
        else if (a[i] < trans) {
            counts += trans - a[i];
        } else {
            counts += 3 - a[i] + trans;
        }
    }
    cout << counts;
    return 0;
}
