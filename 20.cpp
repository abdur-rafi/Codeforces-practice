#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;scanf("%d",&t)    ;
    while(--t>=0){
        int n;scanf("%d",&n);
        char str[n];
        scanf("%s",str);
        string temp(str);
        string res(str);
        int r = 1;
        for(int i=1;i<n;++i){
            string temp;
            for(int j=i;j<n;++j) temp+=str[j];
            int fr = n-i;
            if(fr%2 == 0){
                for(int k = 0; k < i;++k) temp += str[k];
            }
            else{
                 for(int k = i-1; k > -1;--k) temp += str[k];
            }
            if(temp < res){
                r = i+1;
                res = temp;
            }

        }
        printf("%s\n",res.c_str());
        printf("%d\n",r);

    }

}
