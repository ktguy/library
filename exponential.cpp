/*
 * べき乗の高速計算
 * x^n (mod _mod)を出力する。
 * 計算量 : O(log n)
 */

// x^n (mod _mod)
ll mod_pow(ll x, ll n, ll _mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1)res = res * x % _mod;	// 最下位ビットが立っているときにx^(2^i)を掛ける
		x = x * x % _mod;				// xを順次二乗していく
		n >>= 1;
	}
	return res;
}

// 再帰で記述すると以下のようになる。
// x^n (mod _mod)
ll mod_pow(ll x, ll n, ll _mod) {
	if (n == 0) return 1;
	ll res = mod_pow(x * x % _mod, n / 2, _mod);
	if (n & 1) res = res * x % _mod;
	return res;
}