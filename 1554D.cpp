#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
	int t;
	cin >> t;
	// scanf("%d", &t);
	while(--t>=0){
		int n;cin >> n;
		if(n == 1){
			cout << "a"; 
		}
		else if(n == 2){
			cout << "ab";
		}
		else if(n % 2){
			int k = (n - 1) / 2;
			cout << string(k, 'a') << "bc" << string( k-1, 'a');
		}
		else{
			int k = (n) / 2;
			cout << string(k, 'a') << "b" << string(k-1, 'a');
			
		}
		cout<<"\n";
	}

}