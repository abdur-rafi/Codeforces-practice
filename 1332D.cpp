#include <iostream>

int main(){
	int k;
	scanf("%d", &k);
	int c = 0;
	for(int i = 0; i < 20; ++i){
		if((1<<i) & k)
			c = i + 1;
	}
	int power = 1 << c;
	int s = power + k;
	printf("3 3\n");
	printf("%d %d %d\n", s, s, power );
	printf("%d %d %d\n",power, k, s );
	printf("%d %d %d\n",power, s, k );

}