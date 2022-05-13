#include <cstdio>
#include <vector>
#include <utility>

using namespace std;


typedef long long ll;

int main(){
	int t;scanf("%d", &t);
	while(--t>=0){
		ll n;
		scanf("%lld", &n);
		ll mx = n;
		vector<pair<ll, ll>> res;
		for(ll i = n - 1; i > 1;--i){
			if(i * i <= mx){
				mx = mx / i + ((mx % i == 0) ? 0 : 1);
				res.push_back({n, i});
			}
			if( i != 2)
				res.push_back({i, n});
		}
		while(mx > 1){
			mx = mx / 2 + ((mx % 2 == 0) ? 0 : 1);
			res.push_back({n, 2});
		}
		printf("%d\n",res.size() );
		for(auto d : res)
			printf("%lld %lld\n",d.first , d.second );
	}
}

