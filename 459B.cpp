#include <iostream>
#include <cstdio>
using namespace std;

const int N = 221111;
typedef long long lli;

int num[N];

int main()
{
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 0; i < n; i++)
		cin >> num[i];
	int amin = 0x7f7f7f7f;
	int amax = 0;
	for(int i = 0; i < n; i++)
	{
		amin = min(amin, num[i]);
		amax = max(amax, num[i]);
	}
	lli cmin = 0;
	lli cmax = 0;
	for(int i = 0; i < n; i++)
	{
		if(amin == num[i])
			cmin++;
		if(amax == num[i])
			cmax++;
	}
	cout << amax-amin << ' ';
	if(amin == amax)
		cout << (lli)n*(n-1)/2;
	else cout << cmin*cmax;
	cout << '\n';
	return 0;
}