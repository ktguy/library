﻿
/*
 * segment_tree_RMQ
 * セグメント木によるRMQの実装　（動作未確認）
 * O(n) : 初期化、O(logn) : 最小値、更新
 */

const int MAX_N = 1 << 17;
const int INT_MAX = 1 << 32;

//セグメント木をもつグローバル配列
int n, dat[2 * MAX_N - 1];

//初期化
void init(int n_) {
	//簡単のため、要素数を2のべき乗に
	n = 1;
	while (n < n_) n *= 2;

	//すべての値をINT_MAXに
	for (int i = 0; i < 2 * n - 1; i++) {
		dat[i] = INT_MAX;
	}
}

// k番目の値(0-indexed)をaに変更
void update(int k, int a) {
	// 葉の接点
	k += n - 1;
	dat[k] = a;
	//のぼりながら更新
	while (k > 0) {
		k = (k - 1) / 2;
		dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
	}
}

// [a, b)の最小値を求める。
// 後ろのほうの引数は、計算の簡単のための引数。
// ｋは接点の番号、l、rはその接点が[l, r) に対応づいていることを表す。
// したがって、外からはquery(a,b,0,0,n)と呼び出す。
int query(int a, int b, int k, int l, int r) {
	// [a,b)と[l,r)が交差しなければ、INT_MAX
	if (r <= a || b <= l)return INT_MAX;

	// [a, b)が[l,r)を完全に含んでいれば、この接点の値。
	if (a <= 1 && r <= b) return dat[k];
	else {
		// そうでなければ、2つの子の最小値
		int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return min(vl, vr);
	}
}


