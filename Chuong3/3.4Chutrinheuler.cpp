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

void dfs2(int u) {
	vs[u] = 1 ; 
	for(int v = 1; v<= n ;v++) {
		if(vs[v] == 0 && (a[u][v] || a[v][u])) {
			dfs2(v) ;
		}
	}
}
bool ltch() {
	memset(vs,0,sizeof(vs)) ; 
	int st = -1 ; 
	for(int i =1 ; i<= n ;i++) {
		for(int j =1 ; j<= n ;j++) {
			if(a[i][j] || a[j][i]) {
				st = i ;
				break ;
			}
		}
		if(st != -1) break ;
	}
	if(st == -1) return 1 ; 
	dfs2(st) ;
	for(int i = 1 ;i <= n;i++) {
		int deg =0 ;
		for(int j =1 ; j<= n;j++) {
			deg += a[i][j] + a[j][i] ;
		}
		if(deg > 0 && vs[i] == 0) return 0 ;   
	}
	return 1 ;
}
int eulerCohuong() {
	if(!ltch()) return 0 ;
	memset(degin,0,sizeof(degin));
    memset(degout,0,sizeof(degout));
	for(int i = 1;i <= n ;i++) {
		for(int j =1 ;j <= n ;j++ ){
			if(a[i][j] == 1) {
				degout[i]++ ; 
				degin[j]++; 
			}
		}
	}
	int st = 0, en = 0; 
	for(int i = 1; i <= n ;i++) {
		if(degout[i] - degin[i] == 1) st++ ;
		else if(degin[i]-degout[i] == 1) en++; 
		else if(degin[i] != degout[i]) {
			return 0 ;
		}
	}
	if(st == 0 && en == 0) {
		return 1 ;
	}
	else if(st == 1 && en == 1) {
		return 2 ;
	}
	else {
		return 0 ;
	}
}
int dinhbatdauch() {
	for(int i = 1; i <= n;i++) {
		for(int j = 1; j <= n;j++) {
			if(a[i][j]) {
				degout[i]++ ; 
				degin[j]++ ;
			}
		}
	}
	int st = -1 ;
	for(int i = 1 ;i <= n ;i++) {
		if(degout[i] - degin[i] == 1) {
			return i ;
		}
		if(degout[i] > 0 && st == -1) {
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
    freopen("CT.INP","r",stdin);
    freopen("CT.OUT","w",stdout);

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
    	cout << eulerCohuong() ; 
    }
    else {
    	int k;
    	cin >> n >> k ;
    	for(int i = 1; i <= n ;i++) {
    		for(int j = 1; j <= n;j++) {
    			cin >> a[i][j] ; 
    			if(a[i][j]) {
    				adj[i].insert(j) ;
    			}
    		}
    	}
    	euler(k) ;
    }
    return 0;
}