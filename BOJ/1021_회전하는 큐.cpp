n#include <iostream>
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
#include <deque>

typedef long long ll;
using namespace std;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	int ans = 0;
	cin >> n >> m;
	deque<int> series;
	deque<int> data;
	for (int i = 0; i < n; i++)	{
		series.push_back(i + 1);
	}
	for (int i = 0; i < m; i++)	{
		int t1;
		cin >> t1;
		data.push_back(t1);
	}
	while (m){

		int seek = data.front();
		deque<int> second = series;
		deque<int> third = series;
		int cnt_second = 0;
		int cnt_third = 0;

		while (second.front() != seek){
			cnt_second++;
			second.push_back(second.front());
			second.pop_front();
		}
		while (third.front() != seek){
			cnt_third++;
			third.push_front(third.back());
			third.pop_back();
		}
		if (cnt_second < cnt_third){
			ans += cnt_second;
			series = second;
		}else if (cnt_third <= cnt_second){
			ans += cnt_third;
			series = third;
		}
		m--;
		series.pop_front();
		data.pop_front();
	}
	cout << ans << endl;
}
