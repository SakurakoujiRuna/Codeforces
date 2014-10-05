#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n; cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int p, q;
		cin >> p >> q;
		if(p <= q-2)
			ans++;
	}
	cout << ans << '\n';
}