#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;
const int MXLEN = 200000 + 100;

int main(){

	ll n, t;
	scanf("%lld %lld", &n, &t);

	char grade[MXLEN];

	scanf("%s", grade);


	int radixIndex = -1;
	int greaterThan4Index = -1;
	
	for(int i = 0; i < n; ++i){
		
		if(radixIndex != -1 && grade[i] > '4'){
			greaterThan4Index = i;
			break;
		}

		if(grade[i] == '.'){
			radixIndex = i;
		}
	}	


	if(greaterThan4Index == -1){
		printf("%s\n", grade);
		return 0;
	}
	bool carry = false;

	int j = greaterThan4Index - 1;


	while(j > radixIndex && t){
		grade[j]++;
		--t; 
		grade[j + 1] = 0;
		if(grade[j] <= '4'){
			break;
		}
		--j;

	}

	if(grade[radixIndex + 1] > '4' && t){
		grade[radixIndex] = 0;
		carry = true;
		for(int i = radixIndex - 1; i > -1;--i){
			if(grade[i] == '9'){
				grade[i] = '0';
				carry = true;
			}
			else{
				grade[i]++;
				carry = false;
				break;
			}
		}
	}

	if(carry) printf("1");
	printf("%s\n",grade );

}