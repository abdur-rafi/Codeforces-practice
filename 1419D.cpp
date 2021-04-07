#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(){

	int n;
	scanf("%d",&n);
	int a[n];
	for(int i = 0 ;i < n; ++i){
		scanf("%d",a+i);
	}

	set<int> s;
	map<int,int> mp;

	for(int i = 0; i < n;++i){
		s.insert(a[i]);
		mp[a[i]]++;
	}

	if(s.size() == 1){
		printf("0\n");
		for(int i = 0 ; i < n;++i){
			printf("%d ",a[i] );
		}
		return 0;
	}

	int i = 0;
	vector<int> prices(s.size());
	for(auto itr = s.begin(); itr != s.end();++itr){
		prices[i++] = *itr;
	}

	vector<int> freq(s.size());
	i = 0;
	for(auto itr = mp.begin(); itr != mp.end();++itr){
		freq[i++] = itr->second;
	}

	reverse(freq.begin(),freq.end());
	reverse(prices.begin(),prices.end());

	bool checKForMul = true;
	int fromIndex = 1;
	vector<int> res;

	res.push_back(prices[0]);
	for(int i = 0 ; i < prices.size(); ++i){
		int required = i == 0 ? freq[i] - 1 : freq[i];

		int c = 0 ;
		if(required == 0 ) continue;
	 	if(checKForMul && (i < prices.size() - 1)){
	 		if(fromIndex <= i){
 				fromIndex = i + 1;
	 		}
	 		while(true){
	 			int curr = freq[fromIndex];
	 			int mx = min(required,curr - 1);
	 			freq[fromIndex] -= mx;
	 			for(int k = 0 ; k < mx; ++k){
	 				res.push_back(prices[fromIndex]);
	 				res.push_back(prices[i]);
	 			}
	 			required -= mx;
	 			if(required == 0){
	 				break;
	 			}
	 			else{
	 				if(fromIndex == prices.size() - 1){
	 					fromIndex = i + 1;
	 					checKForMul = false;
	 					break;
	 				}
	 				++fromIndex;
	 			}
	 		}
	 	}
	 	if(!checKForMul && (i < prices.size() - 1)){
	 		if(fromIndex <= i){
		 		fromIndex = i + 1;
		 	}
	 		while(true){
		 		if(freq[fromIndex] == 0){
		 			if(fromIndex == prices.size() - 1){
		 				break;
		 			}
		 			++fromIndex;
		 			continue;
		 		}
		 		res.push_back(prices[fromIndex]);
		 		res.push_back(prices[i]);
		 		freq[fromIndex] = 0;
		 		--required;
		 		if(required == 0){
		 			break;
		 		}
		 		if(fromIndex == prices.size() - 1){
		 			++fromIndex;
		 			break;
		 		}
	 		}
	 	}
	 	while(required){
	 		res.push_back(prices[i]);
	 		--required;
	 	}
	}

	int c = 0;
	for(int i = 1; i < res.size() - 1; ++i){
		if(res[i] < res[i-1] && res[i] < res[i+1]) ++c;
	}

	printf("%d\n",c );

	for(auto r: res){
		printf("%d ",r );
	}
}