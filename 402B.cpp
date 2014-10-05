#include <iostream>
using namespace std;

const int N = 1211;
int a[N];

int main()
{
	ios::sync_with_stdio(false);
	int n, k; cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int anspos = 0;
	int ansmin = 1233;
	for(int i = 1; i <= 1000; i++)
	{
		int tmin = 0;
		for(int j = 1; j <= n; j++)
			if(a[j] != (j-1)*k+i)
				tmin++;
		if(tmin < ansmin)
		{
			ansmin = tmin;
			anspos = i;
		}
	}
	cout << ansmin << '\n';
	for(int i = 1; i <= n; i++)
		if(a[i] != (i-1)*k+anspos)
			if(a[i] > (i-1)*k+anspos)
				cout << '-' << ' ' << i << ' ' << a[i] - ((i-1)*k+anspos) << '\n';
			else cout << '+' << ' ' << i << ' ' << (i-1)*k+anspos - a[i] << '\n';
	return 0;
}