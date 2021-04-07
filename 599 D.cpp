#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll MAX = 1000000+100;
bool prime[MAX+10];
vector<ll> pr; 

void SieveOfEratosthenes(ll n)
{
    for (ll p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (ll i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }

    for (ll p=2; p<=n; p++)
       if (prime[p])
          pr.push_back(p);
}

int main(){
	for (ll i = 0; i <= MAX; ++i) prime[i] = true;
    SieveOfEratosthenes(MAX);
	ll c = 0;
	ll r = 1e16;
	ll n; scanf("%lld", &n);
	for (auto d : pr) {
		if (n % d == 0) {
			r = min(d, r);
			++c;
			while (n % d == 0)	n /= d;
		}
	}
	if (n != 1) {
		++c;
		r = min(r, n);
	}
	if (c > 1 || c == 0) {
		printf("1");
	}
	else printf("%lld", r);
}
