#include <bits/stdc++.h>

#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
using namespace std;

int MOD = (1e9) + 7;
const int MAX = 300000+100;
char str[MAX];

int check(int c[2],int q,int k){
	if(c[0] == c[1]) return 1;
	int diff = abs(c[0] - c[1]);
	if(diff <= q) return 1;
	return 0;
}

int main(){
	int t = 1;
	scanf("%d",&t);
	while(--t >=0){
		int n,k;scanf("%d %d",&n,&k);
		scanf("%s",str);
		bool pos = true;
		for(int i=0;i+k < n;++i){
			if(str[i] == str[i+k]){
				;
			}
			else if(str[i] == '?' || str[i+k] == '?'){
				str[i] = (str[i] == '?')?str[i+k]:str[i];
				str[i+k] = str[i];
			}
			else{
				pos = false;
				// break;
			}
		}

		for(int i=n-1;i-k >= 0;--i){
			if(str[i] == str[i-k]){
				;
			}
			else if(str[i] == '?' || str[i-k] == '?'){
				str[i] = (str[i] == '?')?str[i-k]:str[i];
				str[i-k] = str[i];
			}
			else{
				pos = false;
				// break;
			}
		}

		// printf("%s\n",str );
		if(!pos){
			printf("NO\n");
			continue;
		}
		int c[2] = {0,0};
		int q = 0;
		vector<int> qi;
		for(int i=0;i<k;++i){
			if(str[i] == '?'){
				++q;
				qi.push_back(i);
			}
			else c[str[i]-'0']++;
		}

		pos &= check(c,q,k);

		if(pos){
			char cr;
			if(c[0] > c[1]) cr = '1';
			else if(c[1] > c[0]) cr = '0';

			int diff = abs(c[0]-c[1]);
			while(diff > 0){
				int j = qi[qi.size()-1];
				qi.pop_back();
				while(j < n){
					str[j] = cr;
					j += k;
				}
				--diff;
			} 
			int exc = k - 2*max(c[0],c[1]);

			diff = exc / 2;
			while(diff > 0){
				int j = qi[qi.size()-1];
				qi.pop_back();
				while(j < n){
					str[j] = '0';
					j += k;
				}
				--diff;
			}
			diff = exc / 2;
			while(diff > 0){
				int j = qi[qi.size()-1];
				qi.pop_back();
				while(j < n){
					str[j] = '1';
					j += k;
				}
				--diff;
			}
			c[0] = c[1] = k/2;
			q = 0;
		}

		for(int i=0;;++i){
			int e = i+k;
			if(e >= n) break;
			int b = i;
			if(str[b] == '?') --q;
			else c[str[b]-'0']--;
			if(str[e] == '?') ++q;
			else c[str[b]-'0']++;

			pos &= check(c,q,k);
				
		}
		if(pos){
			printf("YES\n");
		}
		else printf("NO\n");

	}
}