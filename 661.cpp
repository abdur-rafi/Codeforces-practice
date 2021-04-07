#include <bits/stdc++.h>

#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
using namespace std;

int main(){
	int t = 1;
	scanf("%d",&t);
	while(--t>=0){
		int n;scanf("%d",&n);
		char str[n+10];
		scanf("%s",str);
		int end_0 = 0;
		int end_1 = 0;
		vector<int> end_0_i,end_1_i;
		int index[n+1];
		int tot = 0;
		loop(i,n,0){
			if(str[i] == '0'){
				if(end_1 == 0){
					end_0++;
					end_0_i.push_back(++tot);
					index[i] = tot;
				}
				else{
					int lst = end_1_i[end_1-1];
					end_1_i.pop_back();
					--end_1;
					index[i] = lst;
					end_0++;
					end_0_i.push_back(lst);
				}
			}
			else{
				if(end_0 == 0){
					end_1++;
					end_1_i.push_back(++tot);
					index[i] = tot;
				}
				else{
					int lst = end_0_i[end_0-1];
					end_0_i.pop_back();
					--end_0;
					index[i] = lst;
					end_1++;
					end_1_i.push_back(lst);
				}
			}
		}

		printf("%d\n",tot);
		loop(i,n,0) printf("%d ",index[i]);
		printf("\n");
	}
}