 #include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

struct canh{
    int x, y, w ;
};

int n, m, a[105][105] ;
vector<canh> E ;
vector<int> parent(105, -1);
void nhap() {
    E.clear() ; 
    cin >> n >> m ; 
    for(int i = 1 ; i <= m ;i++) {
        int x, y, w ; 
        cin >> x >> y >> w ; 
        E.pb({x,y,w}) ; 
    }
}

void BellmanFord() {
    vector<int> d(n + 1,1e9) ; 
    d[s] = 0;
    for(int i = 1 ; i <= n - 1 ;i++) {
        for(canh e : E) {
            int u = e.x, v = e.y, w = e.w ;
            if(d[u] < 1e9) {
                if(d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    parent[v] = u ;
                }
            }
        }
    }
    for(canh e : E) {
        int u = e.x, v = e.y, w = e.w ;
        if(d[u] < 1e9) {
            if(d[v] > d[u] + w) {
                cout << 1 << "\n" ; 
                return ;
            }
        }
    }
    cout << 0 << "\n" ; 
}
int main(){
    freopen("BN.INP","r",stdin);
    freopen("BN.OUT","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t ;
    while(t--) {
        nhap() ;
        BellmanFord() ;
    }

    return 0;
}