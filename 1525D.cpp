#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
typedef long long ll;

ll table[5001][5001];

ll dp(int i, int j, vector<int> &filled, vector<int> &empty){
	if(i >= filled.size()) return 0;
	if(j >= empty.size()) return INT_MAX;
	if(table[i][j] != -1) return table[i][j];
	table[i][j] = min(dp(i, j+1, filled, empty),
				 dp(i+1, j+1, filled,empty) + abs(filled[i] - empty[j]) );
	return table[i][j];
}

int main(){
	int n;scanf("%d", &n);

	int a[n];
	for(int i = 0; i < n; ++i) scanf("%d", a+i);

	vector<int> filled;
	vector<int> empty;
	for(int i = 0; i < n; ++i){
		if(a[i] == 1){
			filled.push_back(i);
		}
		else 
			empty.push_back(i);
	}

	for(int i = 0; i < filled.size(); ++i){
		for(int j = 0; j < empty.size(); ++j){
			table[i][j] = -1;
		}
	}

	printf("%lld\n",dp(0, 0, filled, empty) );

}