/*
 * Binary Indexed Tree
 * 計算量 : O(log n)
 * ・和の計算	…　iが与えられたときに a1 + a2 + ... + ai を計算
 * ・加算		…　iとxが与えられたとき、ai += x とする
 */


// [1, n] 1 <= x <= n
int bit[MAX_N + 1], n;

// BITでの和の計算
int sum(int i) {
	int s = 0;
	while (i > 0) {
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

// BITでの値の加算
void add(int i, int x) {
	while (i <= n) {
		bit[i] += x;
		i += i & -i;
	}
}