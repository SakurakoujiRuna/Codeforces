#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

const int N = 1211111;

int num[N];
int cleft[N];
int cright[N];

struct BIT
{
	int b[N];
	BIT() { clear(); }
	void clear() { memset(b, 0, sizeof(b)); }
	int lowbit(int x) { return x&(-x); }
	void change(int pos, int x)
	{
		pos += 2;
		for(; pos < N; pos += lowbit(pos))
			b[pos] += x;
	}
	int query(int pos)
	{
		pos += 2;
		int ret = 0;
		for(; pos; pos -= lowbit(pos))
			ret += b[pos];
		return ret;
	}
}B;

int main()
{
	//cout << (0&(-0)) << '\n';
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> num[i];
	map<int, int> M;
	memset(cleft, 0, sizeof(cleft));
	memset(cright, 0, sizeof(cright));
	for(int i = 1; i <= n; i++)
	{
		if(M.find(num[i]) == M.end())
			M[num[i]] = 0;
		M[num[i]]++;
		cleft[i] = M[num[i]];
	}
	M.clear();
	for(int i = n; i >= 1; i--)
	{
		if(M.find(num[i]) == M.end())
			M[num[i]] = 0;
		M[num[i]]++;
		cright[i] = M[num[i]];
		B.change(cright[i], 1);
	}
	long long ans = 0;
	for(int i = 1; i < n; i++)
	{
		B.change(cright[i], -1);
		ans += B.query(cleft[i]-1);
	}
	cout << ans << '\n';
	return 0;
}