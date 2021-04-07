#include <cstdio>
#include <vector>
using namespace std;
typedef unsigned long long ll;
const ll MX = 1000000000000000001;

int main(){

	vector<ll> v;
	ll i = 1;
	while((i*(i+1))/2 < MX){
		ll c = (i*(i+1))/2;
		if(v.size() > 0){
			c += v.back();
		}
		v.push_back(c);
		i = 2 * i + 1;
	}
	// printf("%d\n",v.size());
	int t;
	scanf("%d",&t);
	while(--t>=0){
		ll x;
		scanf("%llu",&x);
		int i = 0;
		int j = v.size() - 1;
		int m;
		while(i <= j){
			m = (i + j) >> 1;
			if(v[m] > x){
				j = m - 1;
			}
			else{
				i = m + 1;
			}
		}
		printf("%d\n", i);
	}
}