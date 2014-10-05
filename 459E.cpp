#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 311111;

vector <int> u[N];
vector <int> v[N];

int f[N];

int main()
{
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int iu, iv, iw;
		cin >> iu >> iv >> iw;
		u[iw].push_back(iu);
		v[iw].push_back(iv);
	}
	int flag = 0;
	memset(f, 0, sizeof(f));
	for(int i = 0; i < N; i++)
	{
		vector<pair<int, int> > tv;
		for(int j = 0; j < u[i].size(); j++)
		{
			if(f[u[i][j]]+1 > f[v[i][j]])
				tv.push_back(make_pair(v[i][j], f[u[i][j]]+1));
		}
		//if(u[i].size())
			//flag ^= 1;
		for(int j = 0; j < tv.size(); j++)
			f[tv[j].first] = max(f[tv[j].first], tv[j].second);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans = max(ans, f[i]);
	cout << ans << '\n';
	return 0;
}