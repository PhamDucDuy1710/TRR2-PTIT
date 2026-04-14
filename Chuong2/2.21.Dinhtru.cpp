#include<bits/stdc++.h>
using namespace std;

int a[105][105], lt[100005], n;

void DFS(int u) {
    lt[u] = 1;
    for(int v = 1; v <= n; v++) {
        if(lt[v] == 0 && a[u][v] == 1) {
            DFS(v);
        }
    }
}

int tpltDfs() {
    int k = 0;
    for(int i = 1; i <= n; i++)
        lt[i] = 0;

    for(int i = 1; i <= n; i++) {
        if(lt[i] == 0) {
            k++;
            DFS(i);
        }
    }
    return k;
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    int k = tpltDfs();
    vector<int> res;
    for(int u = 1; u <= n; u++) {
        vector<int> ke;
        // xóa cạnh của u
        for(int v = 1; v <= n; v++) {
            if(a[u][v] == 1) {
                ke.push_back(v);
                a[u][v] = 0;
                a[v][u] = 0;
            }
        }
        for(int i = 1; i <= n; i++)
            lt[i] = 0;
        lt[u] = 1;
        int I = 0;
        for(int i = 1; i <= n; i++) {
            if(lt[i] == 0) {
                I++;
                DFS(i);
            }
        }
        if(I > k){
            res.push_back(u);
        }
        // khôi phục cạnh
        for(int v : ke) {
            a[u][v] = 1;
            a[v][u] = 1;
        }
    }
    cout << res.size() << "\n";
    for(auto x : res)
        cout << x << " ";

    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    solve();
}