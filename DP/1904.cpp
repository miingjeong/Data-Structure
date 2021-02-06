#include <bits/stdc++.h>
using namespace std;

const int MOD = 15746;
const int MAX = 1000000;
int N;
int dp[MAX + 1];

int tile(void) {

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	return dp[N] % MOD;
}
int main(void) {
	cin >> N;
	if (N > MAX)
		exit(-1);
	cout << tile() << endl;
	return 0;
}