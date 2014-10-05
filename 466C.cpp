#include <iostream>
//#include <map>
//#include <algorithm>
#include <cstring>
using namespace std;

const int N = 611111;
int a[N];
int ileft[N];
int iright[N];

int main()
{
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	long long sum = 0;
	for(int i = 1; i <= n; i++)
		sum += a[i];
	if(sum % 3) cout << 0 << '\n';
	else
	{
		sum /= 3;
		long long tsum = a[1];
		memset(ileft, 0, sizeof(ileft));
		memset(iright, 0, sizeof(iright));
		for(int i = 2; i <= n; i++)
		{
			//ileft[i] = ileft[i-1];
			if(tsum == sum)
				ileft[i]++;
			tsum += a[i];
		}
		tsum = a[n];
		for(int i = n-1; i >= 1; i--)
		{
			iright[i] = iright[i+1];
			if(tsum == sum)
				iright[i]++;
			tsum += a[i];
		}
		long long ans = 0;
		for(int i = 2; i < n; i++)
			ans += (long long)ileft[i]*iright[i];
		cout << ans << '\n';
	}
	return 0;
}