#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string input;
    cin >> input;
    int cnt = 0,start = 0;
    for (int i=1;i<n;i++) {
        if (n % i != 0) continue;
        int flag = 1;
        for (int j=0;j<n;j++) {
            if (input[(i+j) % n] != input[start+j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cnt = i;
            break;
        }
    }
    if (cnt) cout << cnt;
    else cout << n;
    return 0;
}
