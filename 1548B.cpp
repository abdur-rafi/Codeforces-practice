#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
typedef long long ll;




class segTree
{
    ll *segarr;
    ll n;
    ll constructTreeUtil(ll arr[],ll si,ll as,ll ae);
    ll queryUtil(ll qs,ll qe,ll ss,ll se,ll si);
    ll _gcd(ll a, ll b)
    {
        if (b==0)return a;
        return _gcd(b, a % b);   
    }

public:
    segTree(ll arr[],ll N);
    ll query(ll as, ll ae);
};
segTree::segTree(ll arr[],ll N)
{
    n = N;
    ll x = (ll)(ceil(log2(n)));
    ll s = 2*(ll)pow(2,x) - 1;
    segarr = new ll[s];
    constructTreeUtil(arr,0,0,n-1);
}
ll segTree::constructTreeUtil(ll arr[],ll si,ll as,ll ae)
{
    if(as == ae)
    {
        segarr[si] = arr[as];
        return arr[as];
    }
    ll mid = (as+ae) >> 1;
    ll l = constructTreeUtil(arr,2*si+1,as,mid);
    ll r = constructTreeUtil(arr,2*si+2,mid+1,ae);
    ll h = _gcd(l,r);
    segarr[si] = h;
    return h;
}
ll segTree::query(ll qs,ll qe)
{
    return queryUtil(qs,qe,0,n-1,0);
}
ll segTree::queryUtil(ll qs,ll qe,ll ss,ll se,ll si)
{
    if(qs <= ss && qe >= se)
        return segarr[si];
    if(se < qs || ss > qe )
        return -1;
    ll m = (ss+se) >> 1;
    ll l = queryUtil(qs,qe,ss,m,2*si+1);
    ll r = queryUtil(qs,qe,m+1,se,2*si+2);
    if(l == -1) return r;
    if(r == -1) return l;
    return _gcd(l,r);
}


int main(){

    int t;scanf("%d", &t);
    while(--t>= 0){
        int n;scanf("%d", &n);
        ll a[n];
        for(int i = 0; i < n; ++i) scanf("%lld", a + i);
        if(n == 1){
            printf("1\n");
            continue;
        }
        ll b[n-1];
        for(int i = 0; i < n - 1; ++i){
            b[i] = abs(a[i + 1] - a[i]);
        }
        segTree tree(b, n - 1);
        int res = 0;
        int l = 0;
        int r = 0;
        // for(int i = 0; i < n - 1; ++i) printf("%lld ",b[i] );
        // printf("\n");
        while(r < n - 1){
            // printf("%d %d\n",l, r );
            if(tree.query(l, r) == 1){
                ++l; ++r;
            }
            else{
                res = max(res, r - l + 1);
                ++r;
            }
        }
        printf("%d\n", res + 1);
    }

    return 0;
}