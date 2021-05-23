#include <cstdio>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<pair<int, int>> calcZeroSumSubArray(ll a[], int n){
	map<ll,ll> m;
	vector<pair<int,int>> res;
	ll s = 0;
	for(int i = 0; i < n; ++i){
		s += a[i];
		if(m.find(s) == m.end()){
			if(s == 0){
				res.push_back({0, i});
			}
		} 
		else{
			res.push_back({m[s] + 1, i});
		}
		m[s] = i;

	}
	return res;
}

ll calcNotGoodArray(vector<pair<int,int>> intervals, ll a[], ll n){
	set<pair<int, int>> s;
	ll res = 0;
	for(auto v: intervals){
		s.insert({v.second, v.first});
		// printf("%d %d\n",v.second, v.first );
	}
	sort(intervals.begin(), intervals.end());
	int j = 0;

	for(int i = 0; i < n; ++i){
		
		auto p = s.upper_bound({i - 1,- 1});
		// for(auto d : s){
		// 	printf("%d %d\n",d.first, d.second );
		// }
		if(p == s.end()){
			break;
		}
		ll c = n - 1 - p->first + 1;
		// printf("%d %d\n",p->first, p->second );
		res += c;
		// printf("c : %lld\n", c);
		if(i == intervals[j].first){
			s.erase({intervals[j].second, intervals[j].first});
			++j;
		}

	}
	return res;
}

int main(){
	ll n;
	scanf("%lld",&n);
	ll a[n];
	for(int i = 0; i < n; ++i){
		scanf("%lld", a + i);
	}
	vector<pair<int,int>> intervals = calcZeroSumSubArray(a, n);
	ll res = calcNotGoodArray(intervals, a, n);
	res = (n * (n + 1)) / 2 - res;
	printf("%lld\n",res );

	// for(auto v: intervals){
	// 	printf("%d %d \n", v.first, v.second);
	// }


}