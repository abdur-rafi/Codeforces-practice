#include <istream>
#include <cstdio>
#include <vector>
#include <utility>

using namespace std;
typedef long long unsigned ll;

int main(){

	ll n, b;
	scanf("%llu %llu", &n , &b);

	ll bc = b;
	vector<pair<ll, ll>> divs;

	for(ll i = 2; i * i <= b; ++i){
		
		if(bc % i == 0){
			ll c = 0;
			while(bc % i == 0){
				bc /= i;
				c++;
			}
			divs.push_back({i, c});
			// printf("%llu %llu\n",i, c );
		}		
	}
	if(bc != 1) divs.push_back({bc, 1});

	ll mnc = -1;

	for(auto p : divs){
		ll currDiv = p.first;

		ll c = 0;
		ll cm = currDiv;

		while(cm <= n){
			c += n / cm;
			ll temp = cm;
			cm *= currDiv;
			if(cm / currDiv != temp) break;
		}

		if(mnc == -1){
			mnc = c / p.second;
		}

		else
			mnc = min(mnc, c / p.second);
	}

	printf("%llu\n",mnc );



	return 0;
}
