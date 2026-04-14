#include<bits/stdc++.h>
using namespace std;

int a[105][105], n;
bool vs[105];
vector<int> res;

void dfs(int u){
    vs[u] = 1;
    res.push_back(u);

    for(int v = 1; v <= n; v++){
        if(!vs[v] && a[u][v] == 1){
            dfs(v);
        }
    }
}

int main(){
    freopen("TK.INP","r",stdin);
    freopen("TK.OUT","w",stdout);

    cin >> n;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];

    memset(vs,0,sizeof(vs));

    vector<vector<int>> ans;

    for(int i = 1; i <= n; i++){
        if(!vs[i]){
            res.clear();
            dfs(i);
            sort(res.begin(), res.end());
            ans.push_back(res);
        }
    }

    cout << ans.size() << "\n";

    for(auto &v : ans){
        for(int x : v) cout << x << " ";
        cout << "\n";
    }
}