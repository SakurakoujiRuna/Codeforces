#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 121111;
bool vis[N];
int prime[N];
vector<pair<int, int> > ans;

int main()
{
	ios::sync_with_stdio(false);
	int n; cin >> n;
	memset(prime, true, sizeof(prime));
	for(int i = 2; i < N; i++)
		for(int j = i+i; j < N; j += i)
			prime[j] = false;
	memset(vis, 0, sizeof(false));
	for(int i = n; i >= 2; i--)
		if(prime[i])
		{
			vector <int> V(0);
			for(int j = i; j <= n; j += i)
				if(!vis[j]) V.push_back(j);
			if(V.size() < 2) continue;
			if(V.size()&1)
			{
				ans.push_back(make_pair(V[0], V[2]));
				vis[V[0]] = vis[V[2]] = true;
				for(int i = 3; i < V.size(); i += 2)
				{
					ans.push_back(make_pair(V[i], V[i+1]));
					vis[V[i]] = vis[V[i+1]] = true;
				}
			}
			else
				for(int i = 0; i < V.size(); i += 2)
				{
					ans.push_back(make_pair(V[i], V[i+1]));
					vis[V[i]] = vis[V[i+1]] = true;
				}
		}
	cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	return 0;
}