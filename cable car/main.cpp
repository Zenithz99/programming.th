#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

void DFS(ll from,ll to,vector<vector<pll>> adj,vector<bool> &visit,ll mins,vector<ll> &path) {
    if (from == to) {
        path.push_back(mins);
        return;
    }
    visit[from] = true;
    for (auto next : adj[from]) {
         ll v = next.first;
         if (!visit[v]) {
            visit[v] = true;
            mins = min(mins,next.second);
            DFS(v,to,adj,visit,mins,path);
            visit[v] = false;
         }
    }
}
int main()
{
    ll n,m;
    cin >> n >> m;
    vector<vector<pll>> adj(n+1);
    for (ll i=0;i<m;i++) {
        int x,y,w;
        cin >> x >> y >> w;
        adj[x].push_back(make_pair(y,w));
        adj[y].push_back(make_pair(x,w));
    }
    ll from,to,people;
    cin >> from >> to >> people;
    vector<bool> visit(n+1,false);
    vector<ll> path_value;
    visit[from] = true;
    DFS(from,to,adj,visit,INT_MAX,path_value);
    ll min_per_round = INT_MIN;
    for (ll i=0;i<path_value.size();i++) {
        min_per_round = max(min_per_round,path_value[i]);
    }
    ll guide = ceil(people/min_per_round);
    cout << ceil((people+guide)/min_per_round);
    return 0;
}
