#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
int sp[10000], ep[10000], deg[10000], c[105][105] ;
int main(){
    freopen("DT.INP","r",stdin);
    freopen("DT.OUT","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n; 
    cin >> t >> n ; 
    for(int i = 1; i <= n ;i++) {
    	for(int j = 1; j <= n ;j++){
    		cin >> c[i][j] ; 
    	}
    }
    if(t == 1) {
    	for(int i = 1 ;i <= n ;i++) {
    		int cnt = 0 ; 
    		for(int j =1 ;j <= n;j++) {
    			if(c[i][j] != 0 && c[i][j] != 10000) {
    				cnt++ ;  
    		 	}
    		}
    		cout << cnt << " " ;
    	}
    }
    else {
    	int m= 0; 
    	for(int i = 1 ;i <= n ;i++) {
    		for(int j = i + 1;j <= n ;j++) {
    			if(c[i][j] != 0 && c[i][j] != 10000) {
    				m++ ; 
    			}
    		}
    	}
    	cout << n << " " << m << "\n" ; 
    	for(int i = 1 ;i <= n ;i++) {
    		for(int j = i + 1; j <= n ;j++) {
    			if(c[i][j] != 0 && c[i][j] != 10000) {
    				cout << i << " " << j << " " << c[i][j] << "\n" ; 
    			}
    		}
    	}
    }
    return 0;
}