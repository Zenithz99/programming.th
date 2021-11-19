#include <bits/stdc++.h>

using namespace std;

auto cmp1 = [](int a,int b) {
    return a > b;
};

auto cmp2 = [](int a,int b) {
    return a < b;
};

int main()
{
    int n;
    cin >> n;
    priority_queue<int,vector<int>,decltype(cmp1)> h(cmp1);
    priority_queue<int,vector<int>,decltype(cmp2)> s(cmp2);
    priority_queue<int,vector<int>,decltype(cmp2)> t(cmp2);
    for (int i=0;i<n;i++) {
        int x;
        cin >> x;
        h.push(x);
    }
    for (int i=0;i<n;i++) {
        int x;
        cin >> x;
        s.push(x);
    }
    for (int i=0;i<n;i++) {
        int h_top = h.top();
        int s_top = s.top();
        h.pop();
        s.pop();
        t.push(h_top + s_top);
    }
    int ans = 0,p_diff = t.top();
    t.pop();
    while (t.size()) {
        int diff = t.top();
        t.pop();
        ans += p_diff - diff;
        p_diff = diff;
    }
    cout << ans;
    return 0;
}
