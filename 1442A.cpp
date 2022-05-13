#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


int main(){
	int t;
	scanf("%d", &t);
	while(--t >= 0){
		int n;
		scanf("%d", &n);	
		int h[n];
		for(int i = 0; i < n; ++i) scanf("%d", h + i);
		int mn = h[0];
		pii a[n];
		for(int i = 0; i < n; ++i){
			mn = min(mn, h[i]);
			a[i].first = mn;
		}
		mn = h[n-1];
		for(int i = n-1; i > -1; --i){
			mn = min(mn, h[i]);
			a[i].second = mn;
		}
		bool possible = true;
		pii c[n];
		c[0].first = a[0].first;
		c[0].second = max(0, h[0] - c[0].first);
		for(int i = 1; i < n ; ++i){

			c[i] = c[i - 1];
			if(c[i].first > a[i].first) 
				c[i].first = a[i].first;
			if(c[i].first + c[i].second < h[i])
				c[i].second = h[i] - c[i].first;
			else if(c[i].first + c[i].second > h[i])\
				c[i].first = h[i] - c[i].second;

			if((c[i].first < 0 ) || c[i].second > a[i].second){
				possible = false;
				break;
			}
		}
		if(possible) printf("YES\n");
		else printf("NO\n");
	}

}