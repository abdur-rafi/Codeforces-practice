#include <bits/stdc++.h>

#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
using namespace std;

int MOD = (1e9) + 7;
const int MAX = 100000+100;

int highest[MAX];
int n;

int leaf = -1;

int dfs(vector<int> adj[],int parent,int curr){
	bool l = true;
	int s = 0;
	int mx = 0;
	for(auto v : adj[curr]){
		if(v != parent){
			int r = dfs(adj,curr,v);
			s += r;
			mx = max(mx,r);
			l = false;
		}
	}
	mx = max(mx,n-s-1);
	highest[curr] = mx;

	if(l) leaf = curr;
	return s+1;

}




int main(){
	int t = 1;
	scanf("%d",&t);
	while(--t >=0){
		int n;scanf("%d",&n);
		ll a[n];
		loop(i,n,0) scanf("%lld",a+i);
		vector<ll> pos;
		vector<ll> neg;
		int zeros = 0;
		loop(i,n,0){
			if(a[i] > 0){
				pos.push_back(a[i]);
			}
			else if(a[i] == 0) ++zeros;
			else{
				neg.push_back(a[i]);
			}
		}
		sort(neg.begin(),neg.end());
		sort(pos.begin(),pos.end());
		reverse(neg.begin(),neg.end());
		if(pos.size() == 0){
			if(zeros){
				printf("0\n");
				continue;
			}
			else{
				ll s = 1;
				loop(i,5,0) s*= neg[i];
				printf("%lld\n",s ); 
				continue;
			}

		}
		if(neg.size() == 0){
			ll s = 1;
			if(pos.size() > 4){
				reverse(pos.begin(),pos.end());
				loop(i,5,0) s*= pos[i];
				printf("%lld\n",s );
			}
			else printf("0\n");

			continue;
		}
		ll res = -(1e18);
		int posz = pos.size();
		int negz = neg.size();

		if(posz + negz < 5){
			printf("0\n");
			continue;
		}


		for(int fr = 0;fr <= 5;++fr){
			if(posz - fr < 0) continue;
			int c = fr;
			ll s = 1;
			while(c){
				s *= pos[posz - c];
				--c;
			}
			c = 5 - fr;
			if(negz - c < 0) continue;

			while(c){
				s *= neg[negz - c];
				--c;
			}
			res = max(res,s);
		}


		if(zeros){
			res = max(0LL,res);
		}

		printf("%lld\n",res );

	}
}