#include <iostream>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)

int main(){
    ll n;
    cin >> n;
    while(1){
        ll s=0;
        ll b=n;
        while(n){
            s += n%10;
        n /= 10;
        }
        if(s%4 == 0){
            cout << b;
            return 0;
        }
        ++b;
        n=b;
    }
    return 0;
}

