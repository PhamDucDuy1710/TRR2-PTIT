#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
int degin[10000], degout[10000], a[105][105] ;
int main(){
    freopen("DT.INP","r",stdin);
    freopen("DT.OUT","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, m ; 
    cin >> t >> n >> m ; 
    for(int i = 1 ; i <= n ;i++ ){
    	for(int j = 1 ;j <= n ;j++) {
    		if(i == j) a[i][j] = 0 ; 
    		else a[i][j] = 10000 ;
    	}
    }
    for(int i = 1; i <= m; i++) {
    	int u, v, k ;
    	cin >> u >> v >> k ;
    	a[u][v] = k ;
    	degout[u]++ ; 
    	degin[v]++ ;
    }
    if(t == 1) {
    	for(int i =1 ;i <= n ;i++) {
    		cout << degin[i] << " " << degout[i] << "\n" ; 
    	}
    }
    else {
        cout << n << "\n" ; 
    	for(int i = 1; i <= n ;i++) {
    		for(int j =1 ;j <= n ;j++) {
    			cout << a[i][j] << " " ;
    		}
    		cout << "\n" ;
    	}
    }

    return 0;
}