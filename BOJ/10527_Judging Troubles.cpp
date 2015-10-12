#include <string>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int n;
	int ans = 0;
	cin >> n;
	multiset<string> a;
	
	for (int i = 0; i < n; i++)  {
		string tmp;
		cin >> tmp;
		a.insert(tmp);
	}
	for (int i = 0; i < n; i++) {
		
		string tmp;
		cin >> tmp;
		auto itor = a.lower_bound(tmp);
		if (itor != a.end() && *itor == tmp) {
			ans++;
			a.erase(itor);
		}
	}
	cout << ans << endl;
}