#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
#include<cstdio>
using namespace std;
const int maxn = 1e5 + 10;
typedef struct node {
	int x, y;
	node(int x = 0, int y = 0) :x(x), y(y) {
	};
};
vector <node> a[maxn];
bool v[maxn];
int d[maxn], n, m, s;
void spfa(int s) {
	memset(v, true, sizeof(v));
	memset(d, 0x3f3f, sizeof(d));
	d[s] = 0; v[s] = false;
	queue <int> q;
	q.push(s);
	while (!q.empty()) {
		int k = q.front(); q.pop();
		v[k] = true;
		for (int i = 0; i < a[k].size(); i++) {
			int x = a[k][i].x;
			int y = a[k][i].y;
			if (d[k] + y < d[x]) {
				d[x] = d[k] + y;
				if (v[x]) {
					q.push(x);
					v[x] = false;
				}
			}
		}
	}
}
int main() {
	cin >> n >> m >> s;
	for (int i = 1; i <= m; i++) {
		int q, w, e;
		scanf("%d%d%d", &q, &w, &e);
		a[q].push_back(node(w, e));
	}
	spfa(s);
	for (int i = 1; i <= n; i++) {
		if (d[i] == d[0]) cout << (1 << 31) - 1 << " ";
		else cout << d[i] << " ";
	}
	return 0;
}