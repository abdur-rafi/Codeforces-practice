#include <cstdio>
using namespace std;


int main(){
    int t;scanf("%d",&t);
    while(--t>=0){

        int n;scanf("%d",&n);
        int a,b;scanf("%d %d",&a,&b);
        bool pos = 1;
        if(b>a) pos = 0;
        for(int i=1;i<n;++i){
            int c,d;scanf("%d %d",&c,&d);
            if(c<a ||d<b||d>c||(d-b)>(c-a) ) pos = 0;
            a = c;
            b = d;
        }
        if(!pos) printf("NO\n");
        else printf("YES\n");
    }

}
