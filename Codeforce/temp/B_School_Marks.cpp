#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, k, p, upper, median;
	vector<int> ans;
	cin >> n >> k >> p >> upper >> median;
	vector<int> vi(k);
	for (int i = 0; i < k; i++) cin >> vi[i];
	sort(vi.begin(), vi.end());

	for (int i = k; i < n; i++){
		if (vi.size() == 0){
			vi.push_back(median);
			ans.push_back(median);
			continue;
		}
		int idx = i / 2;
		if (i % 2 == 0) idx--;
		if (idx == -1) idx = 0;
		if (vi[idx] < median){
			vi.push_back(median);
			ans.push_back(median);
		}
		else{
			vi.push_back(1);
			ans.push_back(1);
		}
		sort(vi.begin(), vi.end());
	}
	int ssum = 0;
	for (int i = 0; i < vi.size(); i++) ssum += vi[i];
	sort(vi.begin(), vi.end());
	if (ssum > upper || vi[n / 2] < median) cout << "-1" << endl;
	else{
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << endl;
	}
}