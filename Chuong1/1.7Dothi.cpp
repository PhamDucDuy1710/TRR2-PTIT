#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
int sp[10000], ep[10000], a[105][105], deg[10000] ; 
int main(){
    freopen("DT.INP","r",stdin);
    freopen("DT.OUT","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n ;
    cin >> t >> n ; 
    for(int i = 1 ; i <= n ;i++) {
    	int k ; 
    	cin >> k ; 
    	deg[i] = k ; 
    	for(int j = 1; j <= k ;j++) {
    		int u ; 
    		cin >> u ; 
    		a[i][u] = 1; 
    		a[u][i] = 1; 
    	}
    }
    if(t == 1) {
    	for(int i = 1 ; i <= n ;i++) {
    		cout << deg[i] << " " ; 
    	}
    } 
    else {
    	cout << n << "\n" ; 
    	for(int i = 1; i <= n ;i++) {
    		for(int j = 1; j <= n ;j++) {
    			cout << a[i][j] << " " ; 
    		}
    		cout << "\n" ;
    	}
    }

    return 0;
}