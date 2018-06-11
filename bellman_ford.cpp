/*
 ベルマンフォードのアルゴリズム
 各辺についてto > from + costとなる場合は更新、これを更新がなくなるまで繰り返す。
 負のコストの経路が存在しない場合は最悪|V|-1回の繰り返しで求まる。（最短炉は同じ頂点をとおらないため）
 逆に、|V|回目のループデモ行進が終わらない場合負の経路が存在するということになる。
*/

//O(|V||E|)

//頂点formから頂点toへのコストcostの辺
struct edge{int from, to, cost};

edge es[MAX_E];	//辺

int d[MAX_V];	//最短距離
int V, E;		//Vは頂点数、Eは辺数

//ｓ番目の頂点から各頂点への最短距離を求める
void syortest_path(int s) {
	for (int i = 0; i < V; i++) d[i] = INF;
	d[s] = 0;
	while (true) {
		bool update = false;
		for (int i = 0; i < E; i++) {
			edge e = es[i];
			if (d[e.from] != INF && d[e.to] > d.[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
				update = true;
			}
		}
		if (!update) break;
	}
}


//trueなら負の経路が存在する
bool find_negative_loop() {
	memset(d, 0, sizeof(d));
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < E; j++) {
			edge e = es[j];
			if (d[e.to] = d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;

				//n回目にも更新があるなら負の経路が存在する。
				if (i == V - 1)return true;
			}
		}
	}
	return false;
}

