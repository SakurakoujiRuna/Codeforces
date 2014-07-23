#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	long long n, m, k;
	cin >> n >> m >> k;
	k += 2;
	if(k > n+m)
		cout << -1 << '\n';
	else
	{
		long long ans = 0;
		for(long long i = 1; i*i <= n; i++)
			if(i < k && i <= n && k-i <= m)
				ans = max(ans, (n/i)*(m/(k-i)));
		for(long long i = 1; i*i <= n; i++)
		{
			long long t = n/i;
			if(t >= k) t = k-1;
			if(t <= n && k-t <= m)
				ans = max(ans, (n/t)*(m/(k-t)));
		}
		cout << ans << '\n';
	}
	return 0;
}