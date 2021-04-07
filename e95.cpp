#include <bits/stdc++.h>

#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
using namespace std;

int MOD = (1e9) + 7;
const int MAX = 200000+100;

void test(int i = 0){
    printf("here %d\n",i);
}

int main(){
	int t = 1;
	// scanf("%d",&t);
	while(--t >=0){
		int n,q;
		scanf("%d %d",&n,&q);
		int a[n];
		loop(i,n,0) scanf("%d",a+i);
		sort(a,a+n);
		int mx = 0;
		loop(i,n,1){
			mx = max(mx,a[i]-a[i-1]);
		}

		set<int> s;
		multiset<int> diffs;
		loop(i,n,0) s.insert(a[i]);
		loop(i,n,1) diffs.insert(a[i]-a[i-1]);
		int f = a[0];
		int l = a[n-1];


		printf("%d\n",l-f-mx );

		loop(i,q,0){
			int x,y;scanf("%d %d",&x,&y);
			printf("i : %d\n",i);
			if(s.size() == 0){
                s.insert(y);
                continue;
			}
			if(x == 0){
				set<int>::iterator up,low;
				auto itr = s.upper_bound(y);
				up = itr;

				if(itr != s.end()){
					int d = (*itr) - y;
					diffs.erase(diffs.lower_bound(d));
				}

				test();

				itr = s.lower_bound(y);
				printf("diffs.size() :  %d\n",s.size());
				low = itr;
				if(itr != s.begin()){
					--itr;
					int d = y - (*itr);
					diffs.erase(diffs.lower_bound(d));
				}

				if(low != s.begin() && up != s.end()){
					diffs.insert((*up) - (*low));

				}

				s.erase(y);

				int b = *s.begin();
				 auto var = s.end();
				 --var;
				 int e = *var;
				 auto var2 = diffs.end();
				 --var2;
				 int f = *var2;
				 printf("%d\n",e-b-f);
			}
			else{
				set<int>::iterator up,low;
				s.insert(y);
				auto itr = s.upper_bound(y);
				up = itr;
				if(itr != s.end()){
					int d = (*itr) - y;
					diffs.insert(*diffs.lower_bound(d));
				}
				itr = s.lower_bound(y);
				low = itr;
				if(itr != s.begin()){
					--itr;
					int d = y - (*itr);
					diffs.insert(*diffs.lower_bound(d));
				}

				if(low != s.begin() && up != s.end()){
					diffs.erase(diffs.lower_bound((*up) - (*low)));
				}
				int b = *s.begin();
				 auto var = s.end();
				 --var;
				 int e = *var;
				 auto var2 = diffs.end();
				 --var2;
				 int f = *var2;
				 printf("%d\n",e-b-f);
			}
		}

	}
}
