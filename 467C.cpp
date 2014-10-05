#include <iostream>
#include <cstring>
using namespace std;

const int N = 5111;

long long sum[N];
long long f[N][N];
//long long g[N][N];

int main()
{
	ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	sum[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> sum[i];
		sum[i] += sum[i-1];
	}
	f[0][0] = 0;
	for(int i = 1; i <= k; i++)
		for(int j = 1; j <= n; j++)
		{
			f[j][i] = f[j-1][i];
			if(j >= m)
				f[j][i] = max(f[j][i], f[j-m][i-1] + sum[j] - sum[j-m]);
		}
	cout << f[n][k] << '\n';
	return 0;
}