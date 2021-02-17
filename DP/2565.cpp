#define _CRT_SECURE_NO_WARNINGS
#include iostream
#include vector
#include algorithm

using namespace std;

typedef long long ll;

vector pairint, int v;
int dp[105] = { 0, };

int main() {
	iossync_with_stdio(false); cin.tie(NULL);

	int N; cin  N;
	for (int i = 0; i  N; i++) {
		int a, b; cin  a  b; v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());

	dp[0] = 1;
	int ans = 0;
	for (int i = 1; i  N; i++) {
		for (int j = 0; j  i; j++) {
			if (v[i].second  v[j].second)
				dp[i] = max(dp[i], dp[j] + 1);
			else
				dp[i] = max(1, dp[i]);
		}
		ans = max(dp[i], ans);
	}
	cout  N - ans;
}