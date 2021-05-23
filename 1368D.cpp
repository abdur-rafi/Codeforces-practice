#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	int maxPower = 20;
	vector<int> fre(maxPower, 0);
	for(int i = 0; i < n; ++i){
		scanf("%d", a+i);
		for(int j = 0; j < maxPower;++j){
			int mask = 1 << j;
			fre[j] += bool(mask & a[i]);
		}
	}

	// for(int i = 0; i < maxPower; ++i)
	// 	printf("%d\n",fre[i] );
	vector<pair<int,int>> v;
	for(int i = 0; i < maxPower; ++i){
		if(fre[i])
			v.push_back({fre[i], i});
	}
	unsigned long long res = 0;
	// printf("%d\n",v.size() );
	while(!v.empty()){
		unsigned long long mn = v[0].first;
		unsigned long long curr = 0;
		for(auto elem:v){
			mn = min(mn,(unsigned long long) elem.first);
			curr += (1 << elem.second);
		}
		// printf("%d\n",curr );
		res += mn * curr * curr;
		vector<pair<int, int>> V;
		for(auto elem:v){
			if(elem.first > mn){
				V.push_back({elem.first - mn, elem.second});
			}
		}
		v = V;
		// printf("%d\n",V.size() );
		// break;


	}
	printf("%llu\n",res );
}