#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 121111;

int num[N];
long long sum1[N];
long long sum2[N];

int main()
{
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> num[i];
	sum1[0] = 0;
	for(int i = 1; i <= n; i++)
		sum1[i] = sum1[i-1]+num[i];
	sort(num+1, num+n+1);
	sum2[0] = 0;
	for(int i = 1; i <= n; i++)
		sum2[i] = sum2[i-1]+num[i];

	int q; cin >> q;
	while(q--)
	{
		int type, l, r;
		cin >> type >> l >> r;
		if(type == 1)
			cout << sum1[r]-sum1[l-1] << '\n';
		else cout << sum2[r]-sum2[l-1] << '\n';
	}
	return 0;
}