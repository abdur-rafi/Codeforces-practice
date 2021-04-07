 #include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    int n;scanf("%d",&n);
    int a[n];loop(i,n,0) scanf("%d",a+i);
    int m;scanf("%d",&m);
    int b[m];loop(i,m,0) scanf("%d",b+i);
    sort(a,a+n);
    sort(b,b+m);

    printf("%d %d",a[n-1],b[m-1]);
    return 0;
}
