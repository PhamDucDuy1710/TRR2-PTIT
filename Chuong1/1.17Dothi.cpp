#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
int sp[10000], ep[10000], a[105][105], degin[10000], degout[10000], b[105][105] ;
int main() {
    freopen("DT.INP","r",stdin);
    freopen("DT.OUT","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, m ;
    cin >> t >> n >> m ; 
    for(int i = 1 ;i <= m;i++) {
    	cin >> sp[i] >> ep[i] ;
    	degout[sp[i]]++ ;
    	degin[ep[i]]++ ;
    	a[sp[i]][ep[i]] = 1 ;
    }

    if(t == 1) {
    	for(int i = 1;i <= n ;i++) {
    		cout << degin[i] << " " << degout[i] << "\n" ;
    	}
    }
    else {
    	int m = 0;
        for(int i = 1; i <= n ;i++) {
            for(int j = 1 ;j <= n;j++) {
                if(a[i][j] == 1) {
                    m++ ;
                    b[i][m] = 1;
                    b[j][m] = -1;
                }
            }
        }
        cout << n << " " << m << "\n" ;
        for(int i = 1 ;i <= n ;i++) {
            for(int j = 1; j<= m;j++) {
                cout << b[i][j] << " " ;
            }
            cout << "\n" ;
        }
    }
    return 0;
}