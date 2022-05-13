#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
const int MX = (1e5) + 1;
const int MOD = (1e9) + 7;
int main(){
	int t;
	scanf("%d", &t);
	while(--t >= 0){
		int n;
		scanf("%d", &n);
		int a[n], b[n], d[n];
		int ia[n + 1], ib[n + 1];
		for(int i = 0; i < n; ++i){
			scanf("%d", a + i);
			ia[a[i]] = i;
		}
		for(int i = 0; i < n; ++i){
			scanf("%d", b + i);
			ib[b[i]] = i;
		}
		for(int i = 0; i < n; ++i){
			scanf("%d", d + i);
		}
		
		vector<int> inWhatGroup(n, -1);
		int groupCount = 0;


		for(int i = 0; i < n; ++i){
			if(inWhatGroup[i] != -1) continue;
			if(a[i] == b[i]) continue;

			inWhatGroup[i] = groupCount;
			int tmp = ia[b[i]];
			while(inWhatGroup[tmp] == -1){
				inWhatGroup[tmp] = groupCount;
				tmp = ia[b[tmp]];
			}
			++groupCount;
		}
		vector<int> isTaken(groupCount, false);
		for(int i = 0; i < n; ++i){
			if(d[i] != 0 && a[i] != b[i]){
				isTaken[inWhatGroup[i]] = true;
			}
		}
		int c = 0;
		for(int i = 0; i < groupCount; ++i){
			if(!isTaken[i])  ++c;
		}
		long long r = 1;
		for(int i = 0; i < c; ++i)
			r = (r * 2L) % MOD;

		printf("%lld\n",r );
		// printf("%d\n",groupCount );


			
	}
}