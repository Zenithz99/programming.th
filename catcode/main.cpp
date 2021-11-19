#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> createfunc(string input) {
    vector<ll> func(input.size(),0);
    ll i=1,j=0;
    while (i < input.size()) {
        if (input[i] == input[j]) {
            func[i] = j + 1;
            i++;
            j++;
        } else if (j > 0) {
            j = func[j-1];
        } else {
            func[i] = 0;
            i++;
        }
    }
    return func;
}
bool KMP(string input,string sub,vector<ll> func) {
    ll i=0,j=0;
    while (i < input.size()) {
        if (input[i] == sub[j]) {
            i++;
            j++;
            if (j == sub.size()) return true;
        } else {
            if (j > 0) j = func[j-1];
            else i++;
        }
    }
    return false;
}
int main()
{
    ll n,m;
    cin >> n >> m;
    vector<string> catcode;
    vector<vector<ll>> func;
    for (ll i=0;i<n;i++) {
        string input;
        cin >> input;
        catcode.push_back(input);
        func.push_back(createfunc(input));
    }
    ll N;
    cin >> N;
    for (ll i=0;i<N;i++) {
        string input;
        ll l;
        cin >> l >> input;
        int flag = 1;
        for (ll j=0;j<n;j++) {
            if (KMP(input,catcode[j],func[j])) {
                flag = 0;
                cout << j+1 << " ";
            }
        }
        if (flag == 1) cout << "OK";
        cout << endl;
    }
    return 0;
}
