#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int K = 20;
const int MOD = 1000000007;

int f[1<<K][K+1];
int pow2[1<<K];

bool count(int n)
{
	bool flag = false;
	for(int i = 0; i < 20; i++)
		if((n>>i)&1) flag = !flag;
	return flag;
}

int main()
{
	ios::sync_with_stdio(false);
	pow2[0] = 1;
	for(int i = 1; i < (1<<K); i++)
		pow2[i] = pow2[i-1]*2%MOD;
	int n; cin >> n;
	memset(f, 0, sizeof(f));
	for(int i = 0; i < n; i++)
	{
		int t; cin >> t;
		f[t][0]++;
	}
	for(int k = 0; k < 20; k++)
		for(int i = 0; i < (1<<20); i++)
			if((i>>k)&1)
				f[i][k+1] = f[i][k];
			else f[i][k+1] = f[i][k] + f[i|(1<<k)][k];
	long long ans = 0;
	for(int i = 0; i < (1<<20); i++)
		if(count(i))
			ans -= pow2[f[i][20]];
		else ans += pow2[f[i][20]];
	cout << (ans%MOD+MOD)%MOD << '\n';
	return 0;
}