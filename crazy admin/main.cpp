#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> lists;
    int maxx = INT_MIN;
    for (int i=0;i<m;i++) {
        int x;
        cin >> x;
        lists.push_back(x);
        maxx = max(maxx,x);
    }
    int f=0,r=maxx;
    int out=maxx;
    while (f <= r) {
        int mid = (f+r) / 2;
        int curr_b = 1,curr = 0, max_elem = 0;
        for (int i=0;i<m;i++) {
            if (curr + lists[i] > mid) {
                curr = 0;
                curr_b++;
                if (curr_b > n) break;
            }
            curr += lists[i];
            max_elem = max(max_elem,lists[i]);
        }
        if (curr_b > n) {
            f = mid + 1;
        } else  {
            out = max_elem;
            r = mid - 1;
        }
    }
    cout << out;
    return 0;
}
