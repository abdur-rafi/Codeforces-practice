#include <bits/stdc++.h>

#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
using namespace std;

int MAX = 200000+100;

int main(){
	int t = 1;
	scanf("%d",&t);
	while(--t>=0){
		int n;scanf("%d",&n);
		int a[n];
		loop(i,n,0) scanf("%d",a+i);
		int fre[n+1];
		loop(i,(n+1),0) fre[i] = 0;
		loop(i,n,0){
			fre[a[i]]++;
		}
		int length[n+1];
		loop(i,(n+1),0) length[i] = 0;
		vector<int> vc;
		loop(i,(n+1),0){
			if(fre[i] > 0) vc.push_back(fre[i]);
		}
		sort(vc.begin(),vc.end());
		reverse(vc.begin(),vc.end());
		int sz = vc.size();
		int c = 0;
		int s = 0;
		for(int i = sz-1;i>=0;--i){
			length[sz-c] += vc[i] - s;
			s = vc[i];
			++c;
		}
		// loop(i,(n+1),0) printf("%d\n",length[i] );
		vc.clear();
		int gaps[n+1];
		loop(i,(n+1),0) gaps[i] = 0;
		loop(i,(n+1),0){
			int c = length[i] - 1;

			int f = 1;
			while(c > 1){
				gaps[c/2] += f;
				f *= 2;
				c /= 2;
			}
		}
		vector<PII> g;
		loop(i,(n+1),0){
			if(gaps[i] > 0){
				g.push_back({i,gaps[i]});
			}
		}
		sort(g.begin(),g.end());
		reverse(g.begin(),g.end());
		
	}
}