#include <bits/stdc++.h>

#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
using namespace std;

int MOD = (1e9) + 7;

int tc = 0;

char str[100000+100];
int state[100000+100];
int n,x;
char res[100000+100];

bool possible(){

	loop(i,n,0) res[i] = '2';


	loop(i,n,0){
		if(i-x < 0){
			if(i + x >= n){
				if(str[i] == '1') return false;
				continue;
			}
			res[i+x] = str[i];
		}
		else{
			if(i+x >= n){
				if(res[i-x] == '2'){
					res[i-x] = str[i];
					continue;
				}
				if(res[i-x] != str[i]) return false;
			}
			else{
				if(str[i] == '0' && res[i-x] == '1') return false;
				if(str[i] == '0'){
					res[i+x] = '0';
					res[i-x] = '0';
				}
				else{
					if(res[i-x] == '1') continue;
					if(res[i-x] == '2'){
						res[i-x] = '1';
						continue;
					}
					else
						res[i+x] = '1';
				}
			}
		}
	}
	return true;
	
}

int main(){
	int t = 1;
	scanf("%d",&t);
	while(--t>=0){
		scanf("%s",str);
		n = strlen(str);
		scanf("%d",&x);
		if(possible()){
			loop(i,n,0){
				if(res[i] == '2') res[i] = '0';
			}
			res[n] = '\0';
			printf("%s\n",res );
		}
		else printf("-1\n");
	}

}