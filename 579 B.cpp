 #include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    int q;scanf("%d",&q);
    while(--q>=0){
        int n;scanf("%d",&n);
        int a[4*n];
        loop(i,4*n,0) scanf("%d",a+i);
        map<int,int> m;
        loop(i,4*n,0){
            m[a[i]]++;
        }
        vector<PII> b;
        for(auto p:m){
            b.push_back(p);
        }
        bool pos=true;
        int i=0;
        int j=b.size()-1;
        int area=b[0].first*b[b.size()-1].first;
        while(i<=j){
            if(b[i].first*b[j].first!=area || b[i].second!=b[j].second || b[i].second % 2 !=0){
                pos=false;break;
            }
            if(i==j && b[i].second % 4!=0){
                pos=false;break;
            }
            i++;j--;
        }
        if(pos) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
