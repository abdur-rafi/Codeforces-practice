#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> solve(int n, char a[], char b[]){
	int flipCount = 0 ;
	vector<int> res;
	int f = 0;
	for(int i = n - 1; i > -1; --i){
		f = flipCount / 2 ;
		f = (flipCount % 2) ? n - 1 - f   : f;
		int a_val = a[f] - '0';
		if(flipCount % 2 ) a_val = (a_val+1) % 2;
		if(a_val != (b[i] - '0')){
			res.push_back(i);
		}
		else{
			
			if(i != 0){
				res.push_back(0);
				res.push_back(i);
			}
		}

		++flipCount;
	}
	return res;
}

int main(){
	int t;
	scanf("%d", &t);
	while(--t>=0){
		int n;
		scanf("%d", &n);
		char a[n + 10], b[n + 10];
		scanf("%s %s", a,b);
		vector<int> res = solve(n, a, b);
		printf("%d ",res.size() );
		for(auto v : res){
			printf("%d ",v+1 );
		}
		printf("\n");
	}
}