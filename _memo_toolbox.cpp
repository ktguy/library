/*
	優先度付キューの昇順とりだし（pair格納時）	

	pair<int, int> p;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;

	void solve() {
		REP(i, 10) {
			int a, b;
			cin >> a >> b;
			p.first = a, p.second = b;
			que.push(p);
		}
		cout << endl;
		REP(i, 10) {
			pair<int, int> pr = que.top();
			cout << pr.first << " " << pr.second << endl;
			que.pop();
		}
	}
*/

/*	
	ソートについてのメモ
	
	char c[] = { 'c', 'a', 'b' };
	sort(c, c+3, greater<char>());

	string c = "cab";
	sort(c.begin(), c.end(), greater<char>());
*/

/*
	二分探索についてのメモ

	const int N = 10;
	int a[N] = { 1,2,3,4,5,6,7,8,9,10 };
	
	int *au, *al;
	au = upper_bound(a, a + N, 5);
	al = lower_bound(a, a + N, 5);

	cout << "upper_bound(a, a+N, 5)" << endl;
	cout << "num : " << *au << endl;//6
	cout << "10から数えて : " << a + N - au << endl;//5
	cout << "1から数えて : " << au - a + 1 << endl;//6

	cout << "lower_bound(a, a+N, 5)" << endl;
	cout << "num : " << *al << endl;//5
	cout << "10から数えて : " << a + N - al << endl;//6
	cout << "1から数えて : " << al - a + 1 << endl;//5
*/


/*******************************************************************************************************************************/
//ツールボックス
 
/* run
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>	// upper_bound(A, A+N, num), lower_bound(A, A+N, num)
#include <functional>
#include <string>
#include <sstream>
#include <complex>
#include <vector>		// V[i],  push_back(x), pop_back(), insert(index, x), erase(index), sort(v.begin(), v.end(), greater<int>())
#include <list>			// push_front(x), push_back(x), pop_front(), pop_back(), insert(index, x)
#include <queue>		// push(x), front(), pop()
#include <deque>
#include <stack>		// push(x), top(), pop()
#include <map>			// M[key],  insert(key, val), erase(key), find(key),
#include <set>			// insert(key), erase(key), find(key)

using namespace std;
typedef long long ll;
// typedef pair<int, int> P;

#define PI 3.141592653589793)
#define MOD 1000000007
#define REP(i, n) for(int i = 0; i < n; i++)

void solve() {

}

int main() {
	solve();
	return 0;
}
*/