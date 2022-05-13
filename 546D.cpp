#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 5000000 + 10;
const int MAX_SQ = 2240;
int divisorCount[MAX];

void SieveOfEratosthenes(int n, vector<int> &primes){
	vector<bool> prime(n + 1, true);

    for (int p = 2; p * p <= n; p++){
        if (prime[p] == true){
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++)
        if (prime[p])
        	primes.push_back(p);
}
 


int main(){

	vector<int> primes;
	SieveOfEratosthenes(MAX_SQ, primes);
    // printf("%d\n",primes.size() );

    for(int i = 1; i < MAX; ++i){
        int curr = i;
        for(auto p : primes){
            int c = 0;
            while(curr % p == 0){
                ++c;
                curr /= p;
            }
            if(curr != i){
                divisorCount[i] = c + divisorCount[curr];
                curr = 1;
                break;
            }
        }
        if(curr != 1){
            divisorCount[curr]++;
        }
    }

    for(int i = 2; i < MAX; ++i)
        divisorCount[i] += divisorCount[i - 1];
    int t;
    scanf("%d", &t);
    while(t--){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n",divisorCount[a] - divisorCount[b] );
    }
    // printf("%d\n",divisorCount[100] );

}