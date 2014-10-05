#include <iostream>
using namespace std;

const int N = 23;
int a[N];

int main()
{
	ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i <= m; i++)
		cin >> a[i];
	int ans = 0;
	for(int i = 0; i < m; i++)
	{
		int t = 0;
		for(int j = 0; j < n; j++)
			if(((a[i]>>j)&1) != ((a[m]>>j)&1))
				t++;
		if(t <= k) ans++;
	}
	cout << ans << '\n';
	return 0;
}