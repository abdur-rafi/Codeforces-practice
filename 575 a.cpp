#include <iostream>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    ll n;cin>>n;
    while(--n>=0){
    ll a,b,c;
    cin>>a>>b>>c;
    ll r=(a+b+c)/2;
    cout<<r<<'\n';
    }
    return 0;
}
