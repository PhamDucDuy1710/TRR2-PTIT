#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define file(name) freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);

typedef pair<int,int> ii;

int n, s, t;
int a[105][105];
vector<int> parent(105,-1);
vector<ii> ke[105];

void nhap() {
    cin >> n >> s >> t;
    FOR(i,1,n) {
        FOR(j,1,n) {
            cin >> a[i][j];
            if(a[i][j] != 0 && a[i][j] != 10000) {
                ke[i].pb({j,a[i][j]});
            }
        }
    }
}

void Dijkstra() {
    vector<int> d(n+1,1e9);
    d[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0,s});
    while(!q.empty()) {
        ii p = q.top(); q.pop();
        int u = p.second, dis = p.first;
        if(dis > d[u]) continue;
        dis = d[u];
        for(ii it : ke[u]) {
            int v = it.first;
            int w = it.second;
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                parent[v] = u;
                q.push({d[v],v});
            }
        }
    }
    if(d[t] == 1e9) cout << 0 << "\n";
    else {
        cout << d[t] << "\n";
        vector<int> res;
        while(t != -1) {
            res.pb(t);
            t = parent[t];
        }
        reverse(res.begin(),res.end());
        for(auto x : res) cout << x << " ";
    }
}

void solve() {
    nhap();
    Dijkstra();
}


int main(){
    file("DN");

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}