#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

char op[128];
bool flip[2333];
int calc[2333];
int rcalc[2333];

int kmp(const string& s, const string& t, bool flag = false)
{
	int ans = 0;
	
	int n = t.size();
	vector<int> nxt(n+1, 0);
	for(int i = 1; i < n; i++)
	{
		int j = i;
		while(j > 0)
		{
			j = nxt[j];
			if(t[j] == t[i] || t[j] == op[t[i]])
			{
				nxt[i+1] = j+1;
				break;
			}
		}
	}
	int ret = 0;
	int m = s.size();
	for(int i = 0, j = 0; i < m; i++)
	{
		if(j < n && (s[i] == t[j] || s[i] == op[t[j]]))
			j++;
		else
			while(j > 0)
			{
				j = nxt[j];
				if(s[i] == t[j] || s[i] == op[t[j]])
				{
					j++;
					break;
				}
			}
		if(j == n)
		{
			//cout << s << ' ' << t << ' ' << i-n+1 << '\n';
			int pos = i-n+1;
			//cout << pos << '\n';
			int cc = 0;
			for(int i = pos; i < pos+n; i++)
				if(s[i] == op[t[i-pos]])
					cc++;
			ans = max(ans, cc);
		}
	}
	
	//return ret;
	
	
	//int n = s.size();
	//int m = t.size();
	
	/*
	if(n < 500)
		cout << s << ' ' << t << '\n';
	*/
	/*
	for(int i = 0; i <= n-m; i++)
	{
		bool flag = true;
		int cc = 0;
		for(int j = 0; j < m; j++)
			if(t[j] == op[s[i+j]])
				cc++;
			else if(t[j] != s[i+j])
				flag = false;
		if(flag) ans = max(ans, cc);
	}
	*/
	//cout << n << ' ' << m << '\n';
	//if(!flag) cout << s << ' ' << t << ' ' << ans << '\n';
	return ans;
	
}

string S, T;
void maintain(int n)
{
	if(flip[n])
	{
		for(int i = 0; i < 500; i++)
			S[n*500+i] = op[S[n*500+i]];
		flip[n] = false;
	}
	calc[n] = rcalc[n] = 0;
	string s = S.substr(n*500, 500);
	calc[n] = kmp(s, T, true);
	for(int i = 0; i < s.size(); i++)
		s[i] = op[s[i]];
	rcalc[n] = kmp(s, T, true);
}


int sum[121111];
int main()
{
	ios::sync_with_stdio(false);
	int m; cin >> m;
	cin >> T;
	cin >> S;
	while(S.size() % 500)
		S += '*';
	for(char tc = 'a'; tc <= 'z'; tc++)
	{
		op[tc] = tc + ('A'-'a');
		op[tc + ('A'-'a')] = tc;
	}
	op['*'] = '*';
	int n = S.size();
	int t = T.size();
	memset(flip, false, sizeof(flip));
	for(int i = 0; i < n/500; i++)
		maintain(i);
	//cout << S << ' ' << T << '\n';
	memset(sum, 0, sizeof(sum));
	for(int i = t; i <= n; i++)
	{
		sum[i] = sum[i-1];
		bool flag = true;
		for(int j = 0; j < t; j++)
			if(S[i-t+j] != T[j] && S[i-t+j] != op[T[j]])
				flag = false;
		if(flag) sum[i]++;
		//cout << i << ' ' << sum[i] << '\n';
	}

	while(m--)
	{
		int l, r;
		cin >> l >> r;
		//l--; r--;
		int ans = 0;
		if((l-1)/500 == (r-1)/500)
		{
			//cout << "***" << '\n';
			maintain((l-1)/500);
			//cout << S.substr(l-1, r-l+1) << '\n';
			ans = kmp(S.substr(l-1, r-l+1), T);
			//cout << S.substr(l-1, r-l+1) << ' ' << T << ' ' << ans << '\n';
			for(int i = l; i <= r; i++)
				S[i-1] = op[S[i-1]];
			maintain((l-1)/500);
		}
		else
		{	
			for(int i = 0; i < n/500; i++)
				if(l <= i*500+1 && r >= (i+1)*500)
					if(flip[i]) ans = max(ans, rcalc[i]);
					else ans = max(ans, calc[i]);
				else if(l >= i*500+1 && l <= (i+1)*500)
				{
					//cout << '!';
					maintain(i);
					ans = max(ans, kmp(S.substr(l-1, (i+1)*500-l+1), T));
				}
				else if(r >= i*500+1 && r <= (i+1)*500)
				{
					//cout << '@';
					maintain(i);
					ans = max(ans, kmp(S.substr(i*500, r-(i*500+1)+1), T));
				}
			for(int i = 1; i < n/500; i++)
			{
				int gapl = i*500-t+2;
				int gapr = i*500+t-1;
				//cout << gapl << ' ' << gapr << '\n';
				if(gapl <= l && gapr >= l)
					gapl = l;
				if(gapl <= r && gapr >= r)
					gapr = r;
				//cout << l << ' ' << r << ' ' << gapl << ' ' << gapr << '\n';
				if(gapl >= l && gapr <= r)
				{
					//cout << gapl << ' ' << gapr << '\n';
					string s = "";
					for(int i = gapl; i <= gapr; i++)
						if(flip[(i-1)/500])
							s += op[S[i-1]];
						else s += S[i-1];
					//cout << '#';
					ans = max(ans, kmp(s, T));
					//cout << gapl << ' ' << gapr << ' ' << kmp(s, T) << '\n';
				}

			}

			for(int i = 0; i < n/500; i++)
				if(l <= i*500+1 && r >= (i+1)*500)
					flip[i] = !flip[i];
				else if(l >= i*500+1 && l <= (i+1)*500)
				{
					for(int j = l; j <= (i+1)*500; j++)
						S[j-1] = op[S[j-1]];
					//cout << '$';
					maintain(i);
				}
				else if(r >= i*500+1 && r <= (i+1)*500)
				{
					for(int j = i*500+1; j <= r; j++)
						S[j-1] = op[S[j-1]];
					//cout << '%';
					maintain(i);
				}
		}
		int ans2 = 0;
		if(r-l+1 >= t)
			ans2 = sum[r] - sum[l+t-2];
		if(!ans2) cout << -1 << '\n';
		else cout << ans << '\n';
		//cout << S.substr(l-1, r-l+1) << ' ' << ans2 << ' ' << ans << '\n';
		/*
		if(!ans2) cout << -1 << '\n';
		else cout << ans2-ans << '\n';
		*/
	}
	return 0;
}