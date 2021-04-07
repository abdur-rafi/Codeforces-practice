#include<cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
const ll MAX = 300000 + 10;
ll a[MAX];
int main() {
	ll n,m,k; scanf("%lld %lld %lld", &n,&m, &k);
	loop(i, n, 0) {
		scanf("%lld", a + i);
	}
	ll sum = 0;
	ll mx = 0;
	ll length = 0;
	ll pre_sum = 0;
	ll pre_length = 0;
	loop(i, n, 0) {
		mx = max(mx, pre_sum);
		ll c = ceil((1.0 * (pre_length + 1)) / (1.0 * m)) ;
		ll curr = a[i] - k;
		ll b = c * k;
		pre_sum += a[i]-b;
		c = ceil((1.0 * (pre_length)) / (1.0 * m));
		pre_sum += c * k;
		pre_length++;
		printf("pre_sum:%lld\n", pre_sum);
		if (curr >= pre_sum) {
			pre_sum = curr;
			pre_length = 1;
			mx = max(mx, pre_sum);
		}
	}
	mx = max(mx, pre_sum);
	printf("%lld", mx);
	return 0;
}