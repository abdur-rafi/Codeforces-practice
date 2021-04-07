#include <bits/stdc++.h>
using namespace std;

vector<int> SieveOfEratosthenes(int n) {
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
    for (int p=2; p*p<=n; p++) {
        if (prime[p] == true) {
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  	vector<int> pr;
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
         pr.push_back(p);

   	return pr;
} 

int MAX = 100000+100;

int main(){
	int t;scanf("%d",&t);
	vector<int> pr = SieveOfEratosthenes(MAX);
	while(--t>=0){
		int n;scanf("%d",&n);
		int rem = n;
		if(n % 2 == 0){
			printf("%d %d\n",n/2,n/2);
			continue;
		}
		vector<int> divPrimes;
		for(auto prime:pr){
			if(rem < prime) break;
			if(rem % prime == 0){
				while(rem % prime == 0){
					rem /= prime;
					divPrimes.push_back(prime);
				}
			}
		}
		if(rem != 1) divPrimes.push_back(rem);
		if(divPrimes.size() == 1){
			rem = divPrimes[0];
			printf("1 %d\n",rem - 1);
			continue;
		}
		sort(divPrimes.begin(),divPrimes.end());
		int a = 1,b = 1;
		for(int i=1;i<divPrimes.size();++i)
			a *= divPrimes[i]; 
		b = a;
		b *= divPrimes[0]-1;

		printf("%d %d\n",a,b);
	}
	return 0;
}