#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>

using namespace std;
typedef pair<int , int> pii;
const int MAX = 200000 + 10;
vector<int> adj[2 * MAX];
vector<int> dp[2 * MAX];


int calc(int i, int j){
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	vector<int> &next = adj[i+1];
	int val = adj[i][j];
	int res;
	int l = 0, r = next.size() - 1;
	if(r == -1){
		res = 0;
	}
	else{
		int mid;
		while(l <= r){
			mid = (l + r) >> 1;
			if(next[mid] < val){
				l = mid + 1;
			}
			else{
				r = mid - 1;
			}
		}
		int index = r + 1;
		// printf("index: %d\n",index );
		if(index >= next.size()){
			res = 0;
		}
		else{
			res = calc(i + 1, index);
		}
	}

	dp[i][j] = 1 + res;
	return dp[i][j];
}

int main(){
	// printf("hello");
	int n;
	scanf("%d",&n);
	vector<pii> a;
	for(int i = 0; i < n ; ++i){
		int b;
		scanf("%d", &b);
		a.push_back({b, i});
	}
	sort(a.begin(), a.end());
	int i = 0, c = 0;
	vector<int> temp;
	while(i < n){
		temp.clear();
		int j = i;
		temp.push_back(a[i].second);
		while((i + 1) < n && a[i+1].first == a[i].first){
			++i;
			temp.push_back(a[i].second);

		}
		if(j - 1 > -1 && (a[j-1].first+1) != a[j].first)
			++c;
		adj[c++] = temp;
		++i;
	}
	for(int i = 0 ; i < c; ++i){
		dp[i] = vector<int>(adj[i].size(), -1);
	}

	// for(int i = 0; i  < c; ++i){
	// 	for(int j = 0; j < adj[i].size(); ++j){
	// 		printf("%d ", adj[i][j]);
	// 	}
	// 	printf("\n");
	// }

	int mx = 0;
	pii mxi = {-1, -1};
	for(int i = 0; i  < c; ++i){
		for(int j = 0; j < adj[i].size(); ++j){
			int r = calc(i , j);
			if(r > mx){
				mx = r;
				mxi = {i, j};
			}
		}
	}

	i = mxi.first;
	int j = mxi.second;

	vector<int> res(mx);
	res[0] = adj[i][j];

	for(int k = 0; k < (mx - 1); ++k){
		vector<int> &next = adj[i+1];
		int val = adj[i][j];
		int l = 0, r = next.size() - 1;
		int mid;
		while(l <= r){
			mid = (l + r) >> 1;
			if(next[mid] < val){
				l = mid + 1;
			}
			else{
				r = mid - 1;
			}
		}
		int index = r + 1;
		res[k + 1] = next[index];
		i++;
		j = index;
	}

	printf("%d\n", mx);
	// printf("%d %d\n", mxi.first, mxi.second);
	for(int i = 0; i < res.size(); ++i){
		printf("%d ", res[i] + 1);
	}


}