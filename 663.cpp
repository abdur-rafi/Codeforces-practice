#include <bits/stdc++.h>

#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
using namespace std;

int MOD = (1e9) + 7;
const int MAX = 1000000+100;

ll fct[MAX];
int main(){
	int t = 1;

	while(--t>=0){
		ll n; scanf("%lld",&n);
		ll res = 0;
		fct[0] = 1;
		for(ll i=1;i<n+1;++i){
			fct[i] = (i*(fct[i-1]))%MOD;
			// printf("%lld\n",fct[i] );
		}

		ll mn = 0;

		loop(i,n,0){
			ll lft = i;
			
		}

		res = (fct[n] - (2*n) + MOD ) % MOD;
		printf("%lld\n",res );
	}
}