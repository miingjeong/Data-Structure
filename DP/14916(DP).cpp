
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int dp[100010];

int main() {
	cin >> n;
	memset(dp, -1, sizeof(dp));
	dp[2] = 1; dp[4] = 2; dp[5] = 1;
	for (int i = 6; i <= n; i++) {
		if (dp[i - 5] != -1) dp[i] = dp[i - 5] + 1;
		if (dp[i - 2] != -1) {
			if (dp[i] == -1) dp[i] = dp[i - 2] + 1;
			else dp[i] = min(dp[i], dp[i - 2] + 1);
		}
	}
	cout << dp[n] << '\n';
}
