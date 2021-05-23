#include <bits/stdc++.h>

#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
using namespace std;

int MOD = (1e9) + 7;
const int MAX = 300000+100;


bool check(vector<int> fre, int gap){
	int fFre = fre[0];
	int i = 0;
	while(i + 1 < fre.size() && fre[i+1] == fFre){
		i++;
		--gap;
	}
	++i;
	// printf("gap: %d\n",gap);
	ll sum = 0;
	while(i < fre.size()){
		sum += fre[i++];
	}
	ll a = gap;
	a *= fFre - 1;
	return sum >= a;
}

int main(){
	int t = 1;
	scanf("%d",&t);
	while(--t >=0){
		int n;scanf("%d",&n);
		int a[n];
		loop(i,n,0) scanf("%d",a+i);
		int fre[n+1];
		loop(i,n+1,0) fre[i] = 0;
		loop(i,n,0) fre[a[i]]++;
		vector<int> fr;
		loop(i,n+1,0){
			if(fre[i] != 0) fr.push_back(fre[i]);
		}
		sort(fr.begin(),fr.end());
		reverse(fr.begin(),fr.end());
		// for(auto v: fr) printf("%d\n",v );
		int i = 0, j = n, mid = 0;
		while(i <= j){
			mid = (i + j) >> 1;
			if(check(fr, mid)){
				i = mid + 1;
			}
			else{
				j = mid - 1;
			}
		}

		printf("%d\n",i - 1 );
	}
}