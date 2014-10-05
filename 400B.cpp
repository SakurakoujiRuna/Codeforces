#include <iostream>
#include <set>
using namespace std;

const int N = 2111;

//string s[N];
set <int> S;

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		int last = -1;
		for(int j = 0; j < m; j++)
			if(s[j] == 'G')
				last = j;
			else if(s[j] == 'S')
			{
				if(last == -1)
					S.insert(-1);
				else S.insert(j-last);
			}
	}
	if(S.find(-1) != S.end())
		cout << -1 << '\n';
	else cout << S.size() << '\n';
	return 0;
}