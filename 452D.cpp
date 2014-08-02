#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue <pair<int, int> > pq;

int main()
{
	ios::sync_with_stdio(false);
	int k, n1, n2, n3, t1, t2, t3;
	cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
	int t = 0;
	int k1 = k, k2 = 0, k3 = 0;
	for(int tt = 0; ;tt = -pq.top().first)
	{
		//cout << tt << '\n';
		while((!pq.empty()) && pq.top().first == -tt)
		{
			pair<int, int> p = pq.top();
			pq.pop();
			if(p.second == 1)
				k2++;
			else if(p.second == 2)
				k3++;
			else n3++;
		}
		while(n3 && k3)
		{
			n3--;
			k3--;
			n2++;
			pq.push(make_pair(-tt-t3, 3));
		}
		while(n2 && k2)
		{
			n2--;
			k2--;
			n1++;
			pq.push(make_pair(-tt-t2, 2));
		}
		while(n1 && k1)
		{
			n1--; k1--;
			pq.push(make_pair(-tt-t1, 1));
		}
		//cout << pq.top().first << '\n';


		if(pq.empty())
		{
			cout << tt << '\n';
			break;
		}
	}
	return 0;
}