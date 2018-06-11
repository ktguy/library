/*
	ダイクストラのアルゴリズム
	1.最短距離が確定した頂点と隣接している頂点を更新する。
	2.(距離dが最小のものを最短距離として確定する)
	3.1で使った「最短距離が確定した頂点」はもう使わない。

	//幅優先探索でキューを使ってやっていたことを優先度つきキューで行っている
*/

//O(|E|log|V|)
struct edge{int to, cost};
typedef pair<int, int> P;	//firstは最短距離、secondは頂点の番号

int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s) {
	//greater<P>を指定することでfirstが小さい順に取り出せるようにする
	priority_queue<P, vector<P>, greater<P>> que;
	fill(d, d + V, INF);
	d[s] = 0;
	que.push(P(0, s));

	while (!que.empty()) {
		P p = que.top(); que.pop();
		int v = que.top(); que.pop();
		if (d[v] < p.first) continue;
		for (int i = 0; i < G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}
/******************************************************************************************************/
/*
	ダイクストラのアルゴリズム（経路復元）
	d[j]=d[k]+cost[k][j]が成り立つような頂点kは最短路におけるjの直前の頂点になる
	ほかの最短経路アルゴリズムでも同じような方法で経路復元ができる。（後でやろう）
*/
int prev[MAX_V];//最短路の直前の頂点

//始点sから各頂点への最短炉を求める
void dijkstra(int s) {
	fill(d, d + V, INF);
	fill(used, used + V, false);
	fill(prev, prev + V, -1);
	d[s] = 0;

	while (true) {
		int v = -1;
		for (int u = 0; u < V; u++) {
			if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
		}
		if (v == -1) break;
		used[v] = true;

		for (int u = 0; u < V; u++) {
			if (d[u] > d[v] + cost[v][u]) {
				d[u] = d[v] + cost[v][u];
				prev[u] = v;
			}
		}
	}
}

//頂点tへの最短路 O(|V|)
vector<int> get_path(int t) {
	vector<int> path;	
	for (; t != -1; t = prev[t])path.push_back(t); //tがsになるまでprev[t]をたどっていく
	//このままだとt->sの順になるので逆順にする
	reverse(path.begin(), path.end());
	return path;
}

/******************************************************************************************************/
//O(|V|^2)
int cost[MAX_V][MAX_V];	//cost[u][v]は辺e=(u, v)のコスト（存在しない場合はINF）
int d[MAX_V];			//頂点aからの最短距離
bool used[MAX_V];		//既に使われたかのフラグ
int V;					//頂点数

//始点sから各頂点への最短距離を求める。
void dijkstra(int s) {
	fill(d, d + V, INF);
	fill(used, used + V, false);
	d[s] = 0;

	while (true) {
		int v = -1;
		// まだつかわれていない頂点のうち距離が最小のものを探す
		for (int u = 0; u < V; u++) {
			if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
		}
		if (v == -1) break;
		used[v] = true;

		for (int u = 0; u < V; u++) {
			d[u]  min(d[u].d[v] + cost[v][u]);
		}
	}
}
