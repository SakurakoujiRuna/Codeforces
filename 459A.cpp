#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if(x1 == x2 && y1 != y2)
	{
		int t = abs(y2-y1);
		cout << x1+t << ' ' << y1 << ' ' << x2+t << ' ' << y2 << '\n';
	}
	else if(y1 == y2 && x1 != x2)
	{
		int t = abs(x2-x1);
		cout << x1 << ' ' << y1+t << ' ' << x2 << ' ' << y2+t << '\n';
	}
	else
	{
		int dx = abs(x1-x2);
		int dy = abs(y1-y2);
		if(dx != dy)
			cout << -1 << '\n';
		else cout << x1 << ' ' << y2 << ' ' << x2 << ' ' << y1 << '\n';
	}
	return 0;
}