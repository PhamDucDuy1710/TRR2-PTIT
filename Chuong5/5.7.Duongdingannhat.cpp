#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define F(i, a, b) for(int i = a; i < b; i++)
#define FD(i, a, b) for(int i = a; i > b; i--)
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define file(name) freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);
typedef pair<int,int> ii ; 
typedef pair<int,pair<int,int>> iii ; 
struct canh {
    int x, y, w;
};
int n, s, t ;
int a[105][105]; 
vector<int> parent(105,-1); 
vector<canh> E; 
void nhap() {
    cin >> n >> s >> t ;
    for(int i = 1; i <= n ; i++) {
        for(int j = 1; j <= n ;j++) {
            cin >> a[i][j] ; 
            if(a[i][j] != 0 && a[i][j] != 10000) {
                E.pb({i,j,a[i][j]}) ; 
            }
        }
    }
}
void BellmanFord() {
    vector<int> d(n+1,1e9) ; 
    d[s] = 0 ; 
    for(int i = 1 ;i <= n - 1 ;i++) {
        for(canh e : E) {
            int u = e.x, v = e.y, w = e.w ; 
            if(d[u] < 1e9) {
                if(d[v] > d[u] + w) {
                    d[v] = d[u] + w ;
                    parent[v] = u ;
                }
            }
        }
    }
    for(canh e : E) {
        int u = e.x, v = e.y, w = e.w ; 
        if(d[u] < 1e9) {
            if(d[v] > d[u] + w) {
                cout << -1 << "\n" ; 
                return ; 
            }
        }
    }
    if(d[t] == 1e9) {
        cout << 0 << "\n" ; 
    }
    else {
        cout << d[t] << "\n" ; 
        vector<int> res ; 
        while(t != -1) {
            res.pb(t) ;
            t = parent[t]; 
        }
        reverse(res.begin(),res.end()) ; 
        for(auto x : res) {
            cout << x << " " ; 
        }
    }
}
void solve() {
    nhap() ; 
    BellmanFord() ;
}

int main() {
    freopen("BN.INP", "r", stdin); 
    freopen("BN.OUT", "w", stdout) ;
    solve() ;
}
