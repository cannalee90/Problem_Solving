#include <iostream>
#include <functional>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <limits.h>

typedef long long ll;
using namespace std;

int n, m;



int main()
{
#ifdef _CONSOLE
	freopen("\input.txt", "r", stdin);
#endif
	int t;
	int sauron[7] = { 1, 2, 2, 2, 3, 5, 10 };
	int gandalf[6] = {1,2,3,3,4,10 };
	int caseNumber = 0;
	cin >> t;
	while (t--){
		caseNumber++;
		ll gan_a = 0, sau_a = 0;
		for (int i = 0; i < 6; i++){
			ll t1;
			cin >> t1;
			gan_a += t1 * gandalf[i];
		}
		for (int i = 0; i < 7; i++){
			ll t1;
			cin >> t1;
			sau_a += t1 * sauron[i];
		}
		if (gan_a > sau_a)
			printf("Battle %d: Good triumphs over Evil\n", caseNumber);
		else if (sau_a > gan_a)
			printf("Battle %d: Evil eradicates all trace of Good\n", caseNumber);
		else
			printf("Battle %d: No victor on this battle field\n", caseNumber);

	}
}