#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string ans[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main()
{
	ios::sync_with_stdio(false);
	int n; cin >> n;
	string s; cin >> s;
	for(int i = 0; i < 8; i++)
		if(ans[i].size() == n)
		{
			bool flag = true;
			for(int j = 0; j < n; j++)
				if(s[j] == '.' || s[j] == ans[i][j]) {}
			else flag = false;
			if(flag) cout << ans[i] << '\n';
		}
	return 0;
}