#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	int x, y, z, p;
	cin >> n >> m;
	cin >> x >> y >> z >> p;
	x %= 4; z %= 4; y %= 2;
	while(p--)
	{
		int tn = n;
		int tm = m;
		int xk, yk;
		cin >> xk >> yk;
		for(int i = 0; i < x; i++)
		{
			int t = xk;
			xk = yk;
			yk = tn-t+1;
			swap(tn, tm);
		}
		if(y)
		{
			yk = tm-yk+1;
		}
		for(int i = 0; i < z; i++)
		{
			int t = yk;
			yk = xk;
			xk = tm-t+1;
			swap(tn, tm);
		}
		cout << xk << ' ' << yk << '\n';
	}
	return 0;
}