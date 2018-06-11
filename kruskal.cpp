/*
	クラスカル法
	最小全域木を求めるアルゴリズム
	辺のコストを小さい順にみていき、閉路、二重辺ができなければ追加する
	O(|E|log|V|)　ソートが一番時間かかる。
*/

//Union-find木を使用,,,Union_Find.cppを上に張り付けて使う

struct edge { int u, v, cost; };

bool comp(const edge& e1, const edge& e2) {
	return e1.cost < e2.cost;
}

edge es[MAX_E];
int V, E;

int kruskal() {
	sort(es, es + E, comp);
	init(V);
	int res = 0;
	for (int i = 0; i < E; i++) {
		edge e = es[i];
		if (!same(e.u, e.v)) {
			unite(e.u, e.v);
			res += e.cost;
		}
	}
	return res;
}
