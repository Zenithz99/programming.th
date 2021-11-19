#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main()
{
    ll n,w;
    cin >> n >> w;
    vector<ll> house;
    for (int i=0;i<n;i++) {
        ll v;
        cin >> v;
        house.push_back(v);
    }
    ll max_sofar = 0,min_barrier = 0,curr_barrier = 0,max_here = 0;
    for (int i=0;i<n;i++) {
        //try add barrier
        max_here = max_here + house[i];
        curr_barrier++;
        //in case full
        if (curr_barrier > w) {
            // choose front
            if (house[i] >= house[i-w]) {
                curr_barrier--;
                max_here -= house[i-w];
            // choose back
            } else {
                max_here = house[i];
                curr_barrier = 1;
            }
        }
        if (max_sofar < max_here) {
            max_sofar = max_here;
            min_barrier = curr_barrier;
        } else if (max_sofar == max_here) {
            if (min_barrier > curr_barrier) min_barrier = curr_barrier;
        }
        if (max_here < 0) {
            max_here = 0;
            curr_barrier = 0;
        }
    }
    cout << max_sofar << endl << min_barrier;
    return 0;
}
