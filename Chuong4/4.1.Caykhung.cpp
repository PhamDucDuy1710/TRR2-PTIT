#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

int n, u;
int a[105][105] ; 
bool vs[10005] ; 
set<int> ke[10005] ;
vector<vector<int>> res ;

void dfs(int u) {
	vs[u] = true ;
	for(auto v : ke[u]) {
		if(!vs[v]) {
			res.pb({u,v}) ; 
			dfs(v) ;
		}
	}
}

void bfs(int u) {
	memset(vs,false,sizeof(vs)) ;
	queue<int> q;
	q.push(u) ; 
	vs[u] = true ;
	while(!q.empty()) {
		int v = q.front(); q.pop() ; 
		for(auto i : ke[v]) {
			if(!vs[i]) {
				res.pb({v,i}) ;
				vs[i] = true ;
				q.push(i) ;
			}
		}
	}
}

int main(){
    freopen("CK.INP","r",stdin);
    freopen("CK.OUT","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t >> n >> u ; 
    for(int i = 1 ; i <= n ;i++) {
    	for(int j = 1 ; j <= n ;j++) {
    		cin >> a[i][j] ;
    		if(a[i][j]) {
    			ke[i].insert(j) ;
     		}
    	}
    }
    if(t == 1) dfs(u) ; 
    else bfs(u) ; 
    if(res.size() == n - 1) {
    	cout << res.size() << "\n" ; 
    	for(vector<int> v : res) cout << min(v[0], v[1]) << " " << max(v[0], v[1]) << "\n" ;
    } else {
    	cout << 0 << "\n" ;
    }

    return 0;
}