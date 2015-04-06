#include<cstdio>

typedef long long ll;
using namespace std;

ll ride[10001];
ll n, m;

ll get_cus(ll &time){
	ll total_cus = 0;
	for (int i = 0; i < m; i++)
		total_cus += time / ride[i];
	return total_cus;
}

int main(){
	ll mmax = -1;
	ll mmax_cus;
	ll left = 0, right = 60000000000;
	ll num_cus;
	ll time;

	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < m; ++i)
		scanf("%lld", &ride[i]);
	n -= m;

	if (n <= 0){	
		printf("%d\n", n);
		return 0;
	}

	while (left <= right){
		time = (left + right) / 2;
		num_cus = get_cus(time);
		if (num_cus >= n){
			right = time - 1;
		}
		else{
			left = time + 1;
			if (time > mmax){
				mmax = time;
				mmax_cus = num_cus;
			}
		}
	}

	for (int i = 0; i < m; ++i){
		if (mmax % ride[i] == ride[i] - 1)
			mmax_cus++;
		if (mmax_cus == n){
			printf("%d\n", i + 1);
			return 0;
		}
	}

}