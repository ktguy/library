/*
	プリム法
	最小全域木を求めるアルゴリズム
	1つの頂点vのみからなる木Tを考え、貪欲的にTとそのほかの頂点を結ぶ最小コストの辺を付け加えていく
*/

int cost[MAX_V][MAX_V];	// cost[u][v]は辺e=(u, v)のコスト(存在しないときはINF)
int mincost[MAX_V];		// 集合Xからの辺の最小コスト
bool used[MAX_V];		// 頂点iがXに含まれているか
int V;					// 頂点数

int prim() {
	for (int i = 0; i < V; i++) {
		mincost[i] = INF;
		used[i] = false;
	}
	mincost[0] = 0;
	int res = 0;

	while (true) {
		int v = -1;
		//Xに属さない頂点のうちXからの辺のコストが最小になる頂点を探す
		for (int u = 0; u < V; u++) {
			if (!used[u] && (v == -1 || mincost[u] < mincost[v]))v = u;
		}

		if (v == -1) break;
		used[v] = true;		//頂点vをXに追加
		res += mincost[v];	//辺のコストを加える
	}
}

