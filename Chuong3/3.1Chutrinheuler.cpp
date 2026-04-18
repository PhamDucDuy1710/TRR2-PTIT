#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

int a[100][100], n;
stack<int> st;
vector<int> ce;

bool lienThong() {
	stack<int> dinh;
	int vs[100];
	memset(vs, 0, sizeof(vs));
	dinh.push(1);
	while (!dinh.empty()) {
		int v = dinh.top();
		vs[v] = 1;
		dinh.pop();
		for (int i = 1; i <= n; i++) {
			if (a[v][i] && vs[i] == 0) {
				dinh.push(v);
				dinh.push(i);
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (vs[i] == 0) return false;
	}
	return true;
}

int checkEuler() {
    if (!lienThong()) return 0;

    int odd = 0;
    for (int i = 1; i <= n; i++) {
        int deg = 0;
        for (int j = 1; j <= n; j++) {
            if (a[i][j]) deg++;
        }
        if (deg % 2) odd++;
    }

    if (odd == 0) return 1; // Euler
    if (odd == 2) return 2; // nửa Euler
    return 0;
}
void eulerCycleVoHuong(int start) {
	st.push(start);
	while (!st.empty()) {
		int u = st.top();
		bool check = false;
		for (int i = 1; i <= n; i++) {
			if (a[u][i]) {
				check = true;
				st.push(i);
				a[u][i] = 0; a[i][u] = 0;
				break;
			}
		}
		if (!check) {
			st.pop();
			ce.push_back(u);
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
    	for(int i = 1; i <= n ; i++) {
    		for(int j = 1 ; j <= n ;j++) {
    			cin >> a[i][j] ; 
    		}
    	}
    	cout << checkEuler() << "\n" ; 
    }
    else {
    	int u ; 
    	cin >> n >> u ; 
    	for(int i = 1 ;i <= n ; i++) {
    		for(int j = 1; j <= n ;j++) {
    			cin >> a[i][j] ; 
    		}
    	}
    	eulerCycleVoHuong(u) ; 
    	for(int i = ce.size() - 1 ; i >= 0 ;i--) {
    		cout << ce[i] << " " ; 
    	}
    }
}