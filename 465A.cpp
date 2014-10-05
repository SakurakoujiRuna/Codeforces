#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	bool flag = true;
	for(int i = 0; i < s.size(); i++)
		if(flag)
		{
			if(s[i] == '0')
				flag = false;
			ans ++;
		}
	cout << ans << '\n';
	return 0;
}