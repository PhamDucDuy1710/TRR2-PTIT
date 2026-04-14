#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

int main(){
    freopen("DT.INP","r",stdin);
    freopen("DT.OUT","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n ;
    cin >> t >> n ; 
    int a[105][105] ; 
    for(int i = 1 ; i <= n ; i++) {
    	for(int j = 1 ; j <= n ; j++) {
    		cin >> a[i][j] ; 
    	}
    }
    if(t == 1) {
    	for(int i = 1 ; i <= n ;i++) {
    		int cnt = 0 ;
    		for(int j = 1 ; j <= n ;j++) {
    			if(a[i][j] == 1) {
    				cnt++ ; 
    			}
    		}
    		cout << cnt << " " ; 
    	}
    }
    else {
    	vector<pair<int,int>> v ; 
    	int cnt = 0; 
    	for(int i = 1; i <= n ;i++) {
    		for(int j = i + 1 ; j <= n ;j++) {
    			if(a[i][j] == 1) {
    				cnt++ ; 
    				v.push_back({i,j}) ;
    			}
    		}
    	}
    	cout << n <<  " " << cnt << "\n" ; 
    	for(auto x : v) {
    		cout << x.first << " " << x.second << "\n" ; 
    	}
    }

    return 0;
}