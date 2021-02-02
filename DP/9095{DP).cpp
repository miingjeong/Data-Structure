#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int dp[11];

int main(){
	int i;
	int n;
	int testcase;
	cin >> testcase;

	while (testcase--) {
		cin >> n;
		memset(dp, -1, sizeof(dp));

		dp[1] = 1, dp[2] = 2, dp[3] = 4;

		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];

		}

		cout << dp[n] << '\n';
	}
}
