#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};


int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int a[n];
	for(int i = 0; i < n ;++i) scanf("%d", a + i);

	// pii queries[m];

	// for(int i = 0; i < m; ++i){
	// 	int b, c;
	// 	scanf("%d %d", &b, &c);
	// 	--b;
	// 	--c;
	// 	queries[i] = {b, c};
	// }

	vector<int> adj[n + 1];
	for(int i = 0; i < n; ++i){
		if(a[i] > n) continue;
		adj[a[i]].push_back(i);
	}

	// sort(queries, queries + m);

	vector<int> startFlags(n, 0), endFlags(n, 0);
	for(auto v : adj[1]){
		startFlags[v] = endFlags[v] = 1;
	}

	for(int i = 2; i <= n; ++i){
		int window = i;
		int currSize = adj[i].size();
		for(int j = 0; j + window - 1 < currSize; ++j){
			int i1, i2;

			if(j == 0) i1 = 0;
			else i1 = adj[i][j-1] + 1;

			if(j + window < currSize)
				i2 = adj[i][j + window] - 1;
			else i2 = n - 1;

			startFlags[i1] += 1;
			endFlags[i2] += 1;
		}

	}

	FenwickTree intervalStart(startFlags), intervalEnd(endFlags);


	for(int i = 0; i < m; ++i){
		int b, c;
		scanf("%d %d", &b, &c);
		--b;
		--c;
		if(b == c){
			if(a[b] == 1) printf("1\n");
			else printf("0\n");
		}
		else{
			int s1 = intervalStart.sum(b);
			int s2 = intervalStart.sum(c - 1) - s1;
			int e1 = intervalEnd.sum(b);
			int e2 = intervalEnd.sum(c - 1) - e1;
			printf("%d\n", s1 - s2 + e2 - e1 );
			printf("%d %d %d %d\n",s1, e1, s2, e2 );
		}

	}

	// printf("%d\n",intervalEnd.sum(n - 1) );

	// for(auto v : startFlags) printf("%d\n",v );

	// for(auto v : queries) printf("%d %d\n",v.first, v.second );

}