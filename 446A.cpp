#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int N = 121111;
int num[N];
int f[N], g[N];

int main()
{
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> num[i];
	num[0] = 0x3f3f3f3f;
	num[n+1] = -1;

	f[0] = f[n+1] = 0;
	g[0] = g[n+1] = 0;
	for(int i = 1; i <= n; i++)
		if(num[i] > num[i-1])
			f[i] = f[i-1]+1;
		else f[i] = 1;
	for(int i = n; i >= 1; i--)
		if(num[i] < num[i+1])
			g[i] = g[i+1]+1;
		else g[i] = 1;

	int ans = 0;
	for(int i = 1; i <= n; i++)
		if(num[i+1]-num[i-1] > 1)
			ans = max(ans, f[i-1]+g[i+1]+1);
		else ans = max(ans, max(f[i-1], g[i+1])+1);

	cout << ans << '\n';
	return 0;
}
