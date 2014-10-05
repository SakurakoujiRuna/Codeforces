#include <iostream>
#include <algorithm>
using namespace std;

const int N = 4111;
pair <int, int> p[N];

int main()
{
	ios::sync_with_stdio(false);
	int x, k;
	cin >> x >> k;
	x--;
	int minmiss = 0;
	int maxmiss = 0;
	int last = 0;

	for(int i = 0; i < k; i++)
	{
		int type;
		cin >> type;
		if(type == 1)
			cin >> p[i].first >> p[i].second;
		else
		{
			cin >> p[i].first;
			p[i].second = p[i].first;
		}
	}
	sort(p, p+k);

	for(int i = 0; i < k; i++)
	{
		int type;
		//cin >> type;
		if(p[i].first == p[i].second)
			type = 2;
		else type = 1;
		if(type == 1)
		{
			int r2, r1;
			//cin >> r2 >> r1;
			r2 = p[i].first;
			r1 = p[i].second;
			int t = (r2-last-1);
			last = r1;
			maxmiss += t;
			if(t&1)
				minmiss += t/2+1;
			else minmiss += t/2;
		}
		else if(type == 2)
		{
			int r;
			//cin >> r;
			r = p[i].first;
			int t = (r-last-1);
			last = r;
			maxmiss += t;
			if(t&1)
				minmiss += t/2+1;
			else minmiss += t/2;
		}
	}
	int t = x-last;
	maxmiss += t;
	if(t&1)
		minmiss += t/2+1;
	else minmiss += t/2;
	cout << minmiss << ' ' << maxmiss << '\n';
	return 0;
}