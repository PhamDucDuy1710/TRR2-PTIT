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
    vector<pair<int,int>> v ;
    int t, n ;
    cin >> t >> n ; 
    int m = 0 ;
    for(int i = 1 ;i <= n ;i++) {
    	int k ; 
    	cin >> k ; 
    	for(int j = 1; j <= k ;j++) {
    		int u; 
    		cin >> u ; 
    		degout[i]++ ; 
    		degin[u]++ ;
    		m++ ;
    		v.push_back({i,u}); 
    	}
    }
    if(t == 1) {
   		for(int i = 1 ;i <= n ;i++) {
   			cout << degin[i] << " " << degout[i] << "\n" ; 
   		}
   	}
   	else {
   		cout << n << " " << m << "\n" ; 
      	for(auto x : v ){
      		cout << x.first << " " << x.second << "\n" ;
      	}
   	}
    return 0;
}