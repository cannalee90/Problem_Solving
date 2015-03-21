#include <iostream>
#include <fstream>
#include <string>
#include<queue>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int nst;
	int m;
	int tb;
	int to;
	int minb = 999999;
	int mino = 999999;
	cin >> nst >> m;
	for (int i = 0; i <m; i++)
	{
		cin >> tb >> to;
		if (minb > tb) minb = tb;
		if (mino > to) mino = to;
	}
	if (mino * 6 <= minb)
	{
		cout << nst * mino << endl;
	}
	else
	{
		if ((nst / 6 * minb) + minb < (nst / 6 * minb) + (nst % 6) * mino)
			cout << (nst / 6 * minb) + minb << endl;
		if ((nst / 6 * minb) + minb >= (nst / 6 * minb) + (nst % 6) * mino)
			cout << (nst / 6 * minb) + (nst % 6) * mino << endl;

	}
}