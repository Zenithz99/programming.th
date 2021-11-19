#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> h(3010,0);
    int last = 0;
    for(int i=0;i<n;i++) {
        int x,hi,y;
        cin >> x >> hi >> y;
        for (int j=x;j<y;j++) h[j] = max(h[j],hi);
        last = max(last,y);
    }
    int curr = 0;
    for (int i=0;i<=last;i++) {
        if (h[i+1] != curr) {
            curr = h[i+1];
            cout << i+1 << " " << h[i+1] << " ";
        }
    }

    return 0;
}
