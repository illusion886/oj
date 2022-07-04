#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 1e4;
int dp[maxn + 10][maxn + 10];
int a[maxn];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	/*
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	*/
	dp[0][0] = 1;//0取0得0
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			for (int m = 0; m <= 1 && m * a[i] <= j; m++) {
				dp[i][j] |= dp[i - 1][j - m * a[i]];// m=0;m<=b[i]&&m*a[i]<=j;m++每个数字可选b[i]次
			}
		}
	}
	if (dp[n][k] == 1) cout << "Yes";
	else cout << "No";
	//cout<<dp[n][k];
	return 0;
}