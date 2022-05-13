#include <cstdio>


using namespace std;

int main(){
	int v;
	scanf("%d", &v);
	int a[10];
	for(int i = 1; i < 10; ++i)
		scanf("%d", a + i);

	int minDigit = 1;
	int minPaint = a[minDigit];

	for(int i = 2; i < 10; ++i){

		if(minPaint >= a[i]){
			minPaint = a[i];
			minDigit = i;
		}
	}

	int c = v / minPaint;
	int rem = v - c * minPaint;

	if(c == 0){
		printf("-1\n");
		return 0;
	}

	char number[c + 1] = {'\0'};
	for(int i = 0; i < c; ++i){
		number[i] = '0' + minDigit;
		for(int j = 9; j > minDigit; --j){
			if(a[j] - a[minDigit] <= rem){
				rem -= a[j] - a[minDigit];
				number[i] = '0' + j;
				break;
			}
		}

	}

	printf("%s\n",number );


}