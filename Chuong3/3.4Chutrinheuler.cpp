#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

int n, a[105][105] ;
vector<int> ce ;
stack<int> st ;

bool lt() {
	stack<int> dinh ;
	int vs[100] ; 
	memset(vs,false,sizeof(vs)) ;
	dinh.push(1) ;
	while(!dinh.empty()) {
		int v = dinh.top() ; 
		vs[v] = 1 ;
		dinh.pop() ;
		for(int i = 1 ; i <= n ;i++) {
			if(a[v][i] == 1 && vs[i] == 0) {
				dinh.push(v) ; 
				dinh.push(i) ;
				break ;
			}
		}
	}
	for(int i = 1;i <= n ;i++) {
		if(!vs[i]) return 0 ; 
	}
	return 1 ;
}

int checkEU() {
	if(!lt()) return 0 ;
	int st = 0, en = 0 ;
	for(int i = 1; i <= n ;i++) {
		int in = 0, out = 0 ; 
		for(int j = 1; j <= n ;j++) {
			if(a[i][j]) out++ ; 
			if(a[j][i]) in++ ;
		}
		if(out - in == 1) st++ ;
		else if(in - out == 1) en++ ; 
		else if(in != out) return 0 ;
	}
	if(st == 0 && en == 0) return 1 ;
	if(st == 1 && en == 1) return 2 ;
	return 0 ;
}

void eulerCycleCoHuong(int start) {
	st.push(start) ; 
	while(!st.empty()) {
		int u = st.top() ; 
		bool check = false ; 
		for(int i = 1 ;i <= n ; i++) {
			if(a[u][i]) {
				check = true ;
				st.push(i) ; 
				a[u][i] = 0 ; 
				break ;
			}
		}
		if(!check) {
			st.pop() ;
			ce.pb(u) ;
		}
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
    	for(int i = 1 ; i <= n ; i++) {
    		for(int j = 1 ;j <= n ;j++) {
    			cin >> a[i][j] ; 
    		}
    	}
    	cout << checkEU() << "\n" ; 
    }
    else {
    	int u ; 
    	cin >> n >> u ; 
    	for(int i = 1; i <= n ;i++) {
    		for(int j = 1; j <= n; j++) {
    			cin >> a[i][j] ;
    		} 
    	}
    	eulerCycleCoHuong(u) ;
    	for(int i = ce.size() - 1 ;i >= 0 ;i--) {
    		cout << ce[i] <<  " " ;  
    	}
    }
    

    return 0;
}