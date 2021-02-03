#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
long long dp[1000001];

int main(){
	long long i;
	long long n;
	long long testcase;
	cin >> testcase;

	while (testcase--) {
		cin >> n;
		memset(dp, -1, sizeof(dp));

		dp[1] = 1, dp[2] = 2, dp[3] = 4;

		for (int i = 4; i <= n; i++) {
			dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1])%1000000009;

		}

		cout << dp[n] << '\n';
	}
}
