#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int calc[26];

int main()
{
	ios::sync_with_stdio(false);
	string s, t; cin >> s >> t;
	memset(calc, 0, sizeof(calc));
	for(int i = 0; i < s.size(); i++)
		calc[s[i]-'a']++;
	for(int i = 0; i < t.size(); i++)
		calc[t[i]-'a']--;
	int p = 0;
	for(int i = 0; i < s.size(); i++)
		if(p < t.size() && s[i] == t[p]) p++;
	if(p == t.size())
		cout << "automaton\n";
	else
	{
		bool flagnegative = false, flagpositive = false;
		for(int i = 0; i < 26; i++)
			if(calc[i] < 0) flagnegative = true;
			else if(calc[i] > 0) flagpositive = true;

		if(flagnegative) cout << "need tree\n";
		else if(flagpositive) cout << "both\n";
		else cout << "array\n";
	}
	return 0;
}