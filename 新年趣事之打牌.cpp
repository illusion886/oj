#include<iostream>
#include<cstdio>
#include <stack>
using namespace std;
#define ll long long;
int dp[100005];
int a[105];
int path[100005];
int deta, tw, n;
void print(int j) {//逆序输出
	stack<int> s;
	while (j > 0) {
		s.push(path[j]);
		j -= a[path[j]];
	}
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}
int main() {
	cin >> tw >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	deta = sum - tw;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = deta; j >= a[i]; j--) {
			dp[j] += dp[j - a[i]];//从后往前推
			if (dp[j - a[i]] && !path[j]) path[j] = i;//数字j由i组成
		}
	}
	if (dp[deta] >= 2) cout << "-1";
	else if (dp[deta] == 0) cout << 0;
	else print(deta);
}