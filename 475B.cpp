#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 23;

string sn, sm;
bool vis[N][N];
int n, m;
void dfs(int a, int b)
{
	//cout << a << ' ' << b << '\n';
	vis[a][b] = true;
	if(sn[a] == '<' && b > 0 && !vis[a][b - 1])
		dfs(a, b - 1);
	if(sn[a] == '>' && b < m - 1 &&!vis[a][b + 1])
		dfs(a, b + 1);
	if(sm[b] == '^' && a > 0 && !vis[a - 1][b])
		dfs(a - 1, b);
	if(sm[b] == 'v' && a < n - 1 && !vis[a + 1][b])
		dfs(a + 1, b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	/*
	for(int i = 0; i < n; i++)
		cin >> s[i];
	*/
	cin >> sn >> sm;
	bool flag = true;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			memset(vis, 0, sizeof(vis));
			dfs(i, j);
			for(int k = 0; k < n; k++)
				for(int t = 0; t < m; t++)
					if(!vis[k][t]) flag = false;
		}
	if(flag)
		cout << "YES\n";
	else cout << "NO\n";
	return 0;
}