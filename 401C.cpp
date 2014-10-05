#include <iostream>
#include <cstring>
using namespace std;

const int N = 1211111;
int put1[N];

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	if(m > (n+1)*2 || m < n-1)
	{
		cout << -1 << '\n';
	}
	else
	{
		//minput1[0] = minput1[n] = 0;
		for(int i = 1; i < n; i++)
		{
			put1[i] = 1;
			m--;
		}
		put1[0] = put1[n] = 0;
		for(int i = 0; i <= n; i++)
			if(m)
			{
				put1[i]++;
				m--;
			}
		if(m) { put1[0]++; m--; } 
		if(m) put1[n]++;
		for(int i = 0; i <= n; i++)
		{
			for(int j = 0; j < put1[i]; j++)
				cout << '1';
			if(i != n) cout << '0';
		}
		cout << '\n';
	}
	return 0;
}