#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

struct DS
{
	map <string, string> p;
	DS() { p.clear(); }
	string& find(string& s)
	{
		if(p.find(s) == p.end())
			p[s] = s;
		if(p[s] == s)
			return s;
		else return p[s] = find(p[s]);
	}
	bool query(string& s1, string &s2)
	{
		if(p.find(s1) == p.end())
			p[s1] = s1;
		if(p.find(s2) == p.end())
			p[s2] = s2;
		return p[s1] == p[s2];
	}
	void merge(string &s1, string &s2)
	{
		if(p.find(s1) == p.end())
			p[s1] = s1;
		if(p.find(s2) == p.end())
			p[s2] = s2;
		int r1 = 0;
		int r2 = 0;
		for(int i = 0; i < s1.size(); i++)
			if(s1[i] == 'r') r1++;
		for(int i = 0; i < s2.size(); i++)
			if(s2[i] == 'r') r2++;
		if(r1 < r2 || ((r1 == r2) && s1.size() < s2.size()))
			p[s2] = find(s1);
		else p[s1] = find(s2);
	}
}A;

const int N = 121111;
string essay[N];
void normal(string &s)
{
	for(int i = 0; i < s.size(); i++)
		if(s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] - 'A' + 'a';
}

int main()
{
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> essay[i];
		normal(essay[i]);
	}
	int m; cin >> m;
	for(int i = 0; i < m; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		normal(s1);
		normal(s2);
		if(!A.query(s1, s2))
			A.merge(s1, s2);
	}
	for(int i = 0; i < n; i++)
		essay[i] = A.find(essay[i]);
	int ans1 = 0;
	int ans2 = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < essay[i].size(); j++)
			if(essay[i][j] == 'r')
				ans1++;
		ans2 += essay[i].size();
		cout << essay[i] << ' ';
	}
	cout << '\n';
	cout << ans1 << ' ' << ans2 << '\n';
	return 0;
}