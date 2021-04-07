#include <bits/stdc++.h>

#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
using namespace std;

int MOD = (1e9) + 7;
const int MAX = 300000+100;


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
		vector<int> length;
		int minus = 0;
		for(int i=fr.size()-1;i>=0;--i){
			int f = fr[i] - minus;
			minus = fr[i];
			int sz = fr.size();
			loop(i,f,0) length.push_back(sz);
			fr.pop_back();
		}

		sort(length.begin(),length.end());

		int mn = length[1] - 1;

		priority_queue<int> pq;
		for(auto len : length) pq.push(len-1);

		int sz = length.size();
		if(sz == 2){
			printf("%d\n",length[1]-1 );
			continue;
		}

		// printf("length\n");
		// for(auto len : length){
		// 	printf("%d\n",len );
		// }

		int last = 1;
		int mnn = 1e9;
		loop(i,sz-1,0){

			int mx = pq.top();
			// printf("mx : %d\n",mx );
			if((mx / 2) <= (length[i+1]-1)) break;
			pq.pop();
			pq.push(mx / 2);
			pq.push((mx / 2) + mx % 2);
			mnn = min(mnn,(mx/2));
			++last;

		}
		mn = length[last]-1;
		mn = min(mn,mnn);
		printf("%d\n",mn );

	}
}