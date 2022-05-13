#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

int main(){
	ll A, B, C, D;
	scanf("%lld %lld %lld %lld", &A, &B, &C, &D);
	ll res = 0;

	for(int i = A; i <= B; ++i){
		ll x = i;
		ll y = B;
		if(C > x + y - 1){
			y = C + 1 - x ;
		}

		if(D > x + y - 1){
			
			// else{

				ll d = D - (x + y - 1);
				d = min(d, C - y );
				res += (x + y - C) * (d + 1) + (d * (d + 1)) / 2;
				res += (C - y - d) * (D - C + 1);
			// } 
		}
		else{
			res += (C - y + 1) * (D - C + 1);
		}

	}
	printf("%lld\n",res );

}