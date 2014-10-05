#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, x; cin >> n >> x;
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		int t; cin >> t;
		sum += t;
	}
	if(sum < 0)
		sum = -sum;
	if(sum % x)
		sum = sum/x + 1;
	else sum /= x;
	cout << sum << '\n';
	return 0;
}