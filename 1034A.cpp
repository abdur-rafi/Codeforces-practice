#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;

#define MAXN   15000001
 
int spf[MAXN];
void sieve(){
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
    for (int i=3; i*i<MAXN; i++){
        if (spf[i] == i){
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
set<int> getFactorization(int x){
    set<int> s;
    while (x != 1){
        s.insert(spf[x]);
        x = x / spf[x];
    }
    return s;
}
 


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

int _gcd(int a, int b){
    if (b==0)return a;
    return _gcd(b, a % b);   
}

int f[15000001];

int main(){
	int n;scanf("%d", &n);
	int a[n];
	int mx = -1;
	for(int i = 0; i < n; ++i){
		scanf("%d", a + i);
		mx = max(mx, a[i]);
	}

	sieve();

	int root = sqrt(mx);
	// printf("%d\n",root );
	// auto primes = SieveOfEratosthenes(root + 1);
	int gcd = a[0];
	for(int i = 1; i < n; ++i){
		gcd = _gcd(gcd, a[i]);
	}
	set<int> primesUsed;
	for(int i = 0; i < n; ++i){
		a[i] /= gcd;

		int curr = a[i];

		auto s = getFactorization(curr);
		for(auto v : s){
			f[v]++;
			primesUsed.insert(v);
		}

		// for(auto v : primes){
		// 	if(curr == 1) break;
		// 	if(curr % v == 0){
		// 		primesUsed.insert(v);
		// 		f[v]++;
		// 	}
		// 	while(curr % v == 0){
		// 		curr /= v;
		// 	}
		// }
		// if(curr > 1){
		// 	f[curr]++;
		// 	primesUsed.insert(curr);
		// }
	}

	mx = 0;

	for(auto v : primesUsed){
		mx = max(mx, f[v]);
	}
	if(mx == 0) printf("-1\n");
	else printf("%d\n",n - mx );

}