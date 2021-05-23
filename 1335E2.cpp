#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 200000 + 2;
const int A = 200 + 1;

int prefixSum[A][N];

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 1; i < A; ++i){
		prefixSum[i][0] = 0;
	}

	while(--t>=0){
		int n;
		scanf("%d", &n);
		int a[n];
		vector<vector<int>> adj(A);
		for(int i = 0; i <= n; ++i)
			for(int j = 0; j < A; ++j)
				prefixSum[j][i] = 0;

		for(int i = 0; i < n;++i){
			scanf("%d", a+i);
			prefixSum[a[i]][i+1] = 1 ;
			for(int j = 0; j < A; ++j)
				prefixSum[j][i + 1] += prefixSum[j][i];
			adj[a[i]].push_back(i);
		}
		int res = 0;
		for(int i = 0; i < A; ++i){
			int f = 0;
			int l = adj[i].size() - 1;
			while(f < l){
				int fi = adj[i][f];
				int li = adj[i][l];
				int c = 0;
				for(int j = 0; j < A; ++j){
					c = max(c, prefixSum[j][li] - prefixSum[j][fi+1]);
				}
				res = max(res, (2 * (f+1) + c));
				++f;
				--l;
			}
		}
		printf("%d\n",max(res, 1) );
	}
}

