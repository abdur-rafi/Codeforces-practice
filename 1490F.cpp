#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MAX = 200000+100;

int inp[MAX];

int main(){

	int t;scanf("%d",&t);
	while(--t>=0){
		int n;scanf("%d",&n);
		for(int i=0;i< n;++i){
			scanf("%d",inp+i);
		}
		map<int,int> mp;
		for(int i = 0; i < n; ++i){
			mp[inp[i]]++;
		}

		// printf("frequencies: \n");

		// for(auto p : mp){
		// 	printf("%d %d\n",p.first,p.second);
		// }
		// printf("\n");

		vector<int> fr, prefixSum;

		for(auto p : mp){
			fr.push_back(p.second);
		}

		sort(fr.begin(),fr.end());

		int frSize = fr.size();

		// for(auto v : fr){
		// 	printf("%d ", v);
		// }
		// printf("\n");

		prefixSum.push_back(fr[0]);
		for(int i = 1; i < frSize ; ++i){
			prefixSum.push_back(prefixSum[i-1] + fr[i]);
		}

		// for(auto v : prefixSum){
		// 	printf("%d ", v);
		// }
		// printf("\n");

		long long mxDelete = 1e18;

		for(int i = 0; i < frSize ; ++i){
			int C = fr[i];
			long long cost = 0;
			cost += ( i > 0 ) ? prefixSum[i-1] : 0;
			cost += (prefixSum[frSize - 1] - prefixSum[i]) -  (frSize - i - 1) * C ;

			mxDelete = min(mxDelete , cost);

		}

		printf("%lld\n",mxDelete );


		// printf("%d\n",frSize );

	}

}