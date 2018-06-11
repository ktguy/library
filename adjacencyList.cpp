// 隣接リストの表現
// 蟻本 p90
vector<int> G[MAX_N];

/*
辺に属性がある場合
struct edge { int to, cost; };
vector<edge> G[MAX_V];
*/

int main() {
	int V, E;
	cin << V << E;
	for (int i = 0; i < E; i++) {
		int s, t;
		cin << s << t;
		G[s].push_back(s);
	}
	/*
	グラフの操作
	*/
	return 0;
}