#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

int n, a[105][105], b[105][105], lt[10005]; 

void dfs(int u) {
	lt[u] = 1 ;
	for(int v = 1 ;v <= n ; v++) {
		if(!lt[v] && a[u][v] == 1) {
			dfs(v) ; 
		}
	}
}

void bfs(int u) {
	queue<int> q ; 
	q.push(u) ; 
	lt[u] = 1 ;
	while(!q.empty()) {
		int v = q.front() ; q.pop() ; 
		for(int i = 1 ; i <= n ;i++) {
			if(!lt[i] && a[v][i] == 1) {
				q.push(i) ; 
				lt[i] = 1;
			}
		}
	}
}

int stplt() {
	int k = 0 ;
	for(int i = 1 ; i <= n ;i++) lt[i] = 0 ; 

	for(int i = 1 ; i <= n ; i++) {
		if(!lt[i]) {
			k++ ; 
			dfs(i) ; 
		}
	}
	return k ;
}

void solve() {
	cin >> n ; 
	for(int i = 1 ; i <= n ;i++) {
		for(int j = 1 ; j <= n ;j++) {
			cin >> a[i][j] ; 
			b[i][j] = a[i][j] ; 
		}
	}

	vector<pair<int,int>> res, cc; 
	for(int i = 1 ; i <= n ;i++) {
		for(int j = 1; j <= n ;j++) {
			if(b[i][j]) {
				res.pb({i,j}) ; 
				b[j][i] = 0 ;
			}
		}
	}
	int k = stplt() ; 
	for(auto x : res) {
		int u = x.first ; 
		int v = x.second ; 
		a[u][v] = 0 ; 
		a[v][u] = 0 ; 
		int I = stplt() ;
		if(I > k) {
			cc.pb({u,v}) ; 
		}
		a[u][v] = 1 ;
		a[v][u] = 1 ;
	}
	cout << cc.size() << "\n" ; 
	for(auto x : cc) {
		cout << x.first << " " << x.second << "\n" ;
	}
}


int main(){
    freopen("TK.INP","r",stdin);
    freopen("TK.OUT","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve() ;
    

    return 0;
}