#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <map>

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
		vector<int> fr;
		map<int,int> mp;
		for(int i = 0; i < n; ++i){
			mp[inp[i]]++;
		}

		for(auto p : mp){
			printf("%d %d\n",p.first,p.second);
		}


	}

}