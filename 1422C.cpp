#include <iostream>
#include <cstdio>
#include <cstring>

typedef long long int lli;
const lli MOD = (1e9) + 7;
const lli N = 1000000;
char inpString[N];
lli preSum[N] = {0};

int main(){

	scanf("%s", inpString);

	lli n = strlen(inpString);
	lli mul = 1;

	preSum[0] = 1;

	for(lli i = 1; i <= n ; ++i){
		mul = (mul * 10) % MOD;
		preSum[i] = (preSum[i-1] + mul * (i + 1)) % MOD;
	}

	// presum[i] = 1 * 10^0 + 2 * 10 ^ 1 + 3 * 10^2 +....+ (i+1) * 10^i

	mul = 1;
	lli res = 0;

	lli tsum = 0;

	for(lli i = 0; i < n; ++i){
		lli left = n - i - 1;
		lli right = i;
		lli curr = 0;
		lli digit = inpString[n - i - 1] - '0';
		curr += ((((left * (left + 1)) / 2 * mul) % MOD)  * digit) % MOD;
		if(right > 0)
			curr += (preSum[right - 1] * digit) % MOD;
		curr += digit * mul;

		tsum = (mul * digit + tsum) % MOD;
		mul = (mul * 10) % MOD;
		res = (curr + res) % MOD;
	}

	printf("%lld\n",(res - tsum + MOD) % MOD );

	// 0, 1, 3, 23, 13, 12
}