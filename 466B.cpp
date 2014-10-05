#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	long long n, a, b;
	cin >> n >> a >> b;
	n *= 6;
	if(a*b >= n)
	{
		cout << a*b << '\n';
		cout << a << ' ' << b << '\n';
	}
	else
	{
		if(a > b)
			swap(a, b);
	}
}