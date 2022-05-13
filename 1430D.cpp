#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 200000 + 100;

char str[MAX];

int delBack(int j){
	while(j > 0 && str[j] == str[j - 1])
		--j;
	return j-1;
}

int check(int j){
	while( j > 0 && str[j] != str[j-1])
		--j;
	if(j == 0) return -1;
	return j;
}

int count(bool del[], int j){
	int c = 0;
	while(j > -1)
		c += del[j--] == false ? 1 : 0;
	return c / 2 + c % 2;
}


int main(){
	int t;
	scanf("%d", &t);
	while(--t>=0){
		int n;
		scanf("%d", &n);
		scanf("%s", str);

		reverse(str, str+n);

		bool del[n] = {false};

		int j = n - 1;
		int res = 0;
		int right = j;

		// printf("%s\n",str );

		while(j > -1){
			// printf("j: %d right : %d\n", j, right );
			if(del[j]){
				--j;
				continue;
			}

			if(right >= j){
				right = check(j);
				if(right == -1){
					res += count(del, j);
					break;
				}
			}
			del[right] = true;

			j = delBack(j);

			++res;

			right = check(right - 1);

			if(right == -1){
				// printf("adsf\n");
				res += count(del, j);
				break;
			}
		}




		printf("%d\n",res );
	}
}




