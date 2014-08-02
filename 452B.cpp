#include <iostream>
#include <cmath>
using namespace std;

// 2sqrt(n^2 + (m-1)^2)
// sqrt(n^2 + m^2) + n

int main()
{
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	if(n == 0)
	{
		cout << "0 1\n";
		cout << "0 " << m << '\n';
		cout << "0 0\n";
		cout << "0 " << m-1 << '\n';
	}
	else if(m == 0)
	{
		cout << "1 0\n";
		cout << n << " 0\n";
		cout << "0 0\n";
		cout << n-1 << " 0\n";
	}
	else if (n == 1 && m == 1)
	{
		cout << "1 1\n";
		cout << "0 0\n";
		cout << "1 0\n";
		cout << "0 1\n";
	}
	else
	{
		/*
		double dis0 = sqrt(n*n+m*m) + 2*sqrt((n-1)*(n-1)+m*m) + sqrt((n-2)*(n-2) + m*m);
		double dis1 = sqrt(n*n+m*m) + 2*sqrt(n*n+(m-1)*(m-1)) + sqrt(n*n + (m-2)*(m-2));
		*/
		if(n > m)
		{
			//cout << 2*sqrt(n*n + (m-1)*(m-1)) << ' ' << sqrt(n*n + m*m) + n << '\n';
			if(2*sqrt(n*n + (m-1)*(m-1)) < sqrt(n*n + m*m) + n)
			{
				cout << "0 0\n";
				cout << n << ' ' << m << '\n';
				cout << 0 << ' ' << m << '\n';
				cout << n << ' ' << 0 << '\n';
				return 0;
			}
			cout << n << ' ' << m-1 << '\n';
			cout << "0 0\n";
			cout << n << ' ' << m << '\n';
			cout << "0 1" << '\n';
			/*
			if(m == 2)
				cout << n << ' ' << 0 << '\n';
			else
				cout << n << ' ' << m-1 << '\n';
			//cout << n-1 << ' ' << m << '\n';
			*/
		}
		else
		{

			if(2*sqrt(m*m + (n-1)*(n-1)) < sqrt(n*n + m*m) + m)
			{
				cout << "0 0\n";
				cout << n << ' ' << m << '\n';
				cout << n << ' ' << 0 << '\n';
				cout << 0 << ' ' << m << '\n';
				return 0;
			}

			cout << n-1 << ' ' << m << '\n';
			cout << "0 0\n";
			cout << n << ' ' << m << '\n';
			cout << "1 0\n";
			/*
			if(n == 2)
				cout << 0 << ' ' << m << '\n';
			else cout << n-1 << ' ' << m << '\n';
			//cout << n << ' ' << m-1 << '\n';
			*/
		}
	}
	return 0;
}