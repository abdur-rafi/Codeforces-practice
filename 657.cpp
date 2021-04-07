#include <bits/stdc++.h>

#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
using namespace std;

char pattern[] = "abacaba";

int isthere(char str[],int n,int i){
	for(int j=0;j<7;++j){
		if(j+i >= n || str[j+i] != pattern[j]) return 0;
	}
	return 1;
}
bool canthere(char str[],int n,int i){
	for(int j=0;j<7;++j){
		if(j+i >= n ) return false;
		if(str[j+i] != '?' && str[j+i] != pattern[j]) return false;
	}
	return true;
}

int main(){
	int t;scanf("%d",&t);
	while(--t>=0){
		int n;scanf("%d",&n);
		char str[n+10];
		scanf("%s",str);
		int n2 = n;
		int c = 0;
		loop(i,n,0){
			c += isthere(str,n,i);
		}
		if(c > 1){
			printf("No\n");
			continue;
		}
		if(c == 1){
			loop(i,n,0){
				if(str[i] == '?') str[i] = 'z';
			}
			printf("Yes\n");
			printf("%s\n",str);
			continue;
		}
		bool pos = false;
		loop(i,n,0){
			if(canthere(str,n,i) == true){
				char pattern2[8];
				for(int j=0;j<7;++j){
					pattern2[j] = str[i+j];
					str[i+j] = pattern[j];
				}
				
				if(isthere(str,n,i+4) == 0 && isthere(str,n,i+6) == 0){
					pos = true;
					break;
				}
				else{
					for(int j=0;j<7;++j){
						str[i+j] = pattern2[j];
					}
				}
			}
		}
		if(!pos) printf("No\n");
		else{
			loop(i,n,0){
				if(str[i] == '?') str[i] = 'z';
			}
			printf("Yes\n");
			printf("%s\n",str);
		}

	}
}