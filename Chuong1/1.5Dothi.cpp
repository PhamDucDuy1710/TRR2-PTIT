#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
int sp[10000], ep[10000], deg[10000], a[105][105] ;
int main(){
    freopen("DT.INP","r",stdin);
    freopen("DT.OUT","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, m ; 
    cin >> t >> n >> m ; 

    for(int i = 1 ; i <= m ;i++) {
    	cin >> sp[i] >> ep[i] ; 
    }
    if(t == 1) {
    	for(int i = 1; i <= m ;i++) {
    		deg[sp[i]]++ ; 
    		deg[ep[i]]++ ; 
    	}
    	for(int i = 1 ;i <= n ;i++) {
    		cout << deg[i] << " " ; 
    	}
    }
    else {
    	cout << n << "\n" ; 
    	for(int i = 1 ;i <= m; i++) {
    		a[sp[i]][ep[i]]++ ; 
    		a[ep[i]][sp[i]]++ ; 
    	}
        for(int i = 1 ;i <= n ;i++) {
            int cnt = 0 ;
            vector<int> v;
            for(int j = 1 ;j <= n; j++) {
                if(a[i][j] == 1) {
                    cnt++ ; 
                    v.push_back(j) ; 
                }
            }
            cout << cnt << " " ; 
            for(auto x : v) cout << x << " " ; 
            cout << "\n" ;
        }
    }

    return 0;	
}