#include <cstdio>
#include <set>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int MAX = 200000+ 200;
ll a[MAX];

int main(){
	int t;
	scanf("%d",&t);
	while(--t>=0){
		ll n;
		map<ll,ll> mp;
		scanf("%lld",&n);
		for(int i = 0 ;i < 2*n; ++i){
			scanf("%lld",a+i);
			mp[a[i]]++;
		}
		vector<ll> p;
		bool notEven = false;
		for(auto v : mp){
			p.push_back(v.first);
			if( (v.first % 2 ) || v.second != 2){
				notEven = true;
				break;
			}
		}
		if(notEven){
			printf("NO\n");
			continue;
		}
		int sz = p.size();
		// for(auto v : p){
		// 	printf("%lld\n",v);
		// }

		ll prevSum = 0;

		bool res = true;
		ll c = 2 * n;
		for(int i = sz - 1; i > -1 ; --i){
			ll tmp = p[i];
			tmp -= 2 * prevSum;
			if((tmp <= 0) || tmp % c ){
				res = false;
				break;
			}
			tmp /= c;
			prevSum += tmp;
			c -= 2;
		}
		printf("%s\n", res ? "YES" : "NO" );

	}
}