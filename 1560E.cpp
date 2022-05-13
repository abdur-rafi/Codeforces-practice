#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define loop(x,n,a) for(int x = a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
typedef long long ll;

using namespace std;
char str[500000 + 1];

int main(){
	int t;scanf("%d", &t);
	while(--t >= 0){
		scanf("%s", str);
		int n = strlen(str);
		vector<bool> f(26, false);
		vector<int> charOrder;
		loop_rev(i, n, 0){
			if(!f[str[i] - 'a']){
				f[str[i] - 'a'] = true;
				charOrder.push_back(str[i] - 'a'); 
			}
		}
		reverse(charOrder.begin(), charOrder.end());
		vector<int> fr(26, 0);
		int sIndex = -1;
		loop(i, n, 0){
			int c = str[i] - 'a';
			fr[c]++;
			int j = 1;
			int tot = 0;
			for(auto v : charOrder){
				tot += fr[v] * j++;
			}
			if(tot == n){
				sIndex = i;
			}
		}
		if(sIndex == -1){
			printf("-1\n");
			continue;
		}
		// printf("%d\n",sIndex );
		int i = 0;
		int j = sIndex + 1;
		bool pos = true;
		for(int l = 0; l < charOrder.size() - 1; ++l){
			int v = charOrder[l];
			int k = j;
			// printf("i: %d j: %d\n",i, j );
			while(i < k){
				if(str[i] == v + 'a'){
					++i;
					continue;
				}
				if(str[i] != str[j]){
			// printf("i: %d j: %d\n",i, j );

					pos = false;
					break;
				}
				else{
					++i;
					++j;
				}
			}
			if(!pos) break;

		}
		if(pos){
			char str2[max((int)charOrder.size(), sIndex) + 5];
			loop(i, sIndex + 1, 0){
				str2[i] = str[i];
			}
			str2[sIndex + 1] = 0;
			printf("%s ",str2 );
			for(int i = 0;i < charOrder.size(); ++i){
				str2[i] = charOrder[i] + 'a';
			}
			str2[charOrder.size()] = 0;
			printf("%s\n",str2 );
		}
		else{
			printf("-1\n");
		}
		// if(!pos) 

	}
}