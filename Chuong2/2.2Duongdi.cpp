#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
int a[105][105], n, st, en, e[10000], cnt = 0 ;
bool vs[10000], ok = 0;

void bfs1(int u){
    queue<pair<int,int>> q; // (đỉnh, độ sâu)
    q.push({u,0});

    while(!q.empty()){
        int v = q.front().fi;
        int d = q.front().se;
        q.pop();

        if(d > 2) continue;

        if(v == en && d == 2){
            cnt++;
            continue;
        }

        for(int i = 1; i <= n; i++){
            if(a[v][i] == 1){
                q.push({i, d + 1});
            }
        }
    }
}
void bfs2(int u) {
    queue<int> q ;
    q.push(u) ; 
    vs[u] = 1 ;
    while(!q.empty()) {
    	int v = q.front() ;
    	q.pop() ; 
    	if(v == en) {
    		ok = 1 ;
    		return ;
    	}
    	for(int i = 1; i <= n ;i++) {
    		if(vs[i] == 0 && a[v][i] == 1) {
    			q.push(i) ;
    			vs[i] = 1 ;
    			e[i] = v ;
    		}
    	}
   	}
    	
}
int main(){ 
    freopen("TK.INP","r",stdin);
    freopen("TK.OUT","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

   	int t ;
   	cin >> t >> n >> st >> en ;
   	for(int i = 1 ; i<= n ;i++) {
   		for(int j = 1 ; j <= n ;j++) {
   			cin >> a[i][j] ;
   		}
   	}
   	if(t == 1) {
   		bfs1(st) ; 
   		cout << cnt << "\n" ; 
   	}
   	else{
   		bfs2(st) ; 
   		if(!ok) {
   			cout << "0\n" ;
   		}
   		else {
   			vector<int> res ; 
   			int u = en ; 
   			while(u != st) {
   				res.push_back(u) ; 
   				u = e[u] ;
   			}
   			res.push_back(st) ; 
   			reverse(res.begin(),res.end()) ; 
   			for(auto x : res) {
   				cout << x << " " ; 
   			}
   		}
   	}

    return 0;
}