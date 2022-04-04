#include <bits/stdc++.h>
using namespace std;
const int nax = 150123;
vector<int> edges[nax];
bool vis[nax];
 
void dfs(int a, int & cnt_vertices, int & cnt_edges) {
	assert(!vis[a]);
	vis[a] = true;
	++cnt_vertices;
	cnt_edges += edges[a].size();
	for(int b : edges[a])
		if(!vis[b])
			dfs(b, cnt_vertices, cnt_edges);
}
 
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for(int i = 1; i <= n; ++i)
		if(!vis[i]) {
			int cnt_vertices = 0, cnt_edges = 0;
			dfs(i, cnt_vertices, cnt_edges);
			if(cnt_edges != (long long) cnt_vertices * (cnt_vertices - 1)) {
				puts("NO");
				return 0;
			}
		}
	puts("YES");
}