#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n; cin >> n;
	int last = -233;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int x; cin >> x;
		if(x)
		{
			if(last == i-1)
				ans++;
			else if(last == -233)
				ans++;
			else ans += 2;
			last = i;
		}
	}
	cout << ans << '\n';
	return 0;
}