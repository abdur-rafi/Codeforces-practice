#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)

int main(){
    int n,m;scanf("%d %d",&n,&m);
    int box[n];
    loop(i,n,0) box[i] = 0;
    int color[m];
    loop(i,m,0) scanf("%d",color+i);
    int i = 0;
    int index[m];
    loop(i,m,0) index[i] = i;
    int lft = m-1+color[m-1]-1;
    lft = n-1-lft;
    if(lft < 0){
        printf("-1");
        return 0;
    }

    int shift[m];
    loop(i,m,0) shift[i] = 0;
    loop(i,m-1,0){
        if(color[i]-1<=lft){
            shift[i] = color[i] - 1;
            lft -= color[i] - 1;
        }
        else{
            shift[i] = lft;
            lft = 0;
            break;
        }
    }
    if(lft){
        printf("-1");
        return 0;
    }
    int pre = 0;
    loop(i,m,1){
        index[i] += shift[i-1]+pre;
        pre += shift[i-1];
    }
    loop(i,m,0){
        printf("%d ",index[i]+1);
    }

    return 0;
}
