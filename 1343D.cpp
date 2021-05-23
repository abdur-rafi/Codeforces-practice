#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

vector<pii> calcRanges(int a[],int n, int k){
	vector<pii> res;
	for(int i = 0; i < n; ++i){
		int li = i;
		int ri = 2 * n - i - 1;
		int s = a[li] + a[ri];
		int mx = max(a[li], a[ri]);
		int mn = s - mx;
		int mxR = s - mn + k;
		int mnR = s - mx + 1;
		res.push_back({mnR, mxR});

	}
	return res;
}

int calcRes(vector<pii> ranges, int k,int n, int a[]){
	// printf("%d\n", ranges.size());
	// for(auto r : ranges){
	// 	printf("r: %d %d\n",r.first, r.second );
	// }
	int mpSum[2 * k + 10];
	for(int i = 0; i <= 2 * k; ++i){
		mpSum[i] = 0;
	}
	for(int i = 0; i < n; ++i){
		int li = i;
		int ri = 2 * n - i - 1;
		int s = a[li] + a[ri];
		mpSum[s]++;
		// printf("%d\n", s);
	}
	int mp[2 * k + 10];
	for(int i = 0; i <= 2 * k; ++i){
		mp[i] = 0 ;
	}
	int c = 0;
	int mxc = 0;
	int mnCost = 2 * ranges.size();
	for(auto v : ranges){
		mp[v.first]++;
		mp[v.second + 1]--; 
	}
	for(int i = 0; i <= 2 * k ; ++i){
		c += mp[i];
		int cost = c + 2 * (n - c);
		cost -= mpSum[i];
		mnCost = min(mnCost, cost);
	}
	return mnCost;
}

int main(){
	int t;
	scanf("%d", &t);
	while(--t>=0){
		int n, k;
		scanf("%d %d", &n , &k);
		n /= 2 ;
		int a[2 * n + 10];
		for(int i = 0; i < 2 * n; ++i){
			scanf("%d", a+i);
		}
		int res = calcRes(calcRanges(a,n,k), k, n, a);
		printf("%d\n",res );

	}
}