#include <bits/stdc++.h>

using namespace std;

void recur(int k,int win,int lose,string out) {
    if (win == k || lose == k) {
        cout << out << endl;
        return;
    }
    recur(k,win+1,lose,out+"W ");
    recur(k,win,lose+1,out+"L ");
}

int main()
{
    int k,win,lose;
    cin >> k >> win >> lose;
    string out = "";
    recur(k,win,lose,out);
    return 0;
}
