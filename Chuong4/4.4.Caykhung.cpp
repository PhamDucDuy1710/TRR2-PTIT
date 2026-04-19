#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

int n, u, a[105][105] ;
typedef pair<int,int> ii ;
typedef pair<int, pair<int,int>> iii ;
vector<ii> ke[100005] ;
int used[100005] ;

void nhap() {
	cin >> n >> u ; 
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ;j <= n ;j++) {
			cin >> a[i][j] ;
			if(a[i][j] != 0 && a[i][j] != 10000) {
				ke[i].pb({j,a[i][j]}) ;
			}
		}
	}
}

void Prim(int u) {
	memset(used, 0, sizeof(used));
	used[u] = 1 ;
	priority_queue<iii, vector<iii>, greater<iii>> q ;
	vector<iii> MST ;
	for(ii it : ke[u]) {
		if(!used[it.first]) {
			q.push({it.second,{u,it.first}}) ;
		}
	}
	ll d = 0 ;
	while(!q.empty()) {
		iii p = q.top(); q.pop() ;
		int w = p.first ;
		int x = p.second.first ;
		int y = p.second.second ;
		if(used[y]) continue ;
		used[y] = 1 ;
		d += w ;
		MST.pb({w,{x,y}}) ; 
		for(ii it : ke[y]) {
			if(!used[it.first]) {
				q.push({it.second,{y,it.first}}) ;
			}
		}	
	}
	if(MST.size() == n - 1) {
		cout << d << "\n" ; 
		for(auto x : MST) {
			int u = min(x.second.first, x.second.second);
    		int v = max(x.second.first, x.second.second);
			cout << u << " " << v << " " << x.first << "\n" ;
		}
	}
	else {
		cout << 0 << "\n" ;
	}
}

int main(){
    freopen("CK.INP","r",stdin);
    freopen("CK.OUT","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    nhap() ; 
    Prim(u) ;

    return 0;
}