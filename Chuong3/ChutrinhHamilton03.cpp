#include<bits/stdc++.h>
using namespace std;

#define INF 10000

int n, u;
int a[105][105];
bool used[105];
int HC[105];

int best = INT_MAX;
vector<int> best_path;

void nhap(){
    cin >> n >> u;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    memset(used, false, sizeof(used));
}

void Try(int pos, int u, int cost){
    if(cost > best) return;

    used[u] = true;
    HC[pos] = u;

    if(pos == n){
        if(a[u][HC[1]] > 0 && a[u][HC[1]] < INF){
            int total = cost + a[u][HC[1]];

            if(total < best){
                best = total;
                best_path.clear();
                for(int i = 1; i <= n; i++) best_path.push_back(HC[i]);
                best_path.push_back(HC[1]);
            }
        }
        used[u] = false;
        return;
    }

    for(int v = 1; v <= n; v++){
        if(!used[v] && a[u][v] > 0 && a[u][v] < INF){
            Try(pos + 1, v, cost + a[u][v]);
        }
    }

    used[u] = false;
}

int main(){
    freopen("CT.INP","r",stdin);
    freopen("CT.OUT","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    nhap();
    Try(1, u, 0);

    if(best == INT_MAX){
        cout << 0;
    } else {
        cout << best << "\n";
        for(int x : best_path) cout << x << " ";
    }

    return 0;
}