#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){
	int n;
	scanf("%d", &n);
	if(n == 1){
		int d;
		scanf("%d", &d);
		printf("%d\n",d );
		return 0;
	}
	ll sum = 0;
	ll mn = 1e10;
	bool pos = false;
	bool neg = false;
	for(int i = 0; i < n; ++i){
		ll d;
		scanf("%lld", &d);
		sum += abs(d);
		pos = pos || (d >= 0);
		neg = neg || (d < 0);
		mn = min(mn, abs(d));
	}
	if(!pos || !neg){
		printf("%lld\n", sum - 2 * mn );
	}
	else printf("%lld\n", sum);
}