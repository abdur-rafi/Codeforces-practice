#include <bits/stdc++.h>

using namespace std;
const int MAX = 20000;
int main(){
    vector<int> div[MAX+1];
    for(int i=1;i<=MAX;++i){
        for(int j=1;j*j<=i;++j){
            if(i%j == 0){
                div[i].push_back(j);
                if(i/j != j) div[i].push_back(i/j);
            }
        }
    }
    for(int i=1;i<=MAX;++i) sort(div[i].begin(),div[i].end());

    int t;scanf("%d",&t);
    while(--t>=0){
        int a,b,c;scanf("%d %d %d",&a,&b,&c);
        int res = INT_MAX;
        vector<int> r;
         for(int i=1;i<=MAX;++i){
            for(int j=0;j<div[i].size();++j){
                int numb = div[i][j];
                auto p = upper_bound(div[numb].begin(),div[numb].end(),a);
                int cst = INT_MAX;
                if(p != div[numb].end()){
                    cst = abs(a-*p)+abs(b-numb)+abs(c-i);
                    if(cst < res){
                        res = cst;
                        vector<int> rr;
                        rr.push_back(*p);
                        rr.push_back(numb);
                        rr.push_back(i);
                        r = rr;
                    }
                }
                if(p != div[numb].begin()){
                    --p;
                    cst = abs(a-*p)+abs(b-numb)+abs(c-i);
                }
                if(cst < res){
                    res = cst;
                    vector<int> rr;
                    rr.push_back(*p);
                    rr.push_back(numb);
                    rr.push_back(i);
                    r = rr;
                }

            }
        }
        printf("%d\n",res);
        printf("%d %d %d\n",r[0],r[1],r[2]);
    }
}
