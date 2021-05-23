#include <cstdio>
using namespace std;
typedef unsigned long long ull;

int main(){
	int t;
	scanf("%d", &t);
	int c = 63;

	while(--t>=0){
		ull l, r;
		ull one = 1;
		scanf("%llu %llu", &l, &r);
		ull lA = l, rA = r;
		for(int i = 0; i < c; ++i){
			ull mask = ( one << i);
			ull temp = l;
			temp = temp | mask;
			if(temp <= rA){
				l = temp | mask;
			}
		}
		printf("%llu\n",l );
	}
}

