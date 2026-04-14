#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
int n, start, en, cnt = 0 ; 
int a[105][105] = {}, e[10000] = {};
bool vs[10000], ok = 0; 
void dfs1(int u, int d) {
	if(d > 2) {
		return ; 
	}
	if(u == en && d == 2) {
		cnt++ ; 
		return ;
	}
	vs[u] = 1 ; 
	for(int v = 1 ; v <= n ;v++) {
		if(vs[v] == 0 && a[u][v] == 1) {
			dfs1(v,d+1) ;
		}
	}
	vs[u] = 0 ;
}
void dfs2(int u) {
	if(u == en) {
		ok = 1 ; 
		return ; 
	}
	vs[u] = 1; 
	for(int v = 1; v <= n ;v++) {
		if(vs[v] == 0 && a[u][v] == 1) {
			e[v] = u ; // e[đỉnh con] = đỉnh cha 
			dfs2(v) ; 
			if(ok) return ;
		}
	}
	vs[u] = 0 ;
}
int main(){
    freopen("TK.INP","r",stdin);
    freopen("TK.OUT","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t ;
    cin >> t >> n >> start >> en ; 
    for(int i = 1; i <= n ;i++) {
    	for(int j =1 ; j<= n ;j++) {
    		cin >> a[i][j] ;
    	}
    }
    if(t == 1) {
    	dfs1(start,0) ; 
    	cout << cnt ; 
    }
    else {
    	dfs2(start) ;
    	if(!ok) {
    		cout << "0" ;
    	}
    	else {
    		vector<int> res ; 
    		int u = en ;
    		while(u != start) {
    			res.push_back(u) ; 
    			u = e[u] ;
    		}
    		res.push_back(start) ;
   			reverse(res.begin(),res.end()) ;
    		for(auto x : res) {
    			cout << x << " " ; 
    		}
    	}
    }
    return 0;
}