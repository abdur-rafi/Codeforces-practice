#include <cstdio>

int main(){
	int f = -1, s = -1;
	int n, m, p;scanf("%d %d %d", &n, &m, &p);
	for(int i = 0; i < n; ++i){
		int a;scanf("%d", &a);
		if(f == -1 && a % p != 0) f = i;
	}
	for(int i = 0; i < m; ++i){
		int a;scanf("%d", &a);
		if(s == -1 && a % p != 0) s = i;
	}
	printf("%d\n",f + s );
}