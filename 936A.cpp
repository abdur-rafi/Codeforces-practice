#include <cstdio>

using namespace std;
typedef long long ll;

template <typename t>
class fraction {

	t numerator;
	t denominator;

	t gcd;

	t __gcd(t a, t b){
	    if(b==0) return a;
	    return __gcd(b, a % b);   
	}

public:
	fraction(t n, t d){
		this->gcd = __gcd(n, d);
		this->numerator = n / gcd;
		this->denominator = d / gcd;
	}

	t num(){
		return numerator;
	}

	t denom(){
		return denominator;
	}


	fraction operator*(fraction f){
		fraction tmp(numerator * f.numerator, denominator * f.denominator);
		return tmp;
	}
	fraction operator*(t v){
		fraction tmp(numerator * v, denominator);
		return tmp;
		
	}
	fraction operator+(t v){
		fraction tmp(v, 1);
		return this->operator+(tmp);
	}

	template <typename T>
	friend fraction operator+(fraction<T> &f1, fraction<T> &f2);

};

template <typename t>
fraction operator+(fraction<t> &f1, fraction<t> &f2){
		fraction tmp(f1.numerator * f2.denominator + f1.denominator * f2.numerator, f2.denominator * f1.denominator);
		return tmp;
}

int main(){
	ll k, d, t;
	scanf("%lld %lld %lld", &k, &d, &t);

	fraction<int> f(5, 10);

	ll r = k / d + (k % d ? 1 : 0);

	fraction<ll> cookedPortionInRDs = fraction<ll>(1, t) * k  + fraction<ll>(1, 2* t) * (r * d - k); 


	ll noOfRCycles = cookedPortionInRDs.denom() / cookedPortionInRDs.num();
	fraction<ll> notCooked = cookedPortionInRDs + (-1);


	printf("%lld\n",noOfRCycles );


	// ll l = 0;
	// ll h = (1e18) + 100;
	// ll mid;
	// while(l <= h){
	// 	mid = (l + h ) >> 1;

	// }

	printf("%lld / %lld\n",notCooked.num(), notCooked.denom() );


	printf("%lld / %lld\n",cookedPortionInRDs.num(), cookedPortionInRDs.denom() );

}
