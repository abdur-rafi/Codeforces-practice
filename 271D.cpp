#include <cstdio>
#include <string>
#include <set>
#include <cstring>

using namespace std;

char str[2000];

int main(){

	scanf("%s", str);
	char b[27];
	scanf("%s", b);
	bool bad[26];
	for(int i = 0; i < 26; ++i){
		bad[i] = b[i] == '0';
	}
	int k;
	scanf("%d", &k);

	set<string> s;
	int n = strlen(str);
	for(int i = 0; i < n; ++i){
		int c = 0;
		string currSubstr = "";
		for(int j = i; j < n; ++j){
			currSubstr += str[j];
			c += bad[str[j] - 'a'];
			if(c > k ){
				break;
			}
			s.insert(currSubstr);
		}
	}

	printf("%d\n",s.size() );

}