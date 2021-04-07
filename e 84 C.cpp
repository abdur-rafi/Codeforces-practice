#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;scanf("%d %d %d",&n,&m,&k);
    int R = -1,U = -1;

    for(int i=0;i<k;++i){
        int x,y;scanf("%d %d",&x,&y);
        x--;y--;
        R = max(R,x);
        U = max(U,y);
    }
    for(int i=0;i<k;++i){
        int a,b;scanf("%d %d",&a,&b);
    }
    string res;
    for(int i=0;i<R;++i) res += 'U';
    for(int i=0;i<U;++i) res += 'L';
    int alt = 1;
    char turn;
    for(int i=0;i<m;++i){
        if(alt){
            turn = 'D';
            alt = 0;
        }
        else{
            turn = 'U';
            alt = 1;
        }
        for(int j = 0; j < n-1;++j) res += turn;
        if(i < m-1) res += 'R';

    }
    printf("%d\n",res.size());
    printf("%s",res.c_str());
}
