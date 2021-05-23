#include <cstdio>

using namespace std;
typedef unsigned long long llu;

int main(){
	int t;scanf("%d", &t);
	while(--t>=0){
		llu n,m;
		scanf("%llu %llu", &n, &m);
		if(m == 0){
			printf("0\n");
			continue;
		}

		llu res = 0;

		if( n >= 2 * m){

			llu zeros = n - m;
			llu blockCount = m + 1;
			llu blockSize = zeros / blockCount;
			res += (zeros % blockCount) * ((blockSize + 2) * (blockSize + 1)) / 2 ;
			res += (blockCount - zeros % blockCount) * ((blockSize ) * (blockSize + 1)) / 2 ;
		}
		else{
			res = n - m;
		}

		res = n * (n + 1) / 2 - res;

		printf("%llu\n",res );
	}
}


