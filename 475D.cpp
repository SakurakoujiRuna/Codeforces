#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

const int N = 121111;

int gcd(int a, int b)
{
	if(!b) return a;
	return gcd(b, a%b);
}

int igcd[N * 23][20];

int log2[N];

inline int segGcd(int left, int right)
{
	/*
	int ret = -1;
	for(int i = 18; i >= 0; i--)
		if(right - left >= (1 << i))
		{
			if(ret == -1)
				ret = igcd[left][i];
			else ret = gcd(igcd[left][i], ret);
			left += (1 << i);
		}
	return ret;
	*/

	//cout << left << ' ' << right << '\n';
	//cout << igcd[left][log2[right - left]] << ' ' << igcd[right - (1 << log2[right - left])][right - left] << '\n';

	return gcd(igcd[left][log2[right - left]], igcd[right - (1 << log2[right - left])][log2[right - left]]);
}

int main()
{
	ios::sync_with_stdio(false);

	for(int i = 1; i < N; i++)
	{
		for(int j = 20; j >= 0; j--)
			if((i >> j) & 1)
			{
				log2[i] = j;
				break;
			}
	}

	int n; cin >> n;
	for(int i = 0; i < n; i++)
		cin >> igcd[i][0];
	for(int j = 1; j < 18; j++)
		for(int i = 0; i < n; i++)
		{
			igcd[i][j] = gcd(igcd[i][j - 1], igcd[i + (1 << (j - 1))][j - 1]);
			//cout << i << ' ' << j << ' ' << igcd[i][j] << '\n';
		}

	map <int, long long> ans;

	for(int i = 0; i < n; i++)
	{
		//cout << '!' << i << '\n';
		int t = i;
		int tgcd = igcd[i][0];
		while(t < n)
		{
			int left = t;
			int right = n;
			while(left + 1 != right)
			{
				int mid = (left + right) >> 1;
				if(segGcd(i, mid + 1) != tgcd)
					right = mid;
				else left = mid;
			}
			if(ans.find(tgcd) == ans.end())
				ans[tgcd] = left - t + 1;
			else ans[tgcd] += left - t + 1;

			//cout << tgcd << ' ' << left - t + 1 << '\n';

			t = left + 1;
			tgcd = segGcd(i, left + 2);
			//cout << t << ' ' << tgcd << '\n';
		}
	}

	int q; cin >> q;
	while(q --)
	{
		int x;
		cin >> x;
		if(ans.find(x) == ans.end())
			ans[x] = 0;
		cout << ans[x] << '\n';
	}
	return 0;
}