#include <cstdio>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = -0; i < n; ++i){
		scanf("%d", a+i);
	}
	map<ll,vector<int>> leftToRightMap, rightToLeftMap;
	ll s = 0;
	// for(int i = 0 ; i < n; ++i ){
	// 	s += a[i];
	// 	leftToRightMap[a[i]]++;
	// }
	s = 0;
	for(int i = n - 1; i > -1 ; --i){
		s += a[i];
		rightToLeftMap[s].push_back(i);
	}

	ll totalSum = s;
	s = 0;

	ll res = 0 ;

	for(int i = 0 ; i < n; ++i){
		s += a[i];
		if(totalSum != 3 * s){
			continue;
		}
		if(rightToLeftMap.find(s) != rightToLeftMap.end()){
			vector<int> &v = rightToLeftMap[s];
			// printf("i : %d\n",i );
			// for(auto c : v){
			// 	printf("%d ",c);
			// }
			// printf("\n");
			int j = 0, k = v.size() - 1;
			int mid;
			while(j <= k){
				mid = (j + k) >> 1;
				if(v[mid] > ( i + 1) ){
					j = mid + 1;
				}
				else{
					k = mid - 1;
				}
			}
			res += j;
		}
	}

	printf("%lld\n",res );
}
