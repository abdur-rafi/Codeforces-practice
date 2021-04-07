#include <bits/stdc++.h>

#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
using namespace std;

int bs(vector<pair<ll,ll>> &v,ll beg,ll val){
	int i = beg;
	int j = v.size() - 1;
	int m;
	while(i <= j){
		m = (i+j) >> 1;
		if(v[m].first > val) j = m-1;
		else i = m+1;
	}
	return i-1;
}

int MOD = (1e9) + 7;
char str[1010];
int main(){
	int t = 1;
	scanf("%d",&t);
	while(--t >=0){
		ll n,k;scanf("%lld %lld",&n,&k);
		ll x[n];
		ll y[n];
		loop(i,n,0) scanf("%lld",x+i);
		loop(i,n,0) scanf("%lld",y+i);
		map<ll,ll> fre;
		loop(i,n,0) fre[x[i]]++;
		vector<pair<ll,ll>> v;
		for(auto p:fre){ 
			v.push_back(p);
		}
		ll sum[v.size() + 1];
		int nv = v.size();
		sum[0] = 0;
		loop(i,nv+1,1){
			sum[i] = sum[i-1] + v[i-1].second;
		}
		// printf("v : \n");
		// for(auto p:v){
		// 	printf("%lld %lld\n",p.first,p.second );
		// }
		vector<ll> count;
		loop(i,nv,0){
			int j = bs(v,i,v[i].first+k);
			// printf("j : %d\n",j );
			int c = sum[j+1] - sum[i];
			count.push_back(c);
		}


		vector<ll> rev_max(count.size());
		ll mx = count[count.size()-1];
		for(int i = count.size()-1;i>=0;--i){
			mx = max(mx,count[i]);
			rev_max[i] = mx;
		}
		// for(auto c : count){
		// 	printf("%lld ", c );
		// }
		// printf("\n");
		// for(auto c : rev_max){
		// 	printf("%lld ", c );
		// }
		// printf("\n");
		ll res = 0;
		loop(i,nv,0){
			int j = bs(v,i,v[i].first+k);
			ll curr = count[i];
			// printf("j : %d\n",j );
			if(j+1 < count.size()) curr += rev_max[j+1];
			res = max(res,curr);
		}
		printf("%lld\n",res );
	}
}