#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAX = 200000 + 100;
ll a[MAX],b[MAX];

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}

int main(){

	ll n,m;scanf("%lld %lld",&n,&m);

	for(int i = 0; i < n;++i){
		scanf("%lld",a+i);
	}
	for(int i = 0; i < m; ++i){
		scanf("%lld",b+i);
	}
	if(n == 1){
		for(int i = 0 ; i < m; ++i){
			printf("%lld ",b[i]+a[0]);
		}
		return 0;
	}

	sort(a, a+n);

	ll gcdWithoutFirst = a[1] - a[0];
	for(int i = 2; i < n;++i){
		gcdWithoutFirst = gcd(gcdWithoutFirst, a[i] - a[i-1]);
	}

	for(int i = 0 ; i < m; ++i){
		printf("%lld ",gcd(gcdWithoutFirst, a[0] + b[i]));
	}


	return 0;
}