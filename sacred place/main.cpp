#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <limits.h>
using namespace std;
typedef pair<int,int> pii;

int MST(vector<vector<pii>> adj,int n) {
    // pii q = <w,node>
    // pii adj = <node,w>
    priority_queue<pii> q;
    vector<bool> visit(n,false);
    vector<int> parent(n,-1);
    vector<int> key(n,INT_MIN);
    q.push(make_pair(0,1));
    visit[1] = true;
    key[1] = 0;
    while (!q.empty()) {
        int top = q.top().second;
        q.pop();
        visit[top] = true;
        for (auto next : adj[top]) {
            if (!visit[next.first] && key[next.first] < next.second) {
                key[next.first] = next.second;
                q.push(make_pair(next.second,next.first));
                parent[next.first] = top;
            }
        }
    }
    int sum=0;
    for (int i=2;i<n;i++) {
        sum = sum + key[i] - 1;
    }
    return sum;
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<pii>> adj(n+1);
    for (int i=0;i<m;i++) {
        int x,y,w;
        cin >> x >> y >> w;
        adj[x].push_back(make_pair(y,w));
        adj[y].push_back(make_pair(x,w));
    }
    int result = MST(adj,n+1);
    cout << result;
    return 0;
}
