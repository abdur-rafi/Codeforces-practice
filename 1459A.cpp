#include <cstdio>
using namespace std;

const int N = 1001;
char n1[N], n2[N];

int main(){
	int t;
	scanf("%d",&t);
	while(--t>=0){
		int n;
		scanf("%d",&n);
		scanf("%s",n1);
		scanf("%s",n2);
		int rc = 0;
		int re = 0;
		int bc = 0;
		for(int i = 0 ; i < n;++i){
			if(n1[i] == n2[i]){
				re++;
			}
			else if(n1[i] > n2[i]){
				rc++;
			}
			else{
				bc++;
			}
		}
		if(rc > bc){
			printf("RED\n");
		}
		else if(rc == bc){
			printf("EQUAL\n");
		}
		else{
			printf("BLUE\n");
		}
	}
}