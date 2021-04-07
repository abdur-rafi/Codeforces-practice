 #include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    int n;cin>>n;
    string s;cin>>s;
    int a[10];
    for(int i=0;i<10;++i) a[i]=0;
    for(auto c:s){
        if(c =='L'){
            int i;
            for( i=0;a[i]!=0;++i) ;
            a[i]=1;
        }
        else if(c=='R'){
            int j;
            for( j=9;a[j]!=0;--j) ;
            a[j]=1;
        }
        else{
            a[c-'0']=0;
        }
    }
    for(auto p:a) cout<<p;
    return 0;
}
