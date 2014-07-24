#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int a, b, c;
	//cout << -1/5 << '\n';
	cin >> a >> b >> c;
	int d, e, f;
	cin >> d >> e >> f;
	int n; cin >> n;
	if(!(a+b+c)) a = -4;
	if(!(d+e+f)) d = -9;
	if((a+b+c-1)/5+1 + (d+e+f-1)/10+1 <= n)
		cout << "YES\n";
	else cout << "NO\n";
	return 0;
}