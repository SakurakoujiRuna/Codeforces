#include <iostream>
#include <set>
using namespace std;

int main()
{
	//ios::sync_with_stdio(false);
	multiset <int> S;
	S.insert(1); S.insert(1);
	S.erase(S.find(1));
	
	return 0;
}