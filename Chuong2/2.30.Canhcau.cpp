#include<bits/stdc++.h>
using namespace std ;
int a[105][105], b[105][105],  lt[10005], n ; 
void BFS(int u) {
	queue<int> q ; 
	q.push(u) ; 
	lt[u] = 1 ;
	while(!q.empty()) {
		int v = q.front() ; 
		q.pop() ; 
		for(int i = 1 ;i <= n ;i++) {
			if(lt[i] == 0 && a[v][i] == 1) {
				q.push(i) ; 
				lt[i] = 1 ;
			}
		}
	}
}
int tpltBfs() { 
	int k = 0 ; 
	for(int u = 1 ; u <= n ;u++) {
		lt[u] = 0 ; 
	}
	for(int u = 1; u <= n ;u++) {
		if(lt[u] == 0) {
			k++ ; 
			BFS(u) ; 
		}
	}
	return k ; 
}
void solve() {
	cin >> n ; 
	vector<pair<int,int>> edges, res ;  
	for(int i = 1 ;i <= n ;i++) {
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j] ; 
			b[i][j] = a[i][j] ; 
		}
	}
	for(int i = 1 ;i <= n ;i++) {
		for(int j = 1; j <= n; j++) {
			if(b[i][j] == 1) {
				edges.push_back({i,j}) ; 
				b[j][i] = 0 ;
			}
		}
	}
	int k = tpltBfs() ; 
	for(auto x : edges) {
		int u = x.first ; 
		int v = x.second ; 
		a[u][v] = 0 ; // Bỏ cạnh 
		a[v][u] = 0 ; 
		int I = tpltBfs() ; 
		if(I > k) { // Ghi nhận là cạnh cầu 
			res.push_back({u,v}) ; 
		}
		a[u][v] = 1 ; // Trả lại để tiếp tục thử xóa cạnh khác
		a[v][u] = 1 ; 
	}
	cout << res.size() << "\n" ; 
	for(auto x : res ) {
		cout << x.first << " " << x.second << "\n" ; 
	}
} 
int main() {
	ios::sync_with_stdio(false) ; 
	cin.tie(nullptr) ; 
	freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
	int t = 1 ; 
	// cin >> t ;
	while(t--) {
		solve() ; 
	}
}