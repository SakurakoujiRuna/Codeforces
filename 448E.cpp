#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int Nind = 0;
long long num[99999];

void print(long long X, int k, int &pnum)
{
	if(!pnum) return;
	if(!k)
	{
		cout << X << ' ';
		pnum--;
		return;
	}
	for(int i = 0; i < Nind && num[i] <= X; i++)
		if(!(X%num[i]) && k)
		{
			if(num[i] == 1 && pnum)
			{
				pnum--;
				cout << 1 << ' ';
			}
			else if(pnum)
				print(num[i], k-1, pnum);
			else break;
		}
}

int main()
{
	ios::sync_with_stdio(false);
	long long X, k;
	cin >> X >> k;
	for(long long i = 1; i*i <= X; i++)
		if(!(X%i))
		{
			num[Nind++] = i;
			if(X/i != i)
				num[Nind++] = X/i;
		}
	sort(num, num+Nind);
	//num[Nind++] = X;
	if(X == 1)
		cout << 1 << '\n';
	else if(k >= 100000)
	{
		for(int i = 0; i < 100000; i++)
			cout << 1 << ' ';
		cout << '\n';
	}
	else
	{
		int t = 100000;
		print(X, k, t);
		cout << '\n';
	}
	return 0;
}