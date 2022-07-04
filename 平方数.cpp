#include<iostream>
#include<cstdio>
#include <stack>
using namespace std;
#define ll long long;
#define inf 0x3f3f3f3f;
int a[35];
int dp[1001][1001];
int main() {
	int n; cin >> n;
	for (int i = 1; i <= 34; i++) {
		a[i] = i * i;
	}
	dp[0][0] = 1;
	for (int i = 1; i <= 34; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k * a[i] <= j; k++) {
				dp[i][j] = dp[i - 1][j-k*a[i]];
			}
		}
	}
	cout << dp[34][n];
}