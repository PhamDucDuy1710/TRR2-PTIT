#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

struct canh{
	int x, y, w;
};

bool cmp(canh u, canh v) {
	if(u.w != v.w) return u.w < v.w ;
	if(u.x != v.x) return u.x < v.x ;
	return u.y < v.y ;
}

int n, m ; 
int parent[100005], sz[100005] ; 
vector<canh> dscanh ;

void init() {
	for(int i = 1 ; i <= n ; i++) {
		parent[i] = i ; 
		sz[i] = 1;
	}
}

int Find(int u) {
	if(u == parent[u]) {
		return u ;
	}
	return parent[u] = Find(parent[u]) ;
}

bool Union(int x, int y) {
	x = Find(x) ; 
	y = Find(y) ; 
	if(x == y) return false ; 
	if(sz[x] < sz[y]) {
		parent[x] = y ; 
		sz[y] += sz[x] ; 
	}
	else {
		parent[y] = x ; 
		sz[x] += sz[y] ;
	}
	return true ;
}

void Kruskal() {
	sort(dscanh.begin(),dscanh.end(),cmp) ; 
	vector<canh> MST ;
	ll d = 0 ; 
	for(int i = 0 ; i < m ; i++) {
		int x = dscanh[i].x, y = dscanh[i].y, w = dscanh[i].w; 
		if(Union(x,y)) {
			MST.pb(dscanh[i]) ;
			d += w; 
		}
		if(MST.size() == n - 1) break ;
	}
	if(MST.size() == n - 1) {
		cout << d << "\n" ; 
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
    int t ;
    cin >> t ;
    while(t--) {
    	dscanh.clear() ; 
    	cin >> n >> m ; 
    for(int i = 0 ; i < m ;i++) {
    	int x, y, w ;
    	cin >> x >> y >> w ; 
    	dscanh.pb({x,y,w}) ;
    }
    init() ; 
    Kruskal() ;
    }
    
    return 0;
}