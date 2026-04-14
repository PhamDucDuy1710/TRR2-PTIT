#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> res ; 
int a[105][105], n, m, u, HC[105];
set<int> adj[105];
bool used[105];
int cnt = 0;
void nhap() {
	cin >> n >> m >> u ; 
	for(int i = 1 ; i <= m ; i++) {
		int x, y ; 
		cin >> x >> y ; 
		adj[x].insert(y) ;
		adj[y].insert(x) ;
	}
	memset(used,false,sizeof(used));
}
void Hamilton_Cycle(int pos, int u){
	used[u] = true;
	HC[pos] = u;
	if(pos == n){
		if(adj[u].count(HC[1])){
			vector<int> tmp ;
			for(int i = 1; i <= n; i++) tmp.push_back(HC[i]) ; 
			tmp.push_back(HC[1]) ;
			res.push_back(tmp) ;
			cnt++;
		}
		used[u] = false;
		return;
	}
	for(int v : adj[u]){
		if(!used[v]){
			Hamilton_Cycle(pos + 1, v);
		}
	}
	used[u] = false;
}

int main(){
	freopen("CT.INP","r",stdin);
	freopen("CT.OUT","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	nhap();
	Hamilton_Cycle(1,u); 
	if(cnt == 0) cout << 0;
	else { 
		cout << cnt << "\n" ; 
		for(auto &x : res) {
			for(int y : x) {
				cout << y << " " ;
			}
			cout << "\n" ;
		}
	}
	return 0;
}