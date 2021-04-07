#include <cstdio>
#include<vector>
#include <utility>

using namespace std;
const int MAX = 200000+100;
char s[MAX],t[MAX];
int leftMostIndex[MAX], rightMostIndex[MAX];

int main(){

	int n,m;scanf("%d %d",&n,&m);
	scanf("%s %s",s,t);
	int lfmi = 0;
	for(int i = 0; i < n;++i){
		if(s[i] == t[lfmi]){
			leftMostIndex[lfmi++] = i;
			if(lfmi == m ) break; 
		}
	}
	int rmi = m-1;
	for(int i = n-1;i > -1 ; --i){
		if(s[i] == t[rmi]){
			rightMostIndex[rmi--] = i;
			if(rmi < 0) break;
		}
	}
	int mx = 0;
	for(int i = 1; i < m; ++i){
		mx = max( mx, rightMostIndex[i] - leftMostIndex[i-1]);
	}
	printf("%d\n",mx );

	printf("Hello World");

}