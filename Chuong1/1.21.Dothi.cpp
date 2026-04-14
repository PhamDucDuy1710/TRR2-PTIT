#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
int c[105][105], degin[10000], degout[10000] ;
int main(){
    freopen("DT.INP","r",stdin);
    freopen("DT.OUT","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n ; 
    cin >> t >> n ; 
    for(int i = 1; i <= n ;i++) {
    	for(int j= 1 ; j <= n ;j++) {
    		cin >> c[i][j] ;
    	}
    }
    int m = 0 ;
    for(int i = 1 ;i <= n ;i++) {
    	for(int j = 1; j <= n;j++) {
    		if(c[i][j] != 0 && c[i][j] != 10000) {
    			degout[i]++ ;
    			degin[j]++; 
    			m++ ; 
    		}
    	}
    }
    if(t == 1) {
    	for(int i = 1 ;i<= n;i++) {
    		cout << degin[i] << " " << degout[i] << "\n" ;
    	}
    }
    else {
    	cout << n << " " << m << "\n" ; 
    	for(int i = 1 ;i <= n ;i++) {
    		for(int j = 1; j <= n ;j++) {
    			if(c[i][j] != 0 && c[i][j] != 10000) {
    				cout << i << " " << j << " " << c[i][j] << "\n" ;
    			}
    		}
    	}
    }
    return 0;
}