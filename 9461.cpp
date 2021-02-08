#include <bits/stdc++.h>
using namespace std;

long long dp[101] = { 0, };
int N;
int t;
int main() {

	cin >> N;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;

	for (int i = 6; i <= 100; i++)
		dp[i] = dp[i - 1] + dp[i - 5];

	for (int j = 0; j < N; j++) {
		cin >> t;
		cout << dp[t] << '\n';
	}

	return 0;
}