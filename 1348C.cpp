#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        int n,k;scanf("%d %d",&n,&k);
        char str[n+1];
        scanf("%s",str);
        sort(str,str+n);
        int fr = 1;
        set<char> st;
        for(int i=0;i<n;++i){
            if(str[i] != str[i+1])
                break;
            ++fr;
        }
        for(int i=0;i<n;++i) st.insert(str[i]);
        if(fr == n){
            int fr2 = fr/k;
            fr2 += (fr%k)?1:0;
            for(int j=0;j<fr2;++j) printf("%c",str[0]);
        }
        else if(fr>k ||(fr==k && st.size()!=2)){
            printf("%c",str[0]);
            for(int i=k;i<n;++i) printf("%c",str[i]);

        }
        else if(fr<k)
            printf("%c",str[k-1]);
        else{
            string arr[k];
            for(int i=0;i<n;++i){
                arr[i%k]+=str[i];
            }
            printf("%s",arr[(n-1)%k].c_str());
        }
        printf("\n");
    }
}
