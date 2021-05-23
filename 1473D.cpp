#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;


int solve(char str[], bool plus, int n, int m, pair<int,int> pairs[], int res[]){
	int pre[n], post[n], toNumber[n] , preMax[n], postMax[n];
	for(int i = 0 ; i < n; ++i){
		if(str[i] == '+'){
			if(plus){
				toNumber[i] = 1;
			}
			else{
				toNumber[i] = -1;
			}
		}
		else{
			if(plus){
				toNumber[i] = -1;
			}
			else{
				toNumber[i] = 1;
			}
		}
	}

	int s = 0 ; 
	preMax[0] = 0;

	for(int i = 0 ; i < n; ++i){
		s += toNumber[i];
		if(s <= 0){
			pre[i] = 0;
			s = 0;
		}
		else{
			pre[i] = s;
		}
		if(i == 0){
			preMax[0] = pre[0];
		}
		else{
			preMax[i] = max(pre[i], preMax[i-1]);
		}
	}
	s = 0;
	for(int i = n-1; i >= 0; --i){
		s += toNumber[i];
		if(s <= 0){
			post[i] = 0;
			s = 0;
		}
		else{
			post[i] = s;
		}
		if(i == n-1){
			postMax[i] = post[i];
		}
		else{
			postMax[i] = max(post[i], postMax[i+1]);
		}
	}



	// for(int i = 0 ; i < n ; ++i){
	// 	printf("pre[%d] : %d  post[%d] : %d \n", i , pre[i], i , post[i] );
	// }

	// for(int i = 0 ; i < n; ++i){
	// 	printf("preMax[%d] : %d postMax[%d] : %d\n",i,preMax[i],i,postMax[i] );
	// }
	// for(int i = 0 ; i < n; ++i) printf("%d ",toNumber[i] );


	for(int i = 0 ; i < m; ++i){
		int li = pairs[i].first - 1;
		int ri = pairs[i].second - 1;
		if(li == 0 && ri == n-1){
			res[i] = 1;
		}
		else if(li == 0){
			res[i] = postMax[ri+1] + 1;
		}
		else if(ri == n-1){
			res[i] = preMax[li - 1] + 1;
		}
		else{
			res[i] = preMax[li - 1] + 1;
			res[i] = max(res[i], postMax[ri + 1] + 1);
			res[i] = max(res[i], pre[li - 1] + post[ri + 1] + 1);
		}
	}
	// for(int i = 0 ; i < m; ++i){
	// 	printf("res[%d] : %d\n",i , res[i] );
	// }


	return 1;
}

int main(){

	int t;
	scanf("%d",&t);
	while(--t>=0){
		int n, m;
		scanf("%d %d", &n, &m);
		char str[n + 10];
		scanf("%s",str);
		pair<int,int> pairs[m];
		for(int i = 0 ; i < m; ++i){
			scanf("%d %d", &pairs[i].first, &pairs[i].second);
		}
		int resP[m];
		int resM[m];
		solve(str, false, n, m , pairs,resP);
		solve(str, true, n , m , pairs, resM);
		for(int i = 0 ; i < m; ++i){
			printf("%d\n",max(resM[i], resP[i]) );
		}

	}

}