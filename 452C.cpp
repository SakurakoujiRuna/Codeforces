#include <iostream>
#include <cstdio>
using namespace std;

/*
 *(t/n)^2 * p(n, m, t)
 *m/(n*m) * (m-1)/(n*m-1) * ... * (m-t+1)/(n*m-t+1) * ... * C(n, t)
 * C(n, t) = n!/t!/(n-t)! 
 */

int main()
{
	//ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	if(n == 1)
	{
		cout << "1.00000000000000" << '\n';
		return 0;
	}
	else if(m == 1)
	{
		//cout << "0.00000000000000\n";
		printf("%.7f\n", 1.0/n);
		return 0;
	}
	long double ans = 0;
	long double t = 1;
	for(int i = 0; i < n; i++)
		t *= (long double)(n*m-m-i)/(n*m-i);
	//cout << t << '\n';
	for(int i = 1; i <= min(n, m); i++)
	{
		t *= (long double)(m-i+1);
		t /= (long double)(n*m-m-(n-i));
		t /= i;
		t *= (n-i+1);
		//cout << t << '\n';
		ans += ((long double)i/n)*((long double)i/n) * t;
	}
	//cout << ans*n << '\n';
	printf("%.8f\n", (double)(ans*n));
	return 0;
}