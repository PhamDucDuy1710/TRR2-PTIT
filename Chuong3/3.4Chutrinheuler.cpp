#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
typedef pair<int,int> ii ;
typedef pair<int,pair<int,int>> iii;

struct canh {
    int x, y, w;
};
int dc[105], dt[105];
int t, n, u, cnt = 0, k;
bool used[105];
set<int> ke[105];
int HC[105];
int a[105][105];
bool vs[105];

void dfs(int u) {
    vs[u] = 1;
    k++;
    FOR(v,1,n) {
        if(!vs[v] && (a[u][v] || a[v][u])) {
            dfs(v);
        }
    }
}

bool lt() {
    memset(vs,false,sizeof(vs));
    k = 0;
    dfs(1);
    return k == n;
}

int kt() {
    if(!lt()) return 0;
    int st = 0, en = 0;
    FOR(i,1,n) {
        int in = 0, out = 0;
        FOR(j,1,n) {
            out += a[i][j];
            in += a[j][i];
        }
        if(out - in == 1) st++;
        else if(in - out == 1) en++;
        else if(out != in) return 0;
    } 
    if(st == 0 && en == 0) return 1;
    if(st == 1 && en == 1) return 2;
    return 0;
}

void euler(int u) {
    stack<int> st;
    vector<int> EC;
    st.push(u);
    while(!st.empty()) {
        int x = st.top();
        if(ke[x].size() != 0) {
            int y = *ke[x].begin();
            st.push(y);
            ke[x].erase(y);
        }
        else {
            st.pop();
            EC.pb(x);
        }
    }
    reverse(EC.begin(), EC.end());
    for(auto x : EC) cout << x << " ";
}

void solve() {
    cin >> t >> n;
    if(t == 1) {
        FOR(i,1,n) {
            FOR(j,1,n) {
                cin >> a[i][j];
            }
        }
        cout << kt();
    }
    else {
        int u; 
        cin >> u;
        FOR(i,1,n) {
            FOR(j,1,n) {
                cin >> a[i][j];
                if(a[i][j]) ke[i].insert(j);
            }
        }
        euler(u);
    }
}

int main(){
    freopen("CT.INP","r",stdin);
    freopen("CT.OUT","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}