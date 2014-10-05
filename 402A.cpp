#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int k, a, b, v;
	cin >> k >> a >> b >> v;
	if(a%v == 0)
		a /= v;
	else a = a/v + 1;
	int ans = 0;
	while(a > 0)
	{
		if(!b)
		{
			ans++;
			a--;
		}
		else if(b < k)
		{
			ans++;
			a -= b+1;
			b = 0;
		}
		else if(b >= k)
		{
			ans++;
			a -= k;
			b -= k-1;
		}
	}
	cout << ans << '\n';
	return 0;
}