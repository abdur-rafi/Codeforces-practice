#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 5010;
int n;
int a[MAX];
long long c[MAX];
long long res = 0 ;

int main(){

	int t;
	scanf("%d",&t);
	while(--t>=0){
		scanf("%d",&n);
		for(int i = 0 ; i < n; ++i){
			scanf("%d",a+i);
		}

		res = 0;
		for(int i = 0 ; i < n; ++i){
			c[i] = 0;
		}
		int i = -1;
		while( i+1 < n && a[i+1] == 1){
			++i;
		}
		i = i == -1 ? 0 : i;
		for(;i < n;++i){
			if(i == n-1){
				res += a[i] - 1;
				c[i] = max((long long)0,c[i] - a[i] + 1);
				res += c[i];
				break;
			}
			int out = n - i - 1;
			if(a[i] > out){
				int rem = a[i] - out;
				res += rem;
				a[i] = out;
				c[i] = max((long long)0, c[i] - rem);
			}
			for(int j = a[i]; j > 1; --j){
				c[i + j]++;
			}
			c[i] = max((long long)0,c[i] - a[i] + 1);
			if(c[i]){
				c[i+1] += c[i];
			}
		}
		
		printf("%lld\n",res );

	}

}