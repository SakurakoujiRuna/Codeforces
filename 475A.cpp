#include <iostream>
using namespace std;

string s[] = {
	"+------------------------+",
	"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
	"|#.#.#.#.#.#.#.#.#.#.#.|.|",
	"|#.......................|",
	"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
	"+------------------------+"
};

int main()
{
	ios::sync_with_stdio(false);
	int k; cin >> k;
	for(int i = 0; i < 233; i++)
		for(int j = 0; j < 6; j++)
			if(s[j].size() > i && s[j][i] == '#' && k)
			{
				k --;
				s[j][i] = 'O';
			}

	for(int i = 0; i < 6; i++)
		cout << s[i] << '\n';
	return 0;

}