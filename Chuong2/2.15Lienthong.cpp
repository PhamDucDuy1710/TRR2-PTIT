#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
int a[105][105], n ; 
bool vs[10000] ; 
void dfs(int u) {
	vs[u] = 1; 
	for(int v = 1 ; v <= n ;v++) {
		if(vs[v] == 0 && a[u][v] == 1) {
			dfs(v) ; 
		}
	}
}
void dfs_yeu(int u) {
	vs[u] = 1 ;
	for(int v = 1 ;v <= n ;v++) {
		if(vs[v] == 0 && (a[u][v] || a[v][u])) {
			dfs_yeu(v) ; 
		}
	}
}
bool lty() { // Liên thông yếu bỏ hướng cạnh thì liên thông 
	memset(vs,0,sizeof(vs)) ; 
	dfs_yeu(1) ; 
	for(int i = 1 ;i <= n ;i++) {
		if(vs[i] == 0) return 0 ; 
	}
	return 1; 
}
bool ltm() { // Liên thông mạnh mọi đỉnh đi qua đi lại được 
	for(int i = 1;i <= n ;i++) {
		memset(vs,0,sizeof(vs)) ; 
		dfs(i) ; 
		for(int j= 1 ; j <= n ;j++) {
			if(!vs[j]) return 0 ;
		}
	}
	return 1 ;
}
int main(){
    freopen("TK.INP","r",stdin);
    freopen("TK.OUT","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n ; 
    for(int i = 1; i <= n ;i++) {
    	for(int j = 1 ;j <= n ;j++) {
    		cin >> a[i][j] ;
    	}
    }
    if(!lty()) {
    	cout << 0 << "\n" ; 
    }
    else {
    	if(ltm()) cout << 1 << "\n" ; 
    	else {
    		cout << 2 << "\n" ; 
    	}
    }

    return 0;
}
// liên thông mạnh => liên thông yếu  