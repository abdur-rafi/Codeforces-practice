#include <iostream>
#include <cstdio>
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    int a[n][m];
    int l[n][m];
    int res[n][m];
    int h[n][m];
    getchar();
    loop(i,n,0){
        loop(j,m,0){
            char c=getchar();
            a[i][j]=c-'a';
            l[i][j]=0;res[i][j]=0;
            h[i][j]=0;
        }
        getchar();
    }
    if(n<3){
        cout<<0;return 0;
    }
    for(int i=0;i<m;++i)l[n-1][i]=1;
    for(int i=n-2;i>=0;--i){
        for(int j=0;j<m;++j){
            if(a[i][j]==a[i+1][j])l[i][j]=l[i+1][j]+1;
            else l[i][j]=1;
        }
    }
    loop(i,n,0){
        loop(j,m,0){
            int c=l[i][j];
            if(c+i<n&&a[i][j]!=a[i+c][j]&&l[i+c][j]==c&&
               2*c+i<n&&a[i+c][j]!=a[i+c+c][j]&&
               l[i+c+c][j]>=c){
                   res[i][j]=3*c;
                   h[i][j] = a[i][j]+a[i+c][j]*100
                            +a[i+c+c][j]*10000;
            }
            else res[i][j]=0;
        }
    }
    ll r=0;
    int f=0;
    loop(i,n,0){
        loop(j,m,1){
            if(res[i][j-1]==res[i][j]&&h[i][j-1]==h[i][j])++f;
            else if(res[i][j-1]!=0){
                r += ((f+2)*(f+1))/2;
                f=0;
            }
            else f=0;
        }
        if(res[i][m-1]!=0){
            r+=((f+1)*(f+2))/2;
        }
        f=0;
    }
    cout <<r;
}
