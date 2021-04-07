#include <bits/stdc++.h>

#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
using namespace std;

int MOD = (1e9) + 7;
const int MAX = 200000+100;

int main(){
	int t = 1;
	// scanf("%d",&t);
	while(--t >=0){
		int n;
		scanf("%d",&n);
		int a[n];
		loop(i,n,0) scanf("%d",a+i);
		map<int,int> fre;
		loop(i,n,0) fre[a[i]]++;

		vector<int> fr;
		vector<PII> fr_with_val;
		for(auto v : fre){
			fr.push_back(v.second);
			fr_with_val.push_back(v);
		}
		if(fr.size() < 3){
			printf("0\n");
			loop(i,n,0) printf("%d ",a[i]);
		}
		vector<int> res;
		int mx = 0;
		loop(i,n,0) mx = max(mx,a[i]);
		res.push_back(mx);
		loop(i,fr.size(),0){
			if(fr_with_val[i].first == mx){
				fr_with_val[i].second--;
				fr[i]--;
			}
		}

		sort(fr.begin(),fr.end());

		for(auto val : fr_with_val) printf("%d %d\n",
		val.first,val.second );

		printf("\n");

		int p = 0;
		int mn = 1;
		for(int i=0;i<fr.size();++i){
			int c = fr[i] - p;
			p = fr[i];
			vector<int> r;
			vector<PII> nw;
			loop(j,fr_with_val.size(),0){
				if(fr_with_val[j].second > fr[i]) nw.push_back(fr_with_val[j]);
				r.push_back(fr_with_val[j].first);
			}

			sort(r.begin(),r.end());

			while(c--){
				++mn;
				res.insert(res.end(),r.begin(),r.end());
			}

			fr_with_val = nw;

			for(auto val : fr_with_val) printf("%d %d\n",
			val.first,val.second );

			printf("\n");
		}

		printf("%d\n",n - mn );

		for(auto v : res) printf("%d ",v );
		

	}
}
