#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	long long base = 1 ;
	int t;
	scanf("%d", &t);
	while(--t >= 0){
		long long n, m;
		scanf("%lld %lld", &n, &m);
		if(n > m ) printf("0\n");
		else if (n == 0){
			printf("%lld\n", m + 1 );
		}
		else{
			int msb = 31;
			while(!(m & (base << msb))){
				--msb;
			}
			// printf("msb: %d\n",msb );
			bool f = false;
			int last_zero = msb + 1;
			for(int i = msb; i > -1; --i){
				long long flag = base << i;
				// printf("%lld\n",flag );
				long long bn = n & flag;
				long long bm = m & flag;
				// printf("%lld %lld\n",bn, bm );
				if( !bm && bn ){
					f = true;
				}
				if(!bm){
					last_zero = i;
				}
				if(f){
					if(!bn &&  bm){
						m = m ^ flag;
					}
					else if(bn){
						m = m | flag;
					}
				}

			}
			if(!f){
				m = m | (base << last_zero);
				for(int i = last_zero - 1; i > -1; --i){
					long long flag = base << i;
					long long bn = n & flag;
					if(!bn){
						m = m ^ flag;
					}
					
				}
			}
			// printf("%lld\n",m );
			printf("%lld\n", (m ^ n) );
		}
	}

}

