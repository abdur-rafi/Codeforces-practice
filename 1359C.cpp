#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;



class floatAsRatio{

	ll num, de;


public:

	floatAsRatio(ll a, ll b){
		ll g = gcd(a, b);
		num = a / g;
		de = b / g;
	}

	floatAsRatio add( floatAsRatio b){
		ll t1 = num * b.de + b.num * de;
		ll t2 = de * b.de;
		return floatAsRatio(t1, t2);
	}

	static ll gcd(ll a, ll b){
	    if (b == 0)
	        return a;
	    return gcd(b, a % b);
	     
	}

	floatAsRatio operator+(floatAsRatio b){
		return add(b);
	}

	floatAsRatio operator-(floatAsRatio b){
		floatAsRatio f2 = floatAsRatio(-b.num, b.de);
		return (*this) + f2; 
	}

	floatAsRatio absF(){
		return floatAsRatio(abs(num), abs(de));
	}

	void print(){
		printf("%lld / %lld\n",num, de );
	}
	bool isNeg(){
		return (num < 0 || de < 0);
	}
	bool operator>(floatAsRatio f){
		return !((*this - f).isNeg());
	}
	bool operator<(floatAsRatio f){
		return (*this - f).isNeg();
	}


};


int main(){
	// floatAsRatio a = floatAsRatio(1, 3);
	// floatAsRatio b = floatAsRatio(2, 3);
	// floatAsRatio f = a + b;
	// f.print();
	// printf("%lld", floatAsRatio::gcd(1, -2));
	int T;scanf("%d",&T);
	while(--T>=0){
		ll h, c, t;
		scanf("%lld %lld %lld", &h, &c, &t);
		ll i = 0;
		ll j = t;
		floatAsRatio f2 = floatAsRatio(t, 1);
		ll mid;
		while(i <= j){
			mid = (i + j) >> 1;
			floatAsRatio f = floatAsRatio(mid * (h + c) + h, 2 * mid + 1);
			floatAsRatio f3 = f - f2;
			if(f3.isNeg()){
				j = mid - 1;
			}
			else{
				i = mid + 1;
			}
		}
		--i;
		// printf("i : %lld\n", i);
		// ll c1 = i;
		// ll c2 = i - 1;
		// ll c3 = 2;
		floatAsRatio c1 = (floatAsRatio(i * (h + c) + h, 2 * i + 1) - f2).absF();
		floatAsRatio c2 = (floatAsRatio((i + 1) * (h + c) + h, 2 * (i + 1) + 1) - f2).absF();
		floatAsRatio c3 = (floatAsRatio(h + c , 2) - f2).absF();

		// c1.print();
		// c2.print();
		// c3.print();


		ll mni = i;
		floatAsRatio mn = c1;
		if((c2 - mn).isNeg()){
			mni = i + 1;
			mn = c2;
		}
		if((c3 - mn).isNeg()){
			printf("2\n");
			continue;
		}
		printf("%lld\n", mni * 2 + 1);
	}
}