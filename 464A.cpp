#include <iostream>
using namespace std;

/*
int length = 12;
int p = 3;

void check(string s)
{
	bool flag = true;
	for(int i = 0; i < s.size(); i++)
		for(int j = i+1; j < s.size(); j++)
		{
			bool tf = true;
			for(int k = i; k <= j; k++)
				if(s[k] != s[j-(k-i)])
					tf = false;
			if(tf) flag = false;
		}
	if(flag)
		cout << s << '\n';
}

void dfs(string s, int tl)
{
	if(!tl)
	{
		check(s);
		return;
	}
	for(char c = 'a'; c < 'a'+p; c++)
		dfs(s+c, tl-1);
}

int main()
{
	dfs("", length);
	return 0;
}

*/

int main()
{
	ios::sync_with_stdio(false);
	int n, p; cin >> n >> p;
	string s; cin >> s;

	
}