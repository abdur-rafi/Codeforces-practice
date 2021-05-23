#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 1000000000 + 7;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1){
            res = (res % MOD) * (a % MOD);
            res %= MOD;
        }
        a = ((a % MOD) * (a % MOD)) % MOD;
        b >>= 1;
    }
    return res;
}

// long long binpow(long long a, long long b) {
//     if (b == 0)
//         return 1;
//     long long res = binpow(a, b / 2);
//     if (b % 2)
//         return ((((res % MOD) * (res % MOD)) % MOD) * (a % MOD)) % MOD;
//     else
//         return ((res % MOD) * (res % MOD)) % MOD;
// }

vector<ll> SieveOfEratosthenes(ll n){
    vector<bool> prime(n + 1, true);
 

    for (ll p = 2; p * p <= n; p++){
        if (prime[p] == true){
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    vector<ll> primes;
    for (ll p = 2; p <= n; p++)
        if (prime[p])
            primes.push_back(p);
    return primes;
}

int main(){
	// printf("%lld\n",binpow(2, 100) );
	ll x, n;
	scanf("%lld %lld", &x, &n);

	ll i;
	for(i = 1; i * i <= x; ++i)
		;
	ll to = i;
	
	auto primes = SieveOfEratosthenes(32000);

	vector<ll> primeDivisors;
	for(auto p: primes){
		bool f = false;
		while( x % p == 0){
			x /= p;
			f = true;
		}
		if(f)
			primeDivisors.push_back(p);
	}
	if(x > 1) primeDivisors.push_back(x);


	// for(auto div: primeDivisors)
	// 	printf("%lld\n",div );


	ll res = 1;

	for(auto p:primeDivisors){
		ll mul = p;
		while(true){
			// printf("%lld %lld\n",res, mul );
			ll fr = n / mul;
			ll frp = (binpow(p,fr)) % MOD;
			res = (res *  frp) % MOD; 
			if(fr <  p)
				break;

			mul *= p;

		}
	}
	printf("%lld\n",res );

	// for(auto p:primes)
	// 	printf("%lld\n",p );

}	

