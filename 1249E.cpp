#include <cstdio>

using namespace std;

const int N = 2 * (1e5) + 100;
int weights[2][N];
int weightsSum[2][N];
int res[N];

int main(){

	int n, c;
	scanf("%d %d", &n, &c);

	for(int i = 0; i < n - 1; ++i){
		scanf("%d", &weights[0][i]);
		weightsSum[0][i+1] = weights[0][i] + weightsSum[0][i];
	}

	for(int i = 0; i < n - 1; ++i){
		scanf("%d", &weights[1][i]);
		weightsSum[1][i+1] = weights[1][i] + weightsSum[1][i];
	}

	// for(int i = 0; i < n; ++i) printf("%d\n", weightsSum[1][i] );

	res[0] = 0;
	int curr = 0;
	int mode = 0;

	curr = weights[1][0] + c;
	mode = 1;

	if(curr > weights[0][0]){
		curr = weights[0][0];
		mode = 0;
	}
	res[1] = curr;

	int last[2] = {0};

	// last = floor

	for(int i = 1; i < n - 1; ++i){
		int prev = curr;
		curr = prev + weights[mode][i];
		int lstMode = (mode + 1 ) % 2;
		int lstIndex = last[lstMode];
		int nxtMode = mode;

		if(mode == 0){
			if(res[lstIndex] + weightsSum[1][i + 1] - weightsSum[1][lstIndex] + (lstIndex == 0 ? c : 0)  <= curr){
				curr = res[lstIndex] + weightsSum[1][i + 1] - weightsSum[1][lstIndex] + (lstIndex == 0 ? c : 0);
				nxtMode = 1;
			}
			if(prev + weights[1][i] + c <= curr){
				curr = prev + weights[1][i] + c;
				last[1] = i + 1;
				nxtMode = 1;
			}
		}
		else{
			if(res[lstIndex] + weightsSum[0][i + 1] - weightsSum[0][lstIndex] < curr){
				curr = res[lstIndex] + weightsSum[0][i + 1] - weightsSum[0][lstIndex];
				nxtMode = 0;
			}
			if(prev + weights[0][i] < curr){
				curr = prev + weights[0][i];
				last[0] = i + 1;
				nxtMode = 0 ;
			}
		}

		res[i + 1] = curr;
		mode = nxtMode;
	}

	for(int i = 0; i < n; ++i) printf("%d ",res[i] );

	
}