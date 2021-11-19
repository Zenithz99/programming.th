#include <iostream>
#include <vector>
using namespace std;
bool boyer(string input,string sub) {

}
int main()
{
    ll n,m;
    cin >> n >> m;
    vector<string> catcode;
    for (ll i=0;i<n;i++) {
        string input;
        cin >> input;
        catcode.push_back(input);
    }
    ll N;
    cin >> N;
    for (ll i=0;i<N;i++) {
        string input;
        ll l;
        cin >> l >> input;
        int flag = 1;
        for (ll j=0;j<n;j++) {
            if (boyer(input,catcode[j])) {
                flag = 0;
                cout << j+1 << " ";
            }
        }
        if (flag == 1) cout << "OK";
        cout << endl;
    }
    return 0;
}
