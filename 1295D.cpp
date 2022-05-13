#include <cstdio>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;


vector<int> SieveOfEratosthenes(int n){
    vector<bool> prime(n + 1, true);
    
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 	vector<int> primes;

    for (int p = 2; p <= n; p++)
        if (prime[p])
        	primes.push_back(p);

    return primes;
}

ll _gcd(ll a, ll b){
    if (b==0)return a;
    return _gcd(b, a % b);   
}


int main(){
	ll base = 1;
	int t;scanf("%d", &t);
	auto primes = SieveOfEratosthenes((1e5) + 1);
	while(--t >= 0){

		ll a, m;
		scanf("%lld %lld", &a, &m);
		ll gcd = _gcd(a, m);
		// m /= gcd;
		set<ll> primeDivisors;
		ll curr = m / gcd;
		for(auto v : primes){
			if(curr % v == 0){
				primeDivisors.insert(v);
			}
			while(curr % v == 0) curr /= v;
		}
		if(curr > 1) primeDivisors.insert(curr);
		// for(auto v : primeDivisors)
		vector<ll> divisors(primeDivisors.begin(), primeDivisors.end());

		// for(auto v : divisors) printf("%lld\n",v );

		int n = divisors.size();
		int upto = 1 << n;

		vector<ll> b[n + 1];

		bool zero = false;

		for(int i = 1; i < upto; ++i){
			ll c = 0;
			ll mul = 1;
			for(int j = 0; j < n; ++j){
				ll mask = base << j;
				if( mask & i){
					++c;
					mul *= divisors[j];
				}
			}
			// if(mul == gcd){
			// 	zero = true;
			// 	break;
			// }
			b[c].push_back(mul);
		}
		// if(zero){
		// 	printf("1\n");
		// 	continue;
		// }

		// printf("%d\n",n );

		ll d = a + m - 1;
		ll res1 = 0;
		ll res2 = 0;
		for(int i = 1; i <= n ; ++i){
			ll mul = (i % 2 == 1) ? 1 : -1;
			for(auto v : b[i]){
				// printf("%lld\n",gcd );
				res1 = res1 + mul * (d / (v * gcd));
				res2 = res2 + mul * (a - 1L) / (v * gcd);
			}
		}
		// printf("%lld %lld\n",res1, res2 );
		res1 = (a + m - 1L) / gcd - res1;
		res2 = (a - 1L) / gcd - res2;
		printf("%lld\n",res1 - res2 );
	}

	
}