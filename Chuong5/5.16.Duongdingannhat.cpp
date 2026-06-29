#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <algorithm>
using namespace std;

#define endl "\n"
#define maxn 105
typedef long long ll;

const int INF = 1e9;

int n;
int a[105][105] = {};
int par[105][105];

void Floyd() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(a[i][k] != INF && a[k][j] != INF && a[i][j] > a[i][k] + a[k][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                    par[i][j] = par[k][j];
                }
            }
        }
    }
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 0 || a[i][j] == 10000) a[i][j] = INF;
            else par[i][j] = i; 
        }
    }
    Floyd();
    int max_d = 0;
    vector<int> res;
    for(int v = 1; v <= n; v++) {
        for(int t = 1; t <= n; t++) {
            if(v != t && a[v][t] != INF && a[v][t] > max_d){
                vector<int> path;
                for(int tmp = t; tmp != v; tmp = par[v][tmp]) {
                    path.push_back(tmp);
                }
                path.push_back(v);
                reverse(path.begin(),path.end());
                res = path;
                max_d = a[v][t];
            }
        }
    }
    if(max_d == 0) {
        cout << 0 << "\n";
    }
    else {
        cout << res[0] << " " << res.back() << " " << max_d << "\n";
        for(auto x : res) cout << x << " ";
    }
}

int main() {
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    solve();
}