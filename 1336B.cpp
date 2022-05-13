#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;
typedef long long ll;

ll bs(ll arr[], ll val, ll n, bool upper){
	ll i = 0;
	ll j = n - 1;
	ll m;
	while(i <= j){
		m = (i + j) >> 1;
		if(upper){
			if(arr[m] < val)
				i = m + 1;
			else
				j = m - 1;
		}
		else{
			if(arr[m] > val){
				j = m - 1;
			}
			else{
				i = m + 1;
			}
		}
	}
	if(upper) return j + 1;
	return i - 1;
}

int main(){

	int _;
	scanf("%d", &_);
	while(_--){

		ll nr, ng, nb;
		scanf("%lld %lld %lld", &nr, &ng, &nb);
		ll redGems[nr], greenGems[ng], blueGems[nb];
		for(int i = 0; i < nr; ++i) scanf("%lld", redGems + i);
		for(int i = 0; i < ng; ++i) scanf("%lld", greenGems + i);
		for(int i = 0; i < nb; ++i) scanf("%lld", blueGems + i);


		// printf("here\n");
		ll mn = LLONG_MAX;

		sort(redGems, redGems + nr);
		sort(greenGems, greenGems + ng);
		sort(blueGems, blueGems + nb);


		for(int i = 0; i < nr; ++i){
			ll currRed = redGems[i];
			for(int j = 0; j < 2; ++j){
				ll currGreen = bs(greenGems, currRed, ng, j % 2 == 0);
				// printf("currGreen index : %llu\n", currGreen);
				if(currGreen >= 0 && currGreen < ng){
					// printf("here\n");
					currGreen = greenGems[currGreen];
					for(int k = 0; k < 2; ++k){
						ll currBlue = bs(blueGems, currGreen, nb, k % 2 == 0);
						if(currBlue >= 0 && currBlue < nb){
							currBlue = blueGems[currBlue];
							ll curr = (currRed - currGreen) * (currRed - currGreen);
							curr += (currGreen - currBlue) * (currGreen - currBlue);
							curr += (currBlue - currRed) * (currBlue - currRed);
							// printf("%llu\n",curr );
							mn = min(curr, mn);
						}
					}

				}
			}
			// for(int j = 0; j < 2; ++j){
			// 	ll currBlue = bs(blueGems, currRed, nb, j % 2 == 0);
			// 	// printf("currGreen index : %llu\n", currGreen);
			// 	if(currBlue >= 0 && currBlue < nb){
			// 		// printf("here\n");
			// 		currBlue = blueGems[currBlue];
			// 		for(int k = 0; k < 2; ++k){
			// 			ll currGreen = bs(greenGems, currBlue, ng, k % 2 == 0);
			// 			if(currGreen >= 0 && currGreen < ng){
			// 				currGreen = greenGems[currGreen];
			// 				ll curr = (currRed - currGreen) * (currRed - currGreen);
			// 				curr += (currGreen - currBlue) * (currGreen - currBlue);
			// 				curr += (currBlue - currRed) * (currBlue - currRed);
			// 				// printf("%llu\n",curr );
			// 				mn = min(curr, mn);
			// 			}
			// 		}

			// 	}
			// }


		}


		for(int i = 0; i < ng; ++i){
			ll currGreen = greenGems[i];
			for(int j = 0; j < 2; ++j){
				ll currRed = bs(redGems, currGreen, nr, j % 2 == 0);
				// printf("currGreen index : %llu\n", currGreen);
				if(currRed >= 0 && currRed < nr){
					// printf("here\n");
					currRed = redGems[currRed];
					for(int k = 0; k < 2; ++k){
						ll currBlue = bs(blueGems, currRed, nb, k % 2 == 0);
						if(currBlue >= 0 && currBlue < nb){
							currBlue = blueGems[currBlue];
							ll curr = (currRed - currGreen) * (currRed - currGreen);
							curr += (currGreen - currBlue) * (currGreen - currBlue);
							curr += (currBlue - currRed) * (currBlue - currRed);
							// printf("%llu\n",curr );
							mn = min(curr, mn);
						}
					}

				}
			}
		}

		for(int i = 0; i < nb; ++i){
			ll currBlue = blueGems[i];
			for(int j = 0; j < 2; ++j){
				ll currGreen = bs(greenGems, currBlue, ng, j % 2 == 0);
				// printf("currGreen index : %llu\n", currGreen);
				if(currGreen >= 0 && currGreen < ng){
					// printf("here\n");
					currGreen = greenGems[currGreen];
					for(int k = 0; k < 2; ++k){
						ll currRed = bs(redGems, currGreen, nr, k % 2 == 0);
						if(currRed >= 0 && currRed < nr){
							currRed = redGems[currRed];
							ll curr = (currRed - currGreen) * (currRed - currGreen);
							curr += (currGreen - currBlue) * (currGreen - currBlue);
							curr += (currBlue - currRed) * (currBlue - currRed);
							// printf("%llu\n",curr );
							mn = min(curr, mn);
						}
					}

				}
			}


		}




		printf("%lld\n",mn );


	}
}