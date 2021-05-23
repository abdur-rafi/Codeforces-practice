#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

bool check(char a[], char b[],int as,int ae,int bs, int be){
	int n = ae - as + 1;
	if(n % 2){
		int eq = true;
		for(int i = 0; i < n; ++i){
			eq &= (a[as + i] == b[bs + i]);
		}
		return eq;
	}
	bool eq = check(a,b,as,(as + n / 2 - 1),bs,(bs + n / 2 - 1));
	eq &= check(a,b,(as + n / 2 ),ae,(bs + n / 2 ),be);
	if(eq) return true;
	eq = check(a,b,as,(as + n / 2 - 1),(bs + n / 2 ),be);
	eq &= check(a,b,(as + n / 2 ),ae,bs,(bs + n / 2 - 1));
	return eq;
}

const int MAX = 200000 + 100; 

int main(){
	char a[MAX], b[MAX];
	scanf("%s %s", a, b);
	int n = strlen(a);

	bool pos = check(a,b,0,n-1,0,n-1);
	if(pos)
		printf("YES\n");
	else printf("NO\n"); 
	// printf("%s %s\n",a,b );
}