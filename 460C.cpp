#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 221111;

struct BIT
{
	int b[N];
	BIT() { clear(); }
	void clear() { memset(b, 0, sizeof(b)); }
	int lowbit(int x) { return x&(-x); }
	void change(int pos, int x)
	{
		for(int i = pos; i < N; i += lowbit(i))
			b[i] += x;
	}
	int query(int pos)
	{
		int ret = 0;
		for(int i = pos; i > 0; i -= lowbit(i))
			ret += b[i];
		return ret;
	}
}B;

int a[N];

int main()
{
	ios::sync_with_stdio(false);
	int n, m, w;
	cin >> n >> m >> w;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int left = 0, right = 1100010001;
	while(left+1 < right)
	{
		int mid = (left+right)>>1;
		B.clear();
		long long change = 0;
		for(int i = 1; i <= n; i++)
		{
			int watered = B.query(i);
			if(watered+a[i] < mid)
			{
				change += mid-a[i]-watered;
				B.change(i, mid-a[i]-watered);
				B.change(i+w, -(mid-a[i]-watered));
			}
		}
		if(change > m)
			right = mid;
		else left = mid;
	}
	cout << left << '\n';
	return 0;
}