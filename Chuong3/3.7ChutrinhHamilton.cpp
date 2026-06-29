#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

int n, u, a[105][105], HC[105] ; 
set<int> adj[105] ;
bool used[105] ; 
int cnt = 0 ;
void nhap() {
	cin >> n >> u ; 
	for(int i = 1 ; i <= n ;i++) {
		for(int j = 1 ;j <= n ;j++) {
			cin >> a[i][j] ; 
			if(a[i][j]) {
				adj[i].insert(j) ; 
			}
		}
	}
	memset(used,false,sizeof(used)) ;
}

void Hamilton_Cycle(int pos, int u) {
	used[u] = true ; 
	HC[pos] = u ; 
	if(pos == n) {
		if(adj[u].count(HC[1])) {
			for(int i = 1 ;i <= n ; i++) cout << HC[i] << " " ; 
			cout << HC[1] << "\n" ; 
			cnt++ ; 
		}
		used[u] = false ; 
		return ;
	}
	for(int v : adj[u]) {
		if(!used[v]) {
			Hamilton_Cycle(pos + 1, v) ; 
		}
	}
	used[u] = false ;
}

int main(){
    freopen("CT.INP","r",stdin);
    freopen("CT.OUT","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    nhap() ; 
    Hamilton_Cycle(1,u) ; 

	cout << cnt ;    

    return 0;
}

prev_per