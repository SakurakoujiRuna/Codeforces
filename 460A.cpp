#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; ; i++)
	{
		if(!n)
		{
			cout << i-1 << '\n';
			break;
		}
		n--;
		if(i%m == 0)
			n++;
	}
	return 0;
}