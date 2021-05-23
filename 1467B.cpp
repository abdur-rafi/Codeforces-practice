#include <cstdio>
#include <algorithm>

using namespace std;

int count(int a[], int n, int l, int r){
	int res = 0;
	for(int i = l; i <= r; ++i){
		if(i - 1 < 0 ) continue;
		if(i + 1 >= n) continue;
		res += a[i-1] > a[i] && a[i+1] > a[i];
		res += a[i-1] < a[i] && a[i+1] < a[i];
		// printf("%d\n",res );
	}
	return res;
}

int main(){
	int t;
	scanf("%d", &t);
	while(--t>=0){
		int n;scanf("%d", &n);
		int a[n];
		for(int i = 0; i < n; ++i)
			scanf("%d", a+i);
		int res = count(a, n, 0, n-1);
		int act = res;

		// printf("%d\n",r );

		for(int i = 1; i < n - 1; ++i){
			int temp = a[i];
			int c = act;
			c -= count(a, n , i-1, i + 1);
			// printf("%d\n",c );
			a[i] = a[i-1];
			res = min(res, c + count(a, n, i - 1, i + 1));
			a[i] = a[i+1];
			res = min(res, c + count(a, n, i - 1, i + 1));
			a[i] = temp;
		}
		printf("%d\n",res );
	}
}