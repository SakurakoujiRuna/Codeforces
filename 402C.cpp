#include <iostream>
#include <cstring>
using namespace std;

const int N = 26;
bool vis[N][N];

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	while(T--)
	{
		int n, p;
		cin >> n >> p;
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < n; i++)
		{
			vis[i][(i+1)%n] = vis[(i+1)%n][i] = true;
			vis[i][(i+2)%n] = vis[(i+2)%n][i] = true;
		}
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++)
				if(p && !vis[i][j])
				{
					vis[i][j] = true;
					p--;
				}
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++)
				if(vis[i][j])
					cout << i+1 << ' ' << j+1 << '\n';
	}
	return 0;
}