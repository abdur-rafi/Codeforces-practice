#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int calculateToMax(char str[], int dp[][2], bool toRight, int i, bool turn){
	if(dp[i][turn] != -1){
		return dp[turn][i];
	}
	if(toRight){
		if( i == n){
			dp[i][turn] = 1;
			return 1;
		}
	}
	else{
		if(i == 0){
			dp[i][turn] = 1;
			return 1;
		}
	}
	int fromNext;
	if(toRight){
		fromNext = calculateToMax(str,dp, toRight, i + 1, !turn);
		if(!turn && str[i] == 'R'){
			dp[i][turn] = 1 + fromNext;
		}
		else if(turn && str[i] == 'L'){
			dp[i][turn] = 1 + fromNext;
		}
		else{
			dp[i][turn] = 1;
		}
	}
	else{
		fromNext = calculateToMax(str,dp, toRight, i - 1, !turn);
		if(!turn && str[i - 1] == 'L'){
			dp[i][turn] = 1 + fromNext;
		}
		else if(turn && str[i - 1] == 'R'){
			dp[i][turn] = 1 + fromNext;
		}
		else{
			dp[i][turn] = 1;
		}
	}
	return dp[i][turn];
}

int main(){

	int t;
	scanf("%d", &t);
	while(--t>=0){
		scanf("%d", &n);
		char str[n+10];
		scanf("%s", str);
		int dpToRightMax[n + 1][2], dpToLeftMax[n + 1][2];
		for(int i = 0 ; i <= n; ++i){
			dpToLeftMax[i][0] = -1;
			dpToLeftMax[i][1] = -1;
			dpToRightMax[i][0] = -1;
			dpToRightMax[i][1] = -1;
		}
		for(int i = 0 ; i <= n; ++i){
			if(dpToRightMax[i][0] == -1){
				calculateToMax(str, dpToRightMax , true, i, 0);
			}
		}
		for(int i = n ; i >= 0; --i){
			if(dpToLeftMax[i][0] == -1){
				calculateToMax(str, dpToLeftMax, false, i , 0);
			}
		}
		// for(int i = 0 ; i <= n; ++i){
		// 	// printf("dpR[%d][%d] : %d dpR[%d][%d] : %d \n", 0, i , dpToRightMax[i][0], 1, i, dpToRightMax[i][1]);
		// 	// printf("dpL[%d][%d] : %d dpL[%d][%d] : %d \n", 0, i , dpToLeftMax[i][0], 1, i, dpToLeftMax[i][1]);
		// }
		for(int i = 0 ; i <= n;++i){
			int mxR = dpToRightMax[i][0];
			int mxL = dpToLeftMax[i][0];
			int r = max(mxR, mxL);
			// mxR = mxR % 2 ? (mxR - 1) : mxR;
			// mxL = mxL % 2 ? (mxL - 1) : mxL;
			// mxR = max(mxR, 0);
			// mxL = max(mxL , 0);
			// printf("%d %d\n",mxL, mxR );
			r = max(r, mxR + mxL - 1);
			printf("%d ",r );
		}
		printf("\n");

	}

}