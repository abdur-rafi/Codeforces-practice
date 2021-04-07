#include <bits/stdc++.h>

#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
using namespace std;

int MOD = (1e9) + 7;
char str[1010];
int main(){
	int t = 1;
	// scanf("%d",&t);

	int n;scanf("%d",&n);

	ll sum = 0;

	ll a[n];
	loop(i,n,0 ) scanf("%lld",a+i);

	loop(i,n,0) sum += a[i];
	sum -= n;

	ll mx = 100000;

	sort(a,a+n);

	loop(i,mx,2){
		ll b = 1;
		ll curr = 0 ;
		loop(j,n,0){
			curr += abs(a[j] - b);
			if(curr >= sum) break;
			b *= i;
		}
		sum = min(sum,curr);
	}

	printf("%lld\n",sum );
		

}