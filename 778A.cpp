#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 200000 + 1;
char t[MAX], p[MAX], temp[MAX];
int a[MAX];
int n;
int nP;

bool check(int mid){
	bool fre[n] = {false};
	for(int i = 0; i < mid; ++i){
		fre[a[i] - 1] = true;
	}
	int j = 0;
	for(int i = 0 ; i < n ;++i){
		if(!fre[i]){
			temp[j++] = t[i];
		}
	}

	int nTemp = j;
	j = 0; 
	for(int i = 0; i < nTemp; ++i){
		if(temp[i] == p[j]){
			++j;
		}
	}
	// printf("%d\n",j );
	// printf("%s\n",temp );
	return j == nP;
}



int main(){
	scanf("%s %s", t, p);
	n = strlen(t);
	nP = strlen(p);
	for(int i = 0; i < n;++i)
		scanf("%d", a + i);

	int i = 0, j = n;
	int mid;
	while( i <= j){
		mid = (i + j ) >> 1;
		if(check(mid))
			i = mid + 1;
		else
			j = mid - 1;
	}
	printf("%d\n", i - 1 );
}




