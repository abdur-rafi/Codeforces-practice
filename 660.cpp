#include <bits/stdc++.h>

#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
using namespace std;

int sumChild(vector<int> adj[],int i,int p[],int sum[],int parent){
	int s = p[i];
	// printf("i : %d\n",i);
	for(auto v : adj[i]){
		if(v != parent)
			s += sumChild(adj,v,p,sum,i);
	}
	sum[i] = s;
	return s;
}

int check(vector<int> adj[],int i,int p[],int h[],int sum[],int parent){
	
	if(sum[i] < h[i]) return -1;

	int tot = sum[i] + h[i];
	if((tot % 2 == 1) || tot < 0) return -1;
	int happy = tot/2;
	int hc = happy;
	// printf("i : %d h : %d\n",i,happy);
	// if( adj[i].size() == 1) return happy;

	for(auto v : adj[i]){
		if(v != parent){
			int r = check(adj,v,p,h,sum,i);
			if(r == -1) return -1;
			happy -= r;
			if(happy < 0) return -1;
		}
	}
	// printf("i : %d h : %d\n",i,happy);
	// if(happy > p[i] ) return -1;


	return hc;

}


int main(){
	int t = 1;
	scanf("%d",&t);
	while(--t>=0){
		int n;scanf("%d",&n);
		if(n == 36){
			printf("Yes\n");
			printf("6 10 15 5\n");
		}
		else if(n == 40){
			printf("Yes\n");
			printf("6 10 15 9\n");
		}
		else if(n == 44){
			printf("Yes\n");
			printf("6 10 21 7\n");
		}
		else{
			if(n <= 30){
				printf("No\n");
				continue;
			}
			printf("Yes\n");
			printf("6 10 14 ");
			printf("%d\n",n-30 );
		}
		
	}


}