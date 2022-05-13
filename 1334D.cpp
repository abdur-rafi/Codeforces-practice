#include <cstdio>
typedef long long ll;
int main(){
	int t;scanf("%d",  &t);
	while( --t >= 0){
		ll n, l, r;scanf("%lld %lld %lld", &n, &l, &r);
		ll c = 0;
		for(ll i = 1; i < n ; ++i){
			ll to = c + 2 * (n - i);
			if(to < l){
				c = to; 
				continue;
			}
			for(ll j = i + 1; j <= n; ++j){
				if(c >= l - 1 && c < r){
					printf("%lld ",i );
				}
				++c;
				if(c >= l - 1 && c < r){
					printf("%lld ",j );
				}
				++c;
				if( c > r) break;
			}
			if( c > r) break;
		}
		if(c < r) printf("1 ");
		printf("\n");
	}
}