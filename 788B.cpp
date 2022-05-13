#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(--t >= 0){
		int n;
		scanf("%d", &n);
		char str[n + 1];
		scanf("%s", str);
		int m;scanf("%d", &m);
		vector<int> special(26, false);
		for(int i = 0; i < m; ++i){
			char b[5];
			scanf("%s", b);
			special[b[0] - 'a'] = true;
		}
		vector<int> dist;
		for(int i = 0; i < n; ++i){
			if(special[str[i] - 'a'])
				dist.push_back(i);
		}
		if(dist.size() == 0) printf("0\n");
		else{
			int mx = dist[0];
			for(int i = 0; i + 1 < dist.size(); ++i){
				mx = max(mx, dist[i + 1] - dist[i]);
			}
			printf("%d\n",mx );

		}
	}
}