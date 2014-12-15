#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 121111;
const int MOD = 1000000007;
bool flag[N];
char a[N];
char b[N];
int n, m;
int p[N];

inline void KMP()
{
	int j = 0; p[1] = 0;
	for(int i = 2; i <= m; i++)
	{
		while(j && b[i] != b[j+1])
			j = p[j];
		if(b[i] == b[j+1]) j++;
		p[i] = j;
	}
	j = 0;
	for(int i = 1; i <= n; i++)
	{
		while(j && a[i] != b[j + 1])
			j = p[j];
		if(a[i] == b[j+1]) j++;
		if(j == m)
		{
			flag[i] = true;
		}
	}
}

long long f[N];
long long sum[N];
long long sSum[N];

int main()
{
	ios :: sync_with_stdio(false);
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	n = strlen(a + 1);
	m = strlen(b + 1);
	KMP();

	f[0] = 0;
	sum[0] = 0;
	sSum[0] = 0;
	int last = -1;
	for(int i = 1; i <= n; i++)
	{
		if(flag[i])
		{
			if(last != -1)
				f[i] = f[i - 1] + sSum[i - m] - sSum[last] + (i - m - last);
			else
				f[i] = f[i - 1] + sSum[i - m] + (i - m - last);
			sum[i] = f[i] + sum[i - 1];
			sSum[i] = sSum[i - 1] + sum[i];
			sum[i] %= MOD;
			sSum[i] %= MOD;
			last = i - m;
		}
		else
		{
			f[i] = f[i - 1];
			sum[i] = sum[i - 1] + f[i];
			sSum[i] = sSum[i - 1] + sum[i];
			sum[i] %= MOD;
			sSum[i] %= MOD;
		}

		//cout << f[i] << ' ' << sum[i] << ' ' << sSum[i] << '\n';
	}

	cout << (sum[n] + MOD) % MOD << '\n';
	return 0;
}