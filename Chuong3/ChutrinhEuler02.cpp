#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
int a[105][105], b[105][105], n, degin[10005], degout[10005] ;
bool vs[10005] ; 
set<int> adj[1001] ;
void dfs1(int u) {
	vs[u] = 1 ; 
	for(int v = 1; v<= n ;v++) {
		if(vs[v] == 0 && a[u][v] == 1) {
			dfs1(v) ;
		}
	}
}
bool ltvh() {
	memset(vs,0,sizeof(vs)) ; 
	int st = -1 ;
	for(int i = 1 ;i <= n ;i++) {
		int deg = 0 ; 
		for(int j = 1; j <= n;j++) deg += a[i][j] ;
		if(deg) {
			st = i ;
			break ;
		}
	}
	if(st == -1) return 1 ; 
	dfs1(st) ;
	for(int i =1 ;i <= n ;i++) {
		int deg = 0 ;
		for(int j = 1 ;j <= n ;j++) {
			deg += a[i][j] ;
		}
		if(deg && vs[i] == 0) return 0 ;
	}
	return 1 ;
}
int eulerVohuong() {
	if(!ltvh()) {
		return 0 ; 
	}
	int odd = 0 ; 
	for(int i = 1 ;i <= n; i++) {
		int deg = 0; 
		for(int j = 1; j <= n; j++) {
			deg += a[i][j] ;
		}
		if(deg % 2 == 1) odd++ ; 
	}
	if(odd == 0) return 1 ; 
	else if(odd == 2) return 2 ;
	else return 0 ;
}
int dinhbatdauvh() {
	int st = -1 ; 
	for(int i = 1; i <= n; i++) {
		int deg = 0 ; 
		for(int j = 1; j <= n ;j++) {
			deg += a[i][j] ;
		}
		if(deg % 2 == 1) return i ; 
		if(deg > 0 && st == -1) {
			st = i ;
		}
	}
	return st ;
}

void euler(int v) {
	stack<int> st ;
	vector<int> EC ; 
	st.push(v) ; 
	while(!st.empty()) {
		int x = st.top() ; 
		if(adj[x].size() != 0) {
			int y = *adj[x].begin() ;
			st.push(y) ; 
			adj[x].erase(y) ; 
			adj[y].erase(x) ;
		}
		else {
			st.pop() ; 
			EC.push_back(x) ;
		}
	}
	reverse(EC.begin(),EC.end()) ; 
	for(auto x : EC) {
		cout << x << " " ; 
	}
}
int main(){


    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t ;
    cin >> t ;
    if(t == 1) {
    	cin >> n ; 
    	for(int i = 1; i <= n ;i++) {
    		for(int j = 1; j <= n;j++) {
    			cin >> a[i][j] ; 
    		}
    	}
    	cout << eulerVohuong() ; 
    }
    else {
    	int k;
    	cin >> n >> k ;
    	for(int i = 1; i <= n ;i++) {
    		for(int j = 1; j <= n;j++) {
    			cin >> a[i][j] ; 
    			if(a[i][j] && i < j) {
    				adj[i].insert(j) ;
    				adj[j].insert(i) ;
    			}
    		}
    	}
    	euler(k) ;
    }
    return 0;
}