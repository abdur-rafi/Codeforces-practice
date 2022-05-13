#include <cstdio>
#include <algorithm>
#include <map>

typedef long long ll;
using namespace std;

int main(){
	ll n;scanf("%lld", &n);
	ll a[n];
	for(int i = 0; i < n; ++i) scanf("%lld", a+i);
	sort(a, a + n);
	map<ll, ll> mp;
	if(n == 1){
		printf("-1\n");
		return 0;
	}
	for(int i = 1; i < n; ++i){
		mp[a[i] - a[i - 1]]++;
	}

	if(mp.size() > 2){
		printf("0\n");
		return 0;
	}
	else if(mp.size() == 1){
		ll d = a[1] - a[0];
		if(d == 0){
			printf("1\n%d\n", a[0]);
		}
		else if(n == 2 && d % 2 == 0){
			printf("3\n");
			printf("%lld %lld %lld\n",a[0] - d,  a[0] + d/2 , a[n-1] + d);
		}
		else{
			printf("2\n");
			printf("%lld %lld\n",a[0] - d, a[n - 1] + d );
		}
	}
	else{
		if(n == 3){
			ll d1 = a[2]- a[1];
			ll d2 = a[1] - a[0];
			ll mx = max(d1, d2);
			ll mn = min(d1, d2);
			if((mx % 2) || mx / 2 != mn){
				printf("0\n");
				return 0;
			}
			if(mx / 2 == mn){
				printf("1\n");
				if(a[2] - a[1] == mx){
					printf("%lld\n", a[1] + mx / 2);
				}
				else{
					printf("%lld\n",a[0] + mx / 2 );
				}
			}
			return 0;

		}
		bool f = false;
		ll key = 0;
		ll d = 0;
		
		for(auto v : mp){
			if(v.second == 1){
				f = true;
				key = v.first;
			}
			else
				d = v.first;
		}
		if(!f || key % 2 == 1 || (key / 2 != d) ){
			printf("0\n");
			return 0;
		}
		int ki = 0;
		for(int i = 1; i < n; ++i){
			if(a[i] - a[i-1] == key){
				ki = i - 1;
			}
		}

		printf("1\n");
		printf("%lld\n",a[ki] + d );
	}

}

