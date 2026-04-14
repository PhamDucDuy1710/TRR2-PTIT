#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
int c[105][105], deg[10000] ;
int main(){
    freopen("DT.INP","r",stdin);
    freopen("DT.OUT","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k, n, m ;
    cin >> k >> n >> m ; 
    for(int i = 1 ; i <= n ;i++) {
   		for(int j =1 ; j <= n ;j++){
   			if(i == j) {
   				c[i][j] = 0 ;
   			}
   			else {
   				c[i][j] = 10000 ; 
   			}
  		}
   	}
    for(int i = 1; i <= m;i++) {
    	int u, v, t ;
    	cin >> u >> v >> t ;
    	deg[u]++ ; 
    	deg[v]++ ; 
    	c[u][v] = t ;
    	c[v][u] = t ;
    }
   	if(k == 1) {
   		for(int i = 1 ; i <= n ;i++) {
   			cout << deg[i] << " " ; 
   		}
   	}
   	else {
   		cout << n << "\n" ; 
   		for(int i = 1 ; i <= n ;i++) {
   			for(int j = 1 ; j <= n ;j++) {
   				cout << c[i][j] << " " ; 
   			}
   			cout << "\n" ; 
   		}
   	}

    return 0;
}