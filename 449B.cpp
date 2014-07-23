#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

const int N = 121111, M = 711111;
struct Edge
{
	int u, v, w;
}e[M];
int Eind = 0;
int first[N], nxt[M];
void addEdge(int iu, int iv, int iw)
{
	e[Eind].u = iu; e[Eind].v = iv; e[Eind].w = iw;
	nxt[Eind] = first[iu]; first[iu] = Eind++;
}

bool vis[N];
queue <int> q;
long long dis[N];

void SPFA(int n)
{
	//q.push(s);
	//vis[s] = true;
	for(int i = 1; i <= n; i++)
	{
		vis[i] = true;
		q.push(i);
	}
	while(!q.empty())
	{
		int x = q.front();
		q.pop(); vis[x] = false;
		//cout << x << ' ' << dis[x] << '\n';
		for(int i = first[x]; i != -1; i = nxt[i])
			if(dis[x]+e[i].w < dis[e[i].v])
			{
				dis[e[i].v] = dis[x]+e[i].w;
				if(!vis[e[i].v])
				{
					vis[e[i].v] = true;
					q.push(e[i].v);
				}
			}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	memset(first, -1, sizeof(first));
	memset(nxt, -1, sizeof(nxt));
	for(int i = 0; i < m; i++)
	{
		int iu, iv, iw;
		cin >> iu >> iv >> iw;
		addEdge(iu, iv, iw);
		addEdge(iv, iu, iw);
	}
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0;
	for(int i = 0; i < k; i++)
	{
		int s, y;
		cin >> s >> y;
		dis[s] = min(dis[s], (long long)y);
	}
	/*
	for(int i = 2; i <= n; i++)
		cout << i << ' ' << dis[i] << '\n';
	*/
	SPFA(n);
	for(int i = 2; i <= n; i++)
	{
		//cout << i << ' ' << dis[i] << '\n';
		bool flag = false;
		for(int j = first[i]; j != -1; j = nxt[j])
			if(dis[e[j].v]+e[j].w == dis[i])
				flag = true;
		if(!flag) k--;
	}
	cout << k << '\n';
	return 0;
}