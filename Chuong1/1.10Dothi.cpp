#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
int deg[105], a[105][105] ;
int main(){
    freopen("DT.INP","r",stdin);
    freopen("DT.OUT","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<int,pair<int,int>>> v;
    int t, n ;
    cin >> t >> n;
    for(int i = 1; i <= n ;i++) {
        for(int j = 1; j <= n ;j++) {
            cin >> a[i][j];
            if(a[i][j] != 0 && a[i][j] != 10000) {
                deg[i]++;
                if(j > i) {
                    v.pb({i,{j,a[i][j]}});
                }
            }
        }
    }
    if(t == 1) {
        for(int i = 1; i <= n ;i++) {
            cout << deg[i] << " ";
        }
    }
    else {
        cout << n << " " << v.size() << "\n"; 
        for(auto x : v) {
            cout << x.fi << " " << x.se.fi << " " << x.se.se << "\n";
        }
    }
}