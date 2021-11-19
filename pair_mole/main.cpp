#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> lists(n+1);
    vector<bool> visit(n+1,false);
    for (int i=1;i<=n;i++) cin >> lists[i];
    int start;
    cin >> start;
    visit[start] = true;
    for (int t=0;t<(n-1)/2;t++) {
        int a,b;
        cin >> a >> b;
        visit[a] = true;
        visit[b] = true;
        int i=1;
        int sum = 0;
        int max_holding_banner = INT_MIN;
        int flag = 1;
        int before;
        int not_select;
        while (i <= n) {
            if (visit[i]) {

            }
            i++;
        }
        cout << sum - max_banner << endl;
    }
    return 0;
}
