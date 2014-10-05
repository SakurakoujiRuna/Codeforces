#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[1211];

int main()
{
	ios::sync_with_stdio(false);
	int n, k, d; cin >> n >> k >> d;
	int kk = k;
	bool flag = false;
	for(int i = 0; i < d; i++)
	{
		if(kk >= n)
		{
			flag = true;
			break;
		}
		kk *= k;
	}
	if(!flag)
		cout << -1 << '\n';
	else
	{
		a[1] = 1;
		int i;
		for(i = 2; i <= d && a[i-1] < n; ++i)
			a[i] = a[i-1]*k;
		for(; i <= d; ++i)
			a[i] = n;
		for(int i = 1; i <= d; ++i)
		{
			for(int j = 0; j < n; j++)
				cout << (j/a[i])%k+1 << ' ';
			cout << '\n';
		}
	}
	return 0;
}