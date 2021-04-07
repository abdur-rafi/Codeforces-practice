#include<bits/stdc++.h>

using namespace std;
void printDouble(long double h){
  //  cout<<fixed<<setprecision(9)<<h<<"\n";
}

int main(){
    int t;cin>>t;
    while(--t>=0){
        int n;cin>>n;
        long double theta = M_PI/(2*n);
        printDouble(theta);
        printDouble(sin(theta));
        long double r =(long double).5/sin(theta);
        printDouble(r);
        long double res = r - sin(theta)+cos(theta);
        printDouble(res);
        res *= 2;
        res /= sqrt(2);
        cout<<fixed<<setprecision(8)<<res<<"\n";
    }
}
