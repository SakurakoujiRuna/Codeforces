#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

map <pair <int, vector <int> > , long long> M;
int icount[10];
int digitmod[23];
int m;

long long DP(vector<int> &V, int rem, int digits)
{
	if(M.find(make_pair(rem, V)) != M.end())
	{
		return M[make_pair(rem, V)];
	}
	else
	{
		M[make_pair(rem, V)] = 0;
		long long sum = 0;
		for(int i = 0; i < 10; i++)
			if(V[i])
			{
				V[i]--;
				sum += DP(V, (rem-digitmod[digits]*i%m+m)%m, digits+1);
				V[i]++;
			}
		//cout << M[make_pair(V, rem)] << '\n';
		return M[make_pair(rem, V)] = sum;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	long long n;
	cin >> n >> m;
	int digits = 0;
	memset(icount, 0, sizeof(icount));
	while(n)
	{
		icount[n%10]++;
		digits++;
		n /= 10;
	}
	digitmod[0] = 1%m;
	for(int i = 1; i < 23; i++)
		digitmod[i] = digitmod[i-1]*10 % m;

	M.clear();
	vector<int> V(10, 0);
	for(int i = 0; i < 10; i++)
	{
		V[i] = 1;
		for(int j = 0; j < m; j++)
			if(j == i*digitmod[digits-1]%m && i)
			{
				//cout << i << ' ' << j << '\n';
				M[make_pair(j, V)] = 1;
			}
			else M[make_pair(j, V)] = 0;
		V[i] = 0;
	}
	for(int i = 0; i < 10; i++)
		V[i] = icount[i];
	cout << DP(V, 0, 0) << '\n';
}