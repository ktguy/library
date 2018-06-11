#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <functional>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

using namespace std;
typedef pair<int, int> P;

#define pi 3.141592653589793)
#define mod 1000000007

//TLE本　17.1コイン問題
//n:支払う金額、m:コインの枚数、c[i]:i番目のコインの額面
//T[n]:n円支払う時のコインの最小枚数

int CoinChangingProblem(int n, int m, int *c) {
	const int N_MAX = 20;
	const int INF = (1 << 29);
	int T[N_MAX+1]; 
	for (int i = 0; i <= N_MAX; i++)T[i] = INF;
	T[0] = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j + c[i] <= n; j++) {
			T[j + c[i]] = min(T[j + c[i]], T[j] + 1);
		}
	}
	return T[n];
}

void solve() {
	int n, m, c[21];
	cin >> n >> m;
	for (int i = 1; i <= m; i++)cin >> c[i];
	cout << CoinChangingProblem(n,m, c) << endl;

}

int main() {
	solve();
	return 0;
}