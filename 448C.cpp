#include <iostream>
#include <cstdio>
using namespace std;

const int N = 5111;
const int INF = 0x3f3f3f3f;
int a[N];

int paint(int l, int r, int painted)
{
	int low = INF;
	for(int i = l; i < r; i++)
		low = min(low, a[i]);
	int ret = low-painted;
	int last = l;
	for(int i = l; i < r; i++)
		if(a[i] == low)
		{
			if(last != i)
				ret += paint(last, i, low);
			last = i+1;
		}
	if(last != r)
		ret += paint(last, r, low);
	//cout << l << ' ' << r << ' ' << ret << '\n';
	return min(ret, r-l);
}

int main()
{
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	cout << paint(0, n, 0) << '\n';
	return 0;
}