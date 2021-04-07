#include <bits/stdc++.h>

#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
using namespace std;

int n,m;

int goUp(int x,int y,vector<PII> &res,int state){
	if(state == 0){
		for(int i=x-1;i>=0;--i){
			res.push_back({i,y});
		}
		for(int i=n-1;i>x;--i) res.push_back({i,y});
	}
	else{
		for(int i=x+1;i<n;++i) res.push_back({i,y});
		for(int i=0;i<x;++i) res.push_back({i,y});
	}
}



int main(){
	int t = 1;
	// scanf("%d",&t);
	while(--t>=0){
		int n,m;scanf("%d %d",&n,&m);
		int a[n],b[m];
		loop(i,n,0) scanf("%d",a+i);
		loop(i,m,0) scanf("%d",b+i);

		int res = 0;
		for(;;++res){
			int found = 1;
			loop(i,n,0){
				int f = a[i];
				int p = 0;
				loop(j,m,0){
					int s = b[j];
					int ad = f & s;
					if((ad | res) <= res){
						p = 1;
						break;
					}
				}
				if(p == 0){
					found = 0;
					break;
				}
			}
			if(found) break;
		}
		printf("%d\n",res );
	}
}