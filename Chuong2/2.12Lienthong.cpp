#include<bits/stdc++.h>
using namespace std;

int n;
int a[105][105];
bool vs[105];

int main(){
    freopen("TK.INP","r",stdin);
    freopen("TK.OUT","w",stdout);

    cin >> n;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> a[i][j];

    vector<vector<int>> res;

    memset(vs,false,sizeof(vs));

    for(int i=1;i<=n;i++){
        if(!vs[i]){

            vector<int> comp;
            queue<int> q;

            q.push(i);
            vs[i] = true;

            while(!q.empty()){
                int v = q.front();
                q.pop();

                comp.push_back(v);

                for(int j=1;j<=n;j++){
                    if(!vs[j] && a[v][j]){
                        vs[j] = true;
                        q.push(j);
                    }
                }
            }

            sort(comp.begin(), comp.end());
            res.push_back(comp);
        }
    }

    cout << res.size() << "\n";

    for(auto &v : res){
        for(int x : v) cout << x << " ";
        cout << "\n";
    }
}