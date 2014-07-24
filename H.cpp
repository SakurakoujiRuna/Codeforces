#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 121111;
typedef long long lli;
const lli MOD = 1000000007;

map<lli, map<lli, set<lli>* > > M[2];
set<lli>** p[N][2];

lli merge(set<lli>* s0, set<lli>* s1, int type)
{
	//cout << -*(s0->begin()) << ' ' << -*(s1->begin()) << '\n';
	if(s0->size() < s1->size())
	{
		lli t0 = *s0->begin();
		lli t1 = *s1->begin();
		s0->erase(t0);
		s1->erase(t1);
		s0->insert(t1);
		s1->insert(t0);
		swap(s0, s1);
	}
	for(set<lli>::iterator it = s1->begin(); it != s1->end(); it++)
	{
		if(it == s1->begin()) continue;
		s0->insert(*it);
		p[*it][type] = &s0;
	}
	//cout << -*((*p[4][0])->begin()) << ' ' << -*((*p[4][1])->begin()) << '\n';
	lli ret = -*(s1->begin());
	//cout << ret << '\n';
	return ret;
}

int main()
{
	int n;
	lli m;
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		lli x, y;
		scanf("%lld%lld", &x, &y);
		for(int j = 0; j < 2; j++)
		{
			if(M[j].find(x) == M[j].end())
				M[j][x] = *(new map<lli, set<lli>* >);
			if(M[j][x].find(y) == M[j][x].end())
			{
				M[j][x][y] = new set<lli>;
				M[j][x][y]->insert(-y);
			}
			M[j][x][y]->insert(i);
			p[i][j^1] = &M[j][x][y];
			//cout << i << ' ' << j << ' ' << (*(p[i][j^1]->begin())) << '\n';
			swap(x, y);
		}
	}
	lli ans = 0;
	int Q; scanf("%d", &Q);
	
	for(int x = 1; x <= n; x++)
		cout << x << ' ' << -*((*p[x][0])->begin()) << ' ' << -*((*p[x][1])->begin()) << '\n';
	
	while(Q--)
	{
		char type;
		scanf("%c%c", &type, &type);
		if(type != 'Q')
		{
			int x;
			lli d;
			scanf("%d%lld", &x, &d);
			x = x^ans;
			if(x > n) while(true);
			lli fx = -*((*p[x][0])->begin());
			lli fy = -*((*p[x][1])->begin());
			lli tx = fx;
			lli ty = fy;
			int dir = 0;
			if(type == 'U')
				tx -= d;
			else if(type == 'D')
				tx += d;
			else if(type == 'L')
			{
				ty -= d;
				dir = 1;
			}
			else
			{
				ty += d;
				dir = 1;
			}

			M[0][fx][fy]->erase(x);
			M[1][fy][fx]->erase(x);

			if(M[0].find(tx) == M[0].end())
				M[0][tx] = *(new map<lli, set<lli>* >);
			if(M[0][tx].find(ty) == M[0][tx].end())
			{
				M[0][tx][ty] = new set<lli>;
				M[0][tx][ty]->insert(-ty);
			}
			if(M[1].find(ty) == M[1].end())
				M[1][ty] = *(new map<lli, set<lli>* >);
			if(M[1][ty].find(tx) == M[1][ty].end())
			{
				M[1][ty][tx] = new set<lli>;
				M[1][ty][tx]->insert(-tx);
			}

			M[0][tx][ty]->insert(x);
			p[x][1] = &M[0][tx][ty];
			M[1][ty][tx]->insert(x);
			p[x][0] = &M[1][ty][tx];

			//cout << x << ' ' << -*(p[x][0]->begin()) << ' ' << -*(p[x][1]->begin()) << '\n';
		}

		else
		{
			int x;
			scanf("%d", &x);
			x = x^ans;
			if(x > n) while(true);
			ans = 0;
			lli tx = -*((*p[x][0])->begin());
			lli ty = -*((*p[x][1])->begin());
			//printf("%lld %lld\n", tx, ty);
			vector <pair<lli, lli> > V;
			for(map<lli, set<lli>* >::iterator it = M[0][tx].begin(); it != M[0][tx].end(); it++)
			{
				if(-*(it->second->begin()) != ty)
				{
					ans += ((it->second->size())-1)*(((-*(it->second->begin())-ty)%MOD*((-*(it->second->begin())-ty)%MOD))%MOD)%MOD;
					V.push_back(make_pair(tx, merge(*p[x][1], (it->second), 1)));
					merge(M[1][ty][tx], M[1][-*(it->second->begin())][tx], 0);
				}
			}
			//cout << ans << '\n';
			for(map<lli, set<lli>* >::iterator it = M[1][ty].begin(); it != M[1][ty].end(); it++)
			{
				if(-*(it->second->begin()) != tx)
				{
					//cout << -*(it->second->begin()) << '\n';
					ans += ((it->second->size())-1)*(((-*(it->second->begin())-tx)%MOD*((-*(it->second->begin())-tx)%MOD))%MOD)%MOD;
					V.push_back(make_pair(merge(*p[x][0], (it->second), 0), ty));
					//cout << -*((*p[4][0])->begin()) << ' ' << -*((*p[4][1])->begin()) << '\n'; 
					merge(M[0][tx][ty], M[0][-*(it->second->begin())][ty], 1);
					//cout << -*((*p[4][0])->begin()) << ' ' << -*((*p[4][1])->begin()) << '\n'; 
				}
			}

			for(int i = 0; i < V.size(); i++)
			{
				//cout << '*' << V[i].first << ' ' << V[i].second << '\n';
				M[0][V[i].first].erase(V[i].second);
				M[1][V[i].second].erase(V[i].first);
			}
			//cout << ans << '\n';
			ans = (ans%MOD+MOD)%MOD;
			printf("%lld\n", ans);
		}
		
		for(int x = 1; x <= n; x++)
			cout << x << ' ' << -*((*p[x][0])->begin()) << ' ' << -*((*p[x][1])->begin()) << '\n';
		
	}
}