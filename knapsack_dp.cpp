#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a, 0, sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define SIZE(array) (sizeof(array) / sizeof(array[0]))

#define MAXAS(x,v) x = max(x,v)

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define PI 3.141592653589793

#define MOD 1000000007L
#define INF 100000000000

signed main() {
	int n, w;
	cin >> n >> w;
	int ws[n], vs[n];
	map<int, int> dp[n + 1];
	dp[0][0] = 0;
	for (size_t i = 0; i < n; i++) {
		cin >> ws[i] >> vs[i];
	}

	for (size_t i = 0; i < n; i++) {
		for (auto const &e: dp[i]) {
			MAXAS(dp[i + 1][e.first], dp[i][e.first]);
			const int nw = ws[i] + e.first;
			const int nv = vs[i] + e.second;
			if (nw <= w) {
				MAXAS(dp[i + 1][nw], nv);
			}
		}
		cin >> ws[i] >> vs[i];
	}

	int m = 0;
	for (auto const &e: dp[n]) {
		MAXAS(m, dp[n][e.first]);
	}
	cout << m << endl;
}

