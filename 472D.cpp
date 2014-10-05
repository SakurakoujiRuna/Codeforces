#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 2333;

struct DS
{
	int p[N];
	DS() { for(int i = 0; i < N; i++) p[i] = i; }
	int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
	bool query(int a, int b) { return find(a) == find(b); }
	void merge(int a, int b) { p[find(b)] = find(a); }
}A;

long long d[N][N];

pair <int, pair<int, int> > p[N*N];

vector <pair<int, int> > edge[N];

bool dfs(int x, int length, int last, int start)
{
	if(d[start][x] != length)
		return false;
	for(int i = 0; i < edge[x].size(); i++)
		if(edge[x][i].first != last)
			if(!dfs(edge[x][i].first, length + edge[x][i].second, x, start))
				return false;
	return true;
}

int main()
{
	//ios::sync_with_stdio(false);
	int n; //cin >> n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			//cin >> d[i][j];
			scanf("%I64d", &d[i][j]);

	int Pind = 0;
	bool flag = true;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
		{
			p[Pind++] = make_pair(d[i][j], make_pair(i, j));
			if(d[i][j] != d[j][i])
				flag = false;
		}
	sort(p, p + Pind);
	for(int i = 0; i < Pind; i++)
		if(!A.query(p[i].second.first, p[i].second.second))
		{
			if(p[i].first == 0) flag = false;
			A.merge(p[i].second.first, p[i].second.second);
			edge[p[i].second.first].push_back(make_pair(p[i].second.second, p[i].first));
			edge[p[i].second.second].push_back(make_pair(p[i].second.first, p[i].first));
		}
//if(n != 1859)
{
	for(int i = 0; i < n; i++)
		if(!dfs(i, 0, -1, i))
			flag = false;

	if(flag) cout << "YES\n";
	else cout << "NO\n";
}
	return 0;
}