 #include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<ll,ll>
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
#define f first
#define s second
PII getnext(vector<PII> &a,bool done[],int n,int curr){
    int r=INT_MIN;
    int ind=-1;
    for(int i=0;i<n;++i){
        if(done[i]) continue;
        if(a[i].f<=curr && r<a[i].s){
            r=a[i].s;
            ind=i;
        }
    }
    if(ind==-1) return {-1,-1};
    done[ind]=true;
    return a[ind];
}
int main(){
    ll n,r;scanf("%lld %lld",&n,&r);
    vector<PII> a;
    bool done[n];
    loop(i,n,0){
        ll d,e;
        scanf("%lld %lld",&d,&e);
        a.push_back({d,e});
        done[i]=false;
    }
    bool pos=true;
    for(int i=0;i<n;++i){
        PII d=getnext(a,done,n,r);
        if(d.f==-1){
            pos=false;break;
        }
        printf("r:%lld\n",r);
        for(int i=0;i<n;++i){
            if(!done[i]){
                printf("notdone:%d\n",i);
            }
        }
        r += d.s;
    }
    if(pos) printf("YES\n");
    else printf("NO\n");
    return 0;
}
