#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

bool cal(int x1,int y1,pii item,int r,int d) {
    int x2 = item.first,y2 = item.second;
    double ans = sqrt(pow(x1-x2,2) + pow(y1-y2,2));
    return ans >= d + 2*r;
}

int main()
{
    int t;
    cin >> t;
    for (int T=0;T<t;T++) {
        int n,r,d;
        cin >> n >> r >> d;
        vector<pii> lists;
        int flag = 1;
        for (int i=0;i<n;i++) {
            int x,y;
            cin >> x >> y;
            for (pii item : lists) {
                if (flag == 0) break;
                if (!cal(x,y,item,r,d)) flag = 0;
            }
            lists.push_back(make_pair(x,y));
        }
        if (flag == 1) cout << "Y";
        else cout << "N";
        cout << endl;
    }
    return 0;
}
/*
5
2 1 1 0 0 4 0
2 1 1 0 0 2 0
3 1 2 0 0 -2 2 2 1
3 1 2 0 0 4 1 -4 0
3 1 2 0 0 3 1 -4 0
*/
