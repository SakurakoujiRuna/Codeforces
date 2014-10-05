#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

const int N = 2111;
const int MOD = (int)(1e9+7);

int a[N];
long long f[N][N];

int main()
{
	ios::sync_with_stdio(false);
	int n, h;
	cin >> n >> h;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	//a[n+1] = h;
	memset(f, 0, sizeof(f));
	f[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == h)
		{
			f[i][0] = f[i-1][0];
		}
		else if(a[i] == h-1)
		{
			f[i][h-a[i]] = (f[i-1][h-a[i]]+f[i-1][h-a[i]-1]) % MOD;
			f[i][h-a[i]-1] = (f[i-1][h-a[i]]+f[i-1][h-a[i]-1]) % MOD;
		}
		else if(a[i] < h-1)
		{
			f[i][h-a[i]] = (f[i-1][h-a[i]]+f[i-1][h-a[i]-1]) % MOD;
			f[i][h-a[i]-1] = (f[i-1][h-a[i]]+f[i-1][h-a[i]-1]) % MOD;
		}
		//cout << i << ' ' << f[i][h-a[i]-1] << ' ' << f[i][h-a[i]] << '\n';
	}
	if(a[n] <= h)
		cout << f[n][0] << '\n';
	else
		cout << 0 << '\n';
	return 0;
}