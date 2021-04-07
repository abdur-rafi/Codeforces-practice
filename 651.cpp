
#include <bits/stdc++.h>
using namespace std;
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
typedef unsigned long long ll;

vector<int> SieveOfEratosthenes(int n){
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++){
        if (prime[p] == true) {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
    vector<int> pr;
    loop(i,(n+1),2){
        if(prime[i]) pr.push_back(i);
    }
    return pr;
}


int main(){
    vector<int> primes = SieveOfEratosthenes(1000000);
    int t = 1;scanf("%d",&t);
    while(--t>=0){
       int n;scanf("%d",&n);
       if( n == 1){
        printf("FastestFinger\n");
       }
       else if(n % 2 == 1 || n == 2){
            printf("Ashishgup\n");
       }
       else if(n % 2 == 0){
        int n2 = n;
        while(n2 % 2 == 0){
            n2 /= 2;
        }
        if(n2 == 1){
            printf("FastestFinger\n");
        }
        else{
            int rem = n / n2;
            if(rem > 2){
                printf("Ashishgup\n");
            }
            else{
                bool pr = false;
                int c = 0;
                for(auto pr:primes){
                    while(n2 % pr == 0){
                        n2/=pr;
                        ++c;
                    }
                }
                if(n2 > 1) ++c;
                if(c <= 1){
                    printf("FastestFinger\n");
                }
                else{
                printf("Ashishgup\n");

                }
            }
        }
        }
    }
    return 0;
}
