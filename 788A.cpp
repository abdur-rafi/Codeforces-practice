#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(--t >= 0){
		int n;
		scanf("%d", &n);
		int a[n];
		for(int i = 0; i < n; ++i)
			scanf("%d", a + i);
		int cn = 0;
		for(int i = 0; i < n; ++i){
			if(a[i] < 0) cn++;
		}
		for(int i = 0; i < n; ++i){
			if(i < cn){
				a[i] = -1 * abs(a[i]);
			}
			else a[i] = abs(a[i]);
		}
		bool sorted = true;
		for(int i = 1; i < n; ++i){
			sorted = sorted & (a[i-1]<=a[i]);
		}
		if(sorted) printf("YES\n");
		else printf("NO\n");
	}
}