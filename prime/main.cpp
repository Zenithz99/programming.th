#include <bits/stdc++.h>
using namespace std;
#define limitnum 8000000
typedef long long ll;

int main()
{
    ll want;
    cin >> want;
    vector<bool> was_div(limitnum,false);
    ll cnt = 0;
    ll i=2;
    while (i < limitnum) {
        if (!was_div[i]) {
            cnt++;
            if (cnt == want) {
                cout << i;
                return 0;
            }
            for (ll j=i+i;j<limitnum;j+=i) was_div[j] = true;
        }
        if (i == 2) i++;
        else i += 2;
    }
}
