#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>

using namespace std;


pair<string, string> transform(string &A, string &B){
	int n = A.size();
	char mnA = 'z';
	for(int i = 0; i < n; ++i)
		mnA = min(mnA, A[i]);
	char mnB = 'z';

	for(int i = 0; i < n; ++i){
		if(A[i] == mnA){
			mnB = min(mnB, B[i]);
		}
	}

	// cout << mnA << " " << mnB << "\n";

	for(int i = 0; i < n; ++i){
		if(A[i] == mnA)
			A[i] = mnB;
	}

	// cout << A << "\n";

	string AN, BN;

	for(int i = 0; i < n; ++i){
		if(A[i] != B[i]){
			AN += A[i];
			BN += B[i];
		}
	}


	return {AN, BN};
}


int main(){

	int t;
	cin >> t;
	while(--t >= 0){

		int n;
		cin >> n;

		string A, B;
		cin >> A >> B;

		bool pos = true;

		for(int i = 0; i < n; ++i){
			if(A[i] > B[i]){
				pos = false;
				break;
			}
		}

		if(!pos){
			cout << -1 << "\n";
			continue;
		}
		if(A == B){
			cout << 0 << "\n";
			continue;
		}

		string AN, BN;

		for(int i = 0; i < n; ++i){
			if(A[i] != B[i]){
				AN += A[i];
				BN += B[i];
			}
		}
		// cout << AN << " " << BN << "\n";

		int c = 1;

		pair<string, string> r = transform(AN, BN);
		while(r.first.size()){
			c++;
			r = transform(r.first, r.second);
		}

		// cout << r.first << " " << r.second << "\n";

		cout << c << "\n";
	}
}