#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

int n, a[105][105], k ; 
bool vs[10005] ; 

void dfs(int u) {
	vs[u] = 1 ; 
	k++ ; 
	for(int v = 1; v <= n ; v++) {
		if(!vs[v] && a[u][v] == 1) {
			dfs(v) ;
		}
	}
}

int main(){
    freopen("TK.INP","r",stdin);
    freopen("TK.OUT","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n ; 
    for(int i = 1 ; i <= n ;i++) {
    	for(int j = 1; j <= n ;j++) {
    		cin >> a[i][j] ; 
    	}
    }
    bool ok = 1 ;
    for(int i = 1 ; i <= n ;i++) {
    	memset(vs,0,sizeof(vs)) ; 
    	k = 0;
    	dfs(i) ; 
    	if(k < n) {
    		ok = 0 ;
    	}
    }
    if(ok) cout << 1 << "\n" ; 
    else {
    	for(int i = 1 ; i <= n ;i++) {
    		for(int j = 1; j <= n ; j++) {
    			if(a[i][j]) a[j][i] = 1 ;
     		}
    	}
    	k = 0 ; 
    	memset(vs,0,sizeof(vs)) ;
    	dfs(1) ; 
    	if(k == n) cout << 2 << "\n" ; 
    	else cout << 0 << "\n" ;
    }

    return 0;
}