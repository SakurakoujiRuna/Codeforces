#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	ios :: sync_with_stdio(false);
	string s;
	cin >> s;
	bool flag = true;
	int count = 0;
	vector <int> ans;
	int lastCount = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '(')
		{
			count ++;
			lastCount ++;
		}
		else if(s[i] == ')')
		{
			count --;
			lastCount --;
		}
		else
		{
			count --;
			lastCount --;
			ans.push_back(1);

			lastCount = 0;
		}
		if(count < 0)
			flag = false;
	}

	if(lastCount > 0)
		flag = false;

	ans[ans.size() - 1] += count;

	if(!flag)
		cout << -1 << '\n';
	else
		for(int i = 0; i < ans.size(); i++)
			cout << ans[i] << '\n';
	return 0;
}