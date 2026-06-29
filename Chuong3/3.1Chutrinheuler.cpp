#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fi first
#define se second
#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define F(i, a, b) for(int i = a; i < b; i++)
#define FD(i, a, b) for(int i = a; i > b; i--)
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define file(name) freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);
#define pb push_back
typedef pair<int,int> ii; 
typedef pair<int,pair<int,int>> iii;

int t, n, m, st, en, k, timer =0;
int deg[105], dt[105], dc[105];
int a[105][105], c[105][105];
bool vs[105], AP[105];
set<int> ke[105];
int e[105], sz[105], low[105], disc[105];
vector<ii> cc;

void dfs(int u) {
	vs[u] = 1;
	k++;
	for(int v = 1; v <= n; v++){
		if(a[u][v] && !vs[v]) {
			dfs(v);
		}
	}
}

bool lt() {
	memset(vs,false,sizeof(vs));
	k = 0;
	dfs(1);
	return k == n;
}

int kt() {
	if(!lt()) return 0;
	int odd = 0;
	FOR(i,1,n) {
		int deg = 0;
		FOR(j,1,n) {
			deg += a[i][j];
		}
		if(deg % 2 == 1) odd++;
	}
	if(odd == 0) return 1;
	else if(odd == 2) return 2;
	else return 0;
}

void euler(int u) {
	stack<int> st;
	vector<int> EC;
	st.push(u);
	while(!st.empty()) {
		int x = st.top();
		if(ke[x].size() != 0) {
			int y = *ke[x].begin();
			st.push(y);
			ke[x].erase(y);
			ke[y].erase(x);
		}
		else {
			st.pop();
			EC.pb(x);
		}
	}
	reverse(EC.begin(),EC.end());
	for(auto x : EC) cout << x << " ";
}

void solve() {
	cin >> t >> n;
	if(t == 1) {
		FOR(i,1,n) {
			FOR(j,1,n) {
				cin >> a[i][j];
			}
		}
		cout << kt() << "\n";
	}
	else {
		int u; cin >> u;
		FOR(i,1,n) {
			FOR(j,1,n) {
				cin >> a[i][j];
				if(a[i][j]) ke[i].insert(j);
			}
		}
		euler(u);
	}
}

int main() {
    file("CT");
    solve();
    return 0;
}