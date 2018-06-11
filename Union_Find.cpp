
/*
 *	2_4 Union-Find木の実装
 *  実装確認済み arc065_d
 */
int par[MAX_N];	//親
int rnk[MAX_N];//木の深さ

//n要素で初期化
void init(int n) {
	for (int i = 0; i < n; i++) {
		par[i] = i;
		rnk[i] = 0;
	}
}

//木の根を求める
int find(int x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = find(par[x]);
	}
}

//xとyの属する集合を併合
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;

	if (rnk[x] < rnk[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (rnk[x] == rnk[y])rnk[x]++;
	}
}

//xとyが同じ集合に属するか否か
bool same(int x, int y) {
	return find(x) == find(y);
}

/*
 *	
 */