#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 200000;

int main(){
   // printf("%llf\n",sin(30));
    ll t;cin>>t;
    while(--t>=0){
        int n;cin>>n;
        double angle = 2*M_PI;
        angle /= 4.0*n;
        double h = 1 / tan(angle);
     //   h /= sqrt(2);
      //  h *= h;
        cout << fixed << setprecision(9)<<h<<"\n";
    }
}
