#include <bits/stdc++.h>
using namespace std;
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
typedef unsigned long long ll;

vector<int> sieve(int n){
    vector<char> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    vector<int> primes;
    loop(i,(n+1),0){
        if(is_prime[i]) primes.push_back(i);
    }
    return primes;
}

int main(){
    int t;//scanf("%d",&t);
    t = 1;
    while(--t>=0){
        int n;scanf("%d",&n);
        int a[n];
        loop(i,n,0) scanf("%d",a+i);
        vector<int> primes = sieve(10000);
        vector<int> r1,r2;
        loop(i,n,0){
            vector<int> pr,fr;
            int curr = a[i];
            int curr2 = a[i];
            for(auto p:primes){
                if(p > curr) break;
                if(curr % p == 0){
                    pr.push_back(p);
                    fr.push_back(1);
                    while(curr % p == 0){
                        curr /= p;
                        fr[fr.size()-1] *= p;
                    }
                }
            }
            if(curr > 1){
                pr.push_back(curr);
                fr.push_back(curr);
            }
            if(pr.size()<2){
                r1.push_back(-1);
                r2.push_back(-1);
            }
            else{

                int r11 = -1,r22 = -1,r111 = -1;
                r11 = 1;
                loop(j,fr.size(),0) r11 *= fr[j];
                loop(j,pr.size(),0){
                    if(__gcd(curr2,(r11/pr[j])+pr[j]) == 1){
                        r111 = r11/pr[j];
                        r22 = pr[j];
                        break;
                    }
                }
                if(r22 != -1){
                    r1.push_back(r111);
                    r2.push_back(r22);
                }
                    /*
                int r11 = 1;
                loop(i,fr[0],0){
                    r11 *= pr[0];
                }
                r1.push_back(r11);

                int r22 = 1;
                loop(i,fr[fr.size()-1],0){
                    r22 *= pr[pr.size()-1];
                }
                r2.push_back(r22); */
            }
        }
        loop(i,n,0){
            printf("%d ",r1[i]);
        }
        printf("\n");
        loop(i,n,0){
            printf("%d ",r2[i]);
        }

    }
    return 0;
}
