#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int digit(long long x)
{
	int ret = 0;
	while(x)
	{
		ret += x%10;
		x /= 10;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	long long a, b, c;
	cin >> a >> b >> c;
	vector <int> ans;
	for(long long sum = 1; sum < 100; sum++)
	{
		long long t = 1;
		for(int i = 1; i <= a; i++)
			t *= sum;
		t *= b;
		t += c;
		if(digit(t) == sum && t > 0 && t < (int)1e9)
			ans.push_back(t);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}