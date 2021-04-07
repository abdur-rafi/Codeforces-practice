#include <cstdio>

using namespace std;
const int MX = 1010;
char number[MX];

int main(){
	int t;scanf("%d",&t);
	while(--t>=0){
		int n;scanf("%d",&n);
		scanf("%s",number);

		if(n % 2){
			bool oddF = false;
			for(int i = 0; i < n; i+= 2){
				if((number[i] - '0') % 2){
					oddF = true;
					break;
				}
			}
			if(!oddF){
				printf("2\n");
			}
			else{
				printf("1\n");
			}

		}
		else{
			bool evenF = false;
			for(int i = 1; i < n; i+= 2){
				if((number[i] - '0') % 2 == 0){
					evenF = true;
					break;
				}
			}
			if(evenF){
				printf("2\n");
			}
			else{
				printf("1\n");
			}
		}

	}

}