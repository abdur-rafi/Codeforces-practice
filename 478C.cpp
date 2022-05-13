#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){
	ll s[3];
	cin >> s[0] >> s[1] >> s[2];
	sort(s, s + 3);
	ll res = 0, diff = 0;
	if(s[2] >= 2 * (s[0] + s[1])){
		cout << s[0] + s[1] ;
	}
	else{
		diff = s[1] - s[0];
		// cout << diff << "\n";
		// cout << s[2] - 2 * diff << "\n";
		if(s[2] - 2 * diff >= s[1] - diff){
			res = diff;
			s[2] -= 2 * diff;
			s[1] = s[0];
			// cout << s[0] << " "  << s[1] << " " << s[2] << "\n";
			// cout << res << "\n";
			diff = s[2] - s[1];
			ll x = diff / 3;

			if(s[0] >= x){
				res += 2* x + s[0] - x;
			}
			else{
				res += 2 * s[0];
			}
		}
		else{
			diff = s[2] - s[1];
			res = diff;
			s[1] -= diff;
			s[2] -= 2 * diff;
			// cout << s[0] << " "  << s[1] << " " << s[2] << "\n";
			diff = s[1] - s[0];
			res += (2 * (diff / 3)) + s[0];
			if (diff % 3 == 2)
				res++;
		}
		cout << res;
	}

}