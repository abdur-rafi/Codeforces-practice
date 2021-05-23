#include <cstdio>
#include <map>

using namespace std;

typedef long long ll;

int main(){
	ll n,k;
	scanf("%lld %lld", &n, &k);

	ll ks = k * k;

	map<ll, ll> mp, res;

	ll r = 0;



	for(int i = 0; i < n; ++i){
		ll a;
		scanf("%lld", &a);
		mp[a]++;
		if(k == 1 || a == 0){
			ll c = mp[a];
			r += ((c - 1) * (c - 2)) / 2;
			continue; 
		}

		if(a % k == 0){
			auto f1 = mp.find(a / k);
			if(f1 != mp.end()){
				res[a] += f1->second;
			}
			auto f2 = res.find(a / k);
			if(f2 != res.end())
				r += f2->second;
		}
		// printf("%lld\n",r );

	}

	printf("%lld\n",r );
}