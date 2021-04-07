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
	scanf("%d",&t);
	while(--t >=0){
		int n,T;scanf("%d %d",&n,&T);
		int a[n];
		loop(i,n,0) scanf("%d",a+i);
		set<int> s;
		map<int,vector<int>> mp;

		loop(i,n,0){
			s.insert(a[i]);
			mp[a[i]].push_back(i);
		}

		int res[n];

		loop(i,n,0) res[i] = -1;
		set<int> d;

		loop(i,n,0){
			// if(res[i] != -1) continue;

			if(mp[a[i]].size() == 0) continue;
			// if(mp[a[i]].size() == 1){
			// 	int ic = 0;

			// 	if(d.find(a[i]) != d.end()){
			// 		ic = 1;
			// 	}
			// 		int rem = a[i];
			// 		int sz = mp[rem].size();
			// 		res[mp[rem][sz-1]] = ic;
			// 		mp[rem].pop_back();
			// 		s.erase(rem);
					
			// 	continue;
			// }

			int ic = 0,id = 0;

			

			int rem = T -a[i];
			if(s.find(rem) != s.end()){
				int sz = mp[rem].size();
				// printf("%d\n",mp[rem][sz-1] );
				if(d.find(rem) != d.end()){
					res[mp[rem][sz-1]] = 1;
					ic = 0;
				}
				else{
					res[mp[rem][sz-1]] = 0;
					ic = 1;
				}
				mp[rem].pop_back();
				if(sz == 1){
					s.erase(rem);
				}
			}
			else{
				int rem = a[i];
				if(d.find(rem) != d.end()){
					ic = 1;
				}
			}

			rem = a[i];

			if(s.find(a[i]) != s.end()){
				int sz = mp[rem].size();
				res[mp[rem][sz-1]] = ic;
				if(ic){
					d.insert(a[i]);
				}
				mp[rem].pop_back();
				if(sz == 1){
						s.erase(rem);
				}
			}

		}

		loop(i,n,0){
			if(res[i] == -1) res[i] = 0;
			printf("%d ",res[i] );
		}
		printf("\n");

	}
}
