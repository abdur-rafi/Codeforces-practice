#include <istream>
#include <cstring>
#include <vector>

using namespace std;
const int MAX = 200000 + 100;
char str[MAX];

int calc(int i, int j, vector<int> &onePos, int strLen){
	int ones = onePos.size();
	int val = 0;
	int mul = 1;
	int pr = i;
	int count = 0;
	int total = 0;
	// if(str[i] == '1') total = 1;

	for(int k = j; k  > -1; --k){

		// printf("here\n");

		for(int l = pr; l > onePos[k]; --l){
			mul *= 2;
			// total *= 2;
			if(mul > i + 1) return count;
		}
		pr = onePos[k];
		total += mul;
		// printf("total : %d\n",total );
		int nxtIndex = 0;
		if(k - 1 > -1)
			nxtIndex = onePos[k - 1] + 1;

		if( (i - onePos[k] + 1) <= total && i - nxtIndex + 1 >= total) ++count;

	}
	return count;
}
int main(){

	int _;
	scanf("%d", &_);
	while(_--){
		scanf("%s", str);
		int n = strlen(str);
		vector<int> onePos;
		for(int i = 0; i < n; ++i){
			if(str[i] == '1'){
				onePos.push_back(i);
			}
		}

		int iOnePos = onePos.size() - 1;
		int res = 0;
		for(int i = n -1 ; i > -1; --i){
			while(iOnePos > -1 && onePos[iOnePos] > i){
				--iOnePos;
			}

			res += calc(i, iOnePos, onePos, n);
			// printf("%d %d\n",res, iOnePos );

		}
			// res += calc(0, 0, onePos, n);
			// printf("%d\n",res );

		printf("%d\n",res );
	}

}