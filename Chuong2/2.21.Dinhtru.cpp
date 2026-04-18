#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

int n, a[105][105], lt[100005] ;

void dfs(int u) {
    lt[u] = 1 ;
    for(int i = 1 ; i <= n ; i++) {
        if(!lt[i] && a[u][i] == 1) {
            dfs(i) ;
        }
    }
}
void bfs(int u) {
    queue<int> q ;
    q.push(u) ; 
    lt[u] = 1 ;
    while(!q.empty()) {
        int v = q.front(); q.pop() ;
        for(int i = 1 ; i <= n ;i++) {
            if(!lt[i] && a[v][i] == 1) {
                q.push(i) ; 
                lt[i] = 1 ;
            }
        }
    }
}

int stplt() {
    int k = 0 ; 
    for(int i =1 ; i <= n ;i++) lt[i] = 0 ; 

    for(int i = 1 ;i <= n ;i++) {
        if(!lt[i]) {
            k++ ; 
            dfs(i) ; 
        }
    }
    return k ;
}

void solve() {
    cin >> n ;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1; j <= n ;j++) {
            cin >> a[i][j] ; 
        }
    }
    int k = stplt() ; 
    vector<int> dt ; 
    for(int u = 1 ;u <= n ;u++) {
        vector<int> ke ; 
        for(int v = 1 ; v <= n ; v++) {
            if(a[u][v] == 1) {
                ke.pb(v) ; 
                a[u][v] = 0 ;
                a[v][u] = 0 ;
            }
        }
        for(int i = 1 ; i <= n ;i++) {
            lt[i] = 0 ;
        }
        lt[u] = 1 ;
        int I = 0 ; 
        for(int i = 1 ; i <= n ;i++) {
            if(!lt[i]) {
                I++ ; 
                dfs(i) ; 
            }
        }
        if(I > k) dt.pb(u) ; 
        for(auto x : ke) {
            a[u][x] = 1 ;
            a[x][u] = 1 ;
        }
    }
    cout << dt.size() << "\n" ; 
    for(auto x : dt) cout << x << " " ;
    cout << "\n" ; 
}

int main(){
    freopen("TK.INP","r",stdin);
    freopen("TK.OUT","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve() ; 

    return 0;
}