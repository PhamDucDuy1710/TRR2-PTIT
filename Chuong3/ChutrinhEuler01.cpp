#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<=b;i++)

int a[105][105], n, m;
bool vs[105];
multiset<int> adj[105];

void dfs(int u){
    vs[u] = true;
    for(int v = 1; v <= n; v++){
        if(!vs[v] && a[u][v] > 0) dfs(v);
    }
}

bool lienThong(){
    memset(vs, false, sizeof(vs));
    int st = -1;
    for(int i = 1; i <= n; i++){
        int deg = 0;
        for(int j = 1; j <= n; j++) deg += a[i][j];
        if(deg > 0){
            st = i;
            break;
        }
    }
    if(st == -1) return true; // không có cạnh
    dfs(st);
    for(int i = 1; i <= n; i++){
        int deg = 0;
        for(int j = 1; j <= n; j++) deg += a[i][j];
        if(deg > 0 && !vs[i]) return false;
    }
    return true;
}

int checkEuler(){
    if(m == 0) return 0;          
    if(!lienThong()) return 0;
    int odd = 0;
    for(int i = 1; i <= n; i++){
        int deg = 0;
        for(int j = 1; j <= n; j++) deg += a[i][j];
        if(deg % 2 == 1) odd++;
    }
    if(odd == 0) return 1;
    if(odd == 2) return 2;
    return 0;
}

void euler(int start){
    stack<int> st;
    vector<int> res;
    st.push(start);
    while(!st.empty()){
        int u = st.top();
        if(!adj[u].empty()){
            int v = *adj[u].begin();
            st.push(v);
            adj[u].erase(adj[u].find(v));
            adj[v].erase(adj[v].find(u));
        } else {
            st.pop();
            res.push_back(u);
        }
    }
    reverse(res.begin(), res.end());
    for(size_t i = 0; i < res.size(); i++){
        if(i > 0) cout << ' ';
        cout << res[i];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("CT.INP", "r", stdin) ; 
    freopen("CT.OUT", "w", stdout) ;
    int t;
    cin >> t;
    memset(a, 0, sizeof(a));
    if(t == 1){
        cin >> n >> m;
        FOR(i, 1, m){
            int x, y; cin >> x >> y;
            a[x][y]++; a[y][x]++;
        }
        cout << checkEuler();
    } else {
        int u;
        cin >> n >> m >> u;
        FOR(i, 1, m){
            int x, y; cin >> x >> y;
            adj[x].insert(y);
            adj[y].insert(x);
        }
        euler(u);
    }
    return 0;
}