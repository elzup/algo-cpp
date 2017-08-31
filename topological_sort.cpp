#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a, 0, sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define SIZE(array) (sizeof(array) / sizeof(array[0]))

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define MAX_V 100000

#define MOD 1000000007L
#define INF 2147483647

vector<int> topological_sort(const vector<vector<int>>& g) {
	const int V = g.size();
	vector<int> indeg(V, 0); // Num of from
	stack<int> S;	// Top

	for(auto& vs : g)
		for(auto& v: vs)
			indeg[v]++;

	REP(i,V)
		if (indeg[i] == 0)
			S.push(i);

	vector<int> ans;
	while( S.size() > 0) {
		int u = S.top(); S.pop();
		ans.emplace_back(u);
		for (auto& v : g[u]) {
			indeg[v] --;
			if (indeg[v] == 0) {
				S.push(v);
			}
		}
	}
	return ans;
}

signed main() {
	int V, E;
	cin >> V >> E;
	vector<vector<int>> vs(V);
	for (int i = 0; i < E; ++i) {
		int from, to;
		cin >> from >> to;
		vs[from].push_back(to);
	}
	vector<int> res = topological_sort(vs);
	for (int t: res) {
		cout << t << endl;
	}
}
