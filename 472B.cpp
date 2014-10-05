#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2333;
int f[N];

int main()
{
	ios::sync_with_stdio(false);
	int n, k; cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> f[i];
	sort(f, f + n);
	int ans = 0;
	int last = 1;

	for(int i = 0; i < n; i++)
		if(i == 0 || f[i] != f[i - 1])
		{
			int people = n - i;
			if(people % k == 0)
				ans += (f[i] - last) * (people / k);
			else ans += (f[i] - last) * (people / k + 1);
			last = f[i];
		}
	cout << ans * 2 << '\n';
	return 0;
}