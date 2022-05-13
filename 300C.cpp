#include <cstdio>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;


ull power(ull x,ull y,ull p){
    ull res = 1;
    x = x % p;
    while (y > 0){
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
ull modInverse(ull n,ull p){
    return power(n, p - 2, p);
} 
 
ull nCrModPFermat(ull n,ull r, ull p, ull fac[]){
    if (n < r)
        return 0;
    if (r == 0)
        return 1; 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}


const ull p = 1000000007;

int main(){

	ull a, b, n;
	scanf("%llu %llu %llu", &a, &b, &n);
	ull fact[n + 1];
	fact[0] = 1;
	for(ull i = 1; i <= n; ++i){
		fact[i] = (fact[i-1] * i) % p;
	}

	ull res = 0;
	for(int i = 0; i <= n; ++i){
		ull digitSum = i * a + (n - i) * b;
		// printf("%llu\n",digitSum );
		bool ok = true;
		while(digitSum){
			if((digitSum % 10 == a) || (digitSum % 10  == b)){
				
			}
			else{
				ok = false;
				break;
			}
			digitSum /= 10;
		}
		if(!ok) continue;
		ull t = nCrModPFermat(n, i, p, fact);
		// printf("%llu\n",t );
		// t = (t * t) % p;
		res = (res + t) % p;
	}
	printf("%llu\n",res );
}