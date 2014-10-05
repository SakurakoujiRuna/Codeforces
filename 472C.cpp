#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map <string, int> m;

const int N = 233333;
pair <string, string> pp[N];
pair <int, int> p[N];

int main()
{
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> pp[i].first >> pp[i].second;
		m[pp[i].first] = m[pp[i].second] = 233;
	}
	int Mind = 0;
	for(map <string, int> :: iterator it = m.begin(); it != m.end(); it++)
		m[it->first] = Mind ++;
	for(int i = 0; i < n; i++)
	{
		p[i].first = m[pp[i].first];
		p[i].second = m[pp[i].second];
	}
	bool flag = true;
	int last = -233;

	for(int i = 0; i < n; i++)
	{
		//cout << last << '\n';
		int t; cin >> t; t --;
		//cout << last << ' ' << p[t].first << ' ' << p[t].second << '\n';
		if(p[t].first > last && p[t].second > last)
			last = min(p[t].first, p[t].second);
		else if(p[t].first > last)
			last = p[t].first;
		else if(p[t].second > last)
			last = p[t].second;
		else flag = false;
	}
	if(flag) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}