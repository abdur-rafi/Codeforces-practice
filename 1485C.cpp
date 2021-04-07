#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

int main(){

	int t;scanf("%d",&t);
	while(--t>=0){
		ll x, y;
		scanf("%lld %lld",&x,&y);
		if(x < 3 || y < 2){
			printf("0\n");
			continue;
		}
		ll kMax;
		ll i = 0;
		for(; i * i <= x ; ++i){
			;
		}
		kMax = i - 1;
		ll res = 0;
		// printf("kMax :  %lld \n",kMax );
		for(ll k = 1; k <= kMax; ++k){
			ll bMin = k + 1;
			ll bMax = y;
			if(bMax < bMin) break;
			ll aMin = k * k + 2 * k;
			ll aMax = k * (y + 1);
			if(aMax <= x){
				res += bMax - bMin + 1;
				continue;
			}
			bMax = (x - k) / k;
			res += max(bMax - bMin + 1, 0LL);
		}
		printf("%lld\n", res);
	}
}