#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
int main()
{
    int n;
    cin >> n;
    vector<vector<pii>> adj(n+1);
    vector<int> dist(n+1,INT_MIN);
    vector<bool> visit(n+1,false);
    for (int i=0;i<n-1;i++) {
        int x,y,w;
        cin >> x >> y >> w;
        adj[x].push_back(make_pair(y,w));
        adj[y].push_back(make_pair(x,w));
    }
    auto cmp = [](pii a,pii b) {
        return a.second > b.second;
    };
    priority_queue<pii,vector<pii>,decltype(cmp)> q(cmp);
    q.push(make_pair(1,0));
    dist[1] = 0;
    int maxx = INT_MIN;
    while (!q.empty()) {
        int u = q.top().first;
        q.pop();
        visit[u] = true;
        for (auto i:adj[u]) {
            int v = i.first;
            int w = i.second;
            if (!visit[v] && dist[u] + w > dist[v]) {
                dist[v] = dist[u] + w;
                q.push(i);
            }
        }
        if (maxx < dist[u]) maxx =dist[u];
    }
    cout << maxx;
    return 0;
}
