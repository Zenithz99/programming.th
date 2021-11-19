#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<char> lists(n);
    vector<bool> mark(n,false);
    for (int i=0;i<n;i++) cin >> lists[i];
    int skip = 1,cnt = 0;
    while (lists.size() > 1) {
        int flag = 1;
        int i=0;
        while (i<lists.size()) {
            if (lists[i] == lists[i+skip+1]) {
                lists.erase(lists.begin()+i,lists.begin()+i+skip+1);
                cnt++;
                flag = 0;
            }
        }

        /*
        for (int i=0;i<lists.size()-skip-1;i++) {
            if (lists[i] == lists[i+skip+1]) {
                cout << i  << " " << i + skip + 1 << " : ";
                lists.erase(lists.begin()+i,lists.begin()+i+skip+1);
                cnt++;
                flag = 0;
            }
        }*/
        for (int i=0;i<lists.size();i++) cout << lists[i] << " ";
        cout << endl;
        if (flag == 0) {
            skip = 0;
        }
        else skip++;
    }
    cout << cnt;
    return 0;
}
