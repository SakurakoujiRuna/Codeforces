#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	int ans = 0x3f3f3f3f;
	for(int i = 0; i <= 1000; i++)
		if(i*m >= n)
			ans = min(ans, i*b);
		else ans = min(ans, i*b + a*(n - i*m));
	cout << ans << '\n';
	return 0;
}