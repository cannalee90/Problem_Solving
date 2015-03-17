#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <climits>
#include <float.h>

typedef long long ll;

using namespace std;

vector<int > solution;
int ans = INT_MAX;
int ans_1, ans_2;
int n;

void binary_search_solution(int sol, int left, int right)
{
	int pivot = (left + right) / 2;
	if (ans > abs(sol + solution[pivot]))
	{
		ans = min(ans, abs(sol + solution[pivot]));
		ans_1 = sol;
		ans_2 = solution[pivot];
	}
	if (left == right) return;
	if (right == pivot) return;
	if (sol + solution[pivot] > 0 && pivot - 1 >= 0)
		binary_search_solution(sol, left, pivot - 1);
	if(sol + solution[pivot] < 0 && pivot + 1 < n)
		binary_search_solution(sol, pivot + 1, right);

}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t1;
		cin >> t1;
		solution.push_back(t1);
	}
	sort(solution.begin(), solution.end());
	for (int i = 0; i < n - 1; i++)
	{
		binary_search_solution(solution[i], i + 1, n - 1);
	}
	if (ans_2 < ans_1) swap(ans_1, ans_2);
	cout << ans_1 << " " << ans_2 << endl;
}
