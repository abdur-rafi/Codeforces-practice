 #include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
bool counter(int a[],int n,int b){
    int d=(b-1+n)%n;
    do{
        if((a[b]-1)!=a[(b+1)%n]) return false;
        b=(b+1)%n;
    }while(b!=d);
    return true;
}
bool clock(int a[],int n,int b){
    int d=(b-1+n)%n;
    do{
        if((a[b]+1)!=a[(b+1)%n]) return false;
        b=(b+1)%n;
    }while(b!=d);
    return true;
}
int main(){
    int q;scanf("%d",&q);
    while(--q>=0){
        int n;scanf("%d",&n);
        int a[n];
        int b=0;
        int e=0;
        loop(i,n,0){
            scanf("%d",&a[i]);
            if(a[i]==1) b=i;
            else if(a[i]==n) e=i;
        }
        if(n==1||counter(a,n,e)||clock(a,n,b))
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
