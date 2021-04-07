#include <bits/stdc++.h>

#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
using namespace std;
char str[200000+100];

int pattern(char first,char sec,int n){
	bool ff = false,fs = false;
	int c = 0;
	loop(i,n,0){
		if(ff == false && str[i] == first){
			ff = true;
		}
		else if(ff == true && str[i] == sec){
			c += 2;
			ff = false;
		}
	}


	return n - c;
}

int main(){

	int t;scanf("%d",&t);


	while(--t>=0){
		scanf("%s",str);
		int n = strlen(str);
		int fr[10];
		loop(i,10,0) fr[i] = 0;
		loop(i,n,0){
			fr[str[i]-'0']++;
		}
		int res = n+100;
		loop(i,10,0){
			loop(j,10,0){
				res = min(res,pattern(i+'0',j+'0',n));
			}
		}


		loop(i,10,0){
			res = min(res,n-fr[i]);
		}
		printf("%d\n",res);
	}
}