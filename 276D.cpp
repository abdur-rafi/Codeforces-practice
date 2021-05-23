#include <iostream>

using namespace std;

typedef unsigned long long ull;

int main(){

	ull l, r;
	cin >> l >> r;

	long long i = 63;
	ull one = 1;

	while(!( r & (one << i))){
		--i;
	}
	ull lA = l;
	ull rA = r;
	while(i > -1){
		ull m1 = one << i;
		ull li = l & m1;
		ull ri = r & m1;
		if(li != ri){
			--i;
			continue;
		}
		if(li == 0){
			ull lN = l | (one << i);
			if(lN > rA){
				ull mask = 0;
				mask = ~mask;
				mask = mask << i;
				mask = ~mask;
				ull rem = mask & lN;
				if( lN - rem <= rA){
					lN -= rem;
				}
				else{
					lN = l;
				}
			}
			l = lN;
		}
		else{
			ull rN = r ^ (one << i);
			if( rN < lA){
				ull mask = 0;
				mask = ~mask;
				mask = mask << i;
				mask = ~mask;
				ull rem = mask & rN;
				if(rN - rem + ((one << i) - 1)  >= lA){
					rN = rN - rem + ((one << i) - 1);
				}
				else{
					rN = r;
				}
			}
			r = rN;
		}
		--i;
	}
	cout << (l ^ r);

}

