#include <cstdio>
#include <vector>

using namespace std;

bool check(int f1, int f2, int m){
	int f = 0, s = 0;
	for(int i = 0; i < m; ++i){
		if( i % 2){
			s += f2;
			if(s <= f){
				// printf("NO\n");
				return 0;
			}
		}
		else{
			f += f1;
			if(f <= s){
				// printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	for(int i = 0; i < m; ++i){
		if( i % 2){
			printf("%d ",f2 );
		}
		else{
			printf("%d ",f1 );
		}
	}
	return 1;
}

int main(){
	char str[11];
	scanf("%s", str);

	vector<int> d;

	for(int i = 0; i < 10; ++i){
		if(str[i] != '0') d.push_back(i + 1);
	}

	int m;scanf("%d", &m);


	if(d.size() < 2){
		if(m > 1)
			printf("NO\n");
		else 
			printf("YES\n%d", d[0]);
		return 0;	
	}

	if(d.size() == 2){
		if(!check(d[0], d[1], m))
			printf("NO\n");
		return 0;
	}



	for(int i = 0; i  < d.size();++i){
		for(int k = i + 1; k < d.size(); ++k){
			for(int l = k + 1; l < d.size(); ++l){

				int f = d[i], e = d[l], mid = d[k];
				if(f + e < 2 * mid){
					bool t = true;
					printf("YES\n");
					printf("%d %d %d\n",f,e,mid );
					for(int j = 0; j < m; ++j){
						if(j % 2){
							printf("%d ",mid );
						}
						else{
							printf("%d ",t ? f : e );
							t = !t;
						}
					}
					return 0;
				}
			}
		}
	}

	for(int i = 0; i < d.size(); ++i){
		for(int j = i + 1; j < d.size(); ++j)
			if(check(d[i], d[j],m)) return 0;
	}

	printf("NO\n");

	return 0;

}