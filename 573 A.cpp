#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)

int main(){
    int x;cin>>x;
    int a=x+0;
    char r='F';
    int r1=0;
    if((a%4)==1 || (a+1)%4==1 || (a+2)%4==1){
        cout<<abs((a%4)-1) <<' '<<'A';
    }
    else if((a)%4==3 || (a+1)%4==3 || (a+2)%4==3){
        cout<<abs((a%4)-3) <<' '<<'B';
    }
    else if(a%4==2 || (a+1)%4==2 || (a+2)%4==2){
        cout<<abs((a%4)-2) <<' '<<'C';
    }

    return 0;
}
