#include<cstdio>
#include <vector>
#include <utility>
typedef long long ll;

using namespace std;

const ll MAX = (1e9) + 100; 

int main(){

	vector<ll> freq; 
	ll i = 3;
	ll c = 0;
	do{
		 c = i * i + 1;
		 c /= 2;
		 ll b  = c - 1;
		 freq.push_back(c);
		 i += 2;
	}
	while(c < MAX);
	// printf("%d\n",freq.size());
	int t;
	scanf("%d",&t);
	while(--t>=0){
		ll n;scanf("%lld",&n);
		ll i = 0;
		ll j = freq.size() - 1;
		ll mid;
		while(i <= j){
			mid = (i+j) >> 1;
			if(freq[mid] > n){
				j = mid - 1;
			}
			else{
				i = mid + 1;
			}
		}
		printf("%lld\n",i);
	}

}
