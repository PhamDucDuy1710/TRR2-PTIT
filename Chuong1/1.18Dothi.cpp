#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
int a[105][105], degin[10000], degout[10000] ;
int main(){
    freopen("DT.INP","r",stdin);
    freopen("DT.OUT","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n ;
    cin >> t >> n ; 

    for(int i = 1 ;i <= n ;i++) {
    	int k ; 
    	cin >> k ; 
    	for(int j = 1; j <= k ;j++) {
    		int u; 
    		cin >> u ; 
    		degout[i]++ ; 
    		degin[u]++ ;
    		a[i][u] = 1 ;
    	}
    }
    if(t == 1) {
   		for(int i = 1 ;i <= n ;i++) {
   			cout << degin[i] << " " << degout[i] << "\n" ; 
   		}
   	}
   	else {
   		cout << n << "\n" ; 
      	for(int i = 1 ;i <= n ;i++) {
    		for(int j= 1 ;j <= n;j++) {
   				cout << a[i][j] << " " ; 
   			}
   			cout << "\n" ;
   		}
   	}
    return 0;
}