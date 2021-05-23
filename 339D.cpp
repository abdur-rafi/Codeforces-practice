#include <cstdio>
#include <vector>

using namespace std;

void buildTree(vector<int> adj[], int level, int p){
	if(level == p ) return;
	int h = adj[level].size() / 2;
	for(int i = 0; i < h; ++i){
		int l = adj[level][2 * i];
		int r = adj[level][2 * i + 1];
		int pVal = 0;
		if(level % 2){
			pVal = l ^ r;
		}
		else{
			pVal = l | r;
		}
		adj[level + 1].push_back(pVal);
	}

	// for(auto v : adj[level + 1]){
	// 	printf("%d ", v );
	// }
	// printf("\n");

	buildTree(adj, level + 1, p);
}

void propagateChange(vector<int> adj[] , int level, int p, int lvIndex){
	int l = adj[level - 1][2 * lvIndex];
	int r = adj[level - 1][2 * lvIndex + 1];
	int newVal;
	if(level % 2){
		newVal = l | r;
	}
	else{
		newVal = l ^ r;
	}
	adj[level][lvIndex] = newVal;
	if(level != p){
		propagateChange(adj, level + 1, p , lvIndex / 2);
	}
}

int main(){

	int p, m;
	scanf("%d %d", &p, &m);
	int n = 1 << (p);
	int a[n + 10];
	for(int i = 0; i < n; ++i){
		scanf("%d", a+i);
	}
	vector<int> adj[p + 1];
	for(int i = 0; i < n; ++i){
		adj[0].push_back(a[i]);
	}
	buildTree(adj, 0 , p);

	for(int i = 0 ; i < m; ++i){
		int index, b;
		scanf("%d %d", &index, &b);
		--index;
		adj[0][index] = b;
		propagateChange(adj, 1, p , index / 2);
		printf("%d\n",adj[p][0]);
	}
}
