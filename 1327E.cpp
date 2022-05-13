#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

const ll MOD = 998244353 ;

int main(){

	ll n;
	scanf("%lld", &n);

	if(n == 1) printf("10\n");
	else if(n == 2) printf("180 10\n");
	else{
		ll res[n + 1];
		res[n] = 10;
		res[n-1] = 180;
		ll p = 1;
		for(ll i = 2; n - i > 0; ++i){
			res[n-i] = ((9 * p * 10 * 2 + 81 * p * (i - 1)) * 10) % MOD;
			p *= 10;
			p %= MOD;
		}
		for(int i = 1; i <= n; ++i) printf("%lld ",res[i] );
	}
 
}