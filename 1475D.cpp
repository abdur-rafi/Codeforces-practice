#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

bool comp(pair<ll, ll> &a, pair<ll, ll> &b){
	if(a.first == b.first) return b.second < a.second;
	return a.first < b.first;
}

int main(){

	int t;scanf("%d", &t);
	while( --t >= 0){
		ll n, m;
		scanf("%lld %lld", &n, &m);
		ll memory[n];
		for(int i = 0; i < n; ++i) scanf("%lld", memory + i);
		ll conv[n];
		for(int i = 0; i < n; ++i) scanf("%lld", conv + i);
		pair<ll, ll> p[n];
		for(int i = 0; i < n; ++i){
			p[i].first = memory[i];
			p[i].second = conv[i];
		}
		sort(p, p + n, comp);
		// printf("\n");
		// for(int i = 0; i < n; ++i) printf("%lld %lld\n",p[i].first, p[i].second );
		// printf("\n");
		vector<ll> selected2s, remaining1s;

		ll freedMemory = 0;
		ll totConv = 0;
		for(int i = n - 1; i > -1 ; --i){
			if(freedMemory >= m){
				if(p[i].second == 1){
					remaining1s.push_back(p[i].first);
				}
			}
			else{

				freedMemory += p[i].first;
				totConv += p[i].second;
				if(p[i].second == 2) selected2s.push_back(p[i].first);
			}
		}

		if(freedMemory < m){
			printf("-1\n");
			continue;
		}

		sort(selected2s.begin(), selected2s.end());
		sort(remaining1s.begin(), remaining1s.end());
		int j = 0;
		for(int i = remaining1s.size() - 1; i > -1 && j < selected2s.size(); --i){
			if(freedMemory - selected2s[j] + remaining1s[i] >= m){
				freedMemory = freedMemory - selected2s[j] + remaining1s[i];
				--totConv;
				++j;
			}
			else
				break;
		}
		printf("%lld\n",totConv );
	}
}