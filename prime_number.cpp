/*
 *　素数判定、約数の列挙、素因数分解、エラトステネスの篩
 *　計算量 : O(√N)
 */

// 入力はすべて正とする
// 素数判定 O(√N)
bool is_prime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n%i == 0)return false;
	}
	return n != 1; //1の場合は例外
}

// 約数の列挙
vector<int> divisor(int n) {
	vector<int> res;
	for (int i = 1; i * i <= n; i++) {
		if (n%i == 0) {
			res.push_back(i);
			if (i != n / i) res.push_back(n / i);
		}
	}
	return res;
}

// 素因数分解
map<int, int> prime_factor(int n) {
	map<int, int> res;
	for (int i = 2; i * i <= n; i++) {
		while (n%i == 0) {
			++res[i];
			n /= i;
		}
	}
	if (n != 1)res[n] = 1;
	return res;
}

// エラトステネスの篩　n以下の素数の数 (動作確認済み)
// O(N log log N)
int prime[MAX_N];			// i番目の素数
bool is_prime[MAX_N + 1];	// is_prime[i]がtrueならiは素数

int sieve(int n) { // n以下の素数の数を返す
	int p = 0;
	for (int i = 0; i <= n; i++) is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (is_prime[i]) {
			prime[p++] = i;
			for (int j = 2 * i; j <= n; j += i)is_prime[j] = false;
		}
	}
	return p;
}

// 区間篩 [a,b)間の素数の数
const ll MAX_L = 1000000;			// 10^6くらい
const ll MAX_SQRT_B = 1000000;		// 10^6くらい

bool is_prime[MAX_L];				// b-a の最大値
bool is_prime_small[MAX_SQRT_B];	// √b の最大値

									// [a,b)の整数に対して篩を行う。is_prime[i-a]=true ⇔ iが素数
void segment_sieve(ll a, ll b) {
	for (int i = 0; (ll)i*i < b; i++) is_prime_small[i] = true;
	for (int i = 0; i < b - a; i++) is_prime[i] = true;

	for (int i = 2; (ll)i*i < b; i++) {
		if (is_prime_small[i]) {
			for (int j = 2 * i; (ll)j*j < b; j += i) is_prime_small[j] = false;					// [2.√b)の篩
			for (ll j = max((ll)2, (a + i - 1) / i) * i; j < b; j += i) is_prime[j - a] = false;	//[a,b)の篩
		}
	}
}