#include <cstdio>
#include <queue>
#include <set>
#include <utility>
using namespace std;

struct point{
	int x;
	int y;
	int n;
	char dir;
};

void count(int x, int y, set<pair<int,int>> &s){
	for(int i = 0; i <= x;++i){
		int cox = 2*i - x;
		for(int j = 0 ; j <= y;++j){
			int coy = 2*j - y;
			s.insert({cox,coy});
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	set<pair<int,int>> s;
	if(n % 2 ){
		count(n/2,(n/2)+1,s);
		count((n/2)+1,(n/2),s);
	}
	else{
		count(n/2,n/2,s);
	}
	printf("%d\n",s.size());

}