#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn = 1e5+10;
int st[maxn][25], a[maxn];
int n,m;
void init() {
	for(int i=1;i<=n;i++) st[i][0] = a[i];
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 1; i <= n - (1 << j) + 1; i++) {
			st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
}
int query(int l, int r) {
	int x = log2(r - l + 1);
	return max(st[l][x], st[r-(1<<x)+1][x]);
}
int main() {
	cin >> n>>m;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}init();
	for (int i = 1; i <= m; i++) {
		int x,y;
		scanf("%d%d", &x, &y);
		printf("%d\n",query(x,y));
	}
	return 0;
}