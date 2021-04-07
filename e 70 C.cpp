#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const ll MAX = 200000 + 10;
char str[MAX];

struct area {
	ll l, r, u, d;
}polls[MAX];

void transform(ll &x, ll &y,char c) {
	if (c == 'W')
		y++;
	else if (c == 'A') x--;
	else if (c == 'D') x++;
	else --y;
}
ll cost(ll x, ll y, area nxt,area curr) {
	curr.u = max(curr.u, y + nxt.u);
	curr.d = min(curr.d, y + nxt.d);
	curr.l = min(curr.l, x + nxt.l);
	curr.r = max(curr.r, x + nxt.r);
	return (curr.u - curr.d + 1) * (curr.r - curr.l + 1);
}
void count_polls( ) {
	ll n = strlen(str);
	ll x = 0, y = 0;
	polls[n].l = 0;
	polls[n].d = 0;
	polls[n].u = 0;
	polls[n].r = 0;
	for (ll i = n - 1; i >= 0; --i) {
		polls[i] = polls[i + 1];
		if (str[i] == 'W') {
			polls[i].u = polls[i + 1].u + 1;
			if (polls[i + 1].d) polls[i].d = polls[i + 1].d + 1;
		}
		else if (str[i] == 'S') {
			polls[i].d = polls[i + 1].d - 1;
			if (polls[i + 1].u) polls[i].u = polls[i + 1].u - 1;
		}
		else if (str[i] == 'A') {
			polls[i].l = polls[i + 1].l - 1;
			if (polls[i].r) polls[i].r = polls[i + 1].r - 1;
		}
		else {
			polls[i].r = polls[i + 1].r + 1;
			if (polls[i].l) polls[i].l = polls[i + 1].l + 1;
		}
	}
} 
int main() {
	ll t; scanf("%lld", &t);
	while (--t >= 0) {
		scanf("%s", str);
		count_polls();
		ll n = strlen(str);
		ll x = 0, y = 0;
		area curr = { 0,0,0,0 };
		ll i = 0;
		ll res = 1e15;
		ll x2, y2;
		x2 = x, y2 = y;
		transform(x2, y2, 'A');
		res = min(res, cost(x2, y2, polls[0], curr));
		x2 = x, y2 = y;
		transform(x2, y2, 'W');
		res = min(res, cost(x2, y2, polls[0], curr));
		x2 = x, y2 = y;
		transform(x2, y2, 'S');
		res = min(res, cost(x2, y2, polls[0], curr));
		x2 = x, y2 = y;
		transform(x2, y2, 'D');
		res = min(res, cost(x2, y2, polls[0], curr));
		while (str[i]) {
			transform(x, y, str[i]);
			curr.u = max(curr.u, y);
			curr.r = max(curr.r, x);
			curr.d = min(curr.d, y);
			curr.l = min(curr.l, x);
			x2 = x, y2 = y;
			transform(x2, y2, 'A');
			res = min(res, cost(x2, y2, polls[i+1], curr));
			x2 = x, y2 = y;
			transform(x2, y2, 'W');
			res = min(res, cost(x2, y2, polls[i+1], curr));
			x2 = x, y2 = y;
			transform(x2, y2, 'S');
			res = min(res, cost(x2, y2, polls[i+1], curr));
			x2 = x, y2 = y;
			transform(x2, y2, 'D');
			res = min(res, cost(x2, y2, polls[i+1], curr));
			++i;
		}
		printf("%lld\n", res);
	}
}