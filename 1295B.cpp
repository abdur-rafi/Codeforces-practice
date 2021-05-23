#include <cstdio>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(--t >= 0){
		int n, x;
		scanf("%d %d", &n, &x);
		char str[n+1];
		scanf("%s", str);
		// int f[n] = 0;
		int s = 0;
		for(int i = 0; i < n; ++i){
			s += str[i] == '0' ? 1 : -1;
		}
		int total = s;
		int res = 0;
		s = 0; 
		if(x == 0)
			++res;
		for(int i = 0; i < n; ++i){
			s += str[i] == '0' ? 1 : -1;
			long long del = x - s;
			long long sign = del * total; 
			if(total == 0 && del == 0){
				res = -1;
				break;
			}
			else if(total != 0){
				if( sign >= 0 && del % total == 0){
					++res;
				}
			}
		}

		printf("%d\n",res );
	}
}
