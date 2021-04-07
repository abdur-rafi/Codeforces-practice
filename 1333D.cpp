#include <bits/stdc++.h>
using namespace std;

struct info{
    int index;
    int left;
    int right;
    int startTime;
    void show(){
        printf("%d %d %d %d\n",index,left,right,startTime);
    }
};

int main(){
    int n,k;scanf("%d %d",&n,&k);
    char str[n+10];
    scanf("%s",str);
    vector<info> v;
    int left = 0;
    for(int i=0;str[i];++i){
        if(str[i]=='R') ++left;
        if(str[i] == 'R' && str[i+1] == 'L'){
            int fr = 0;
            int j = i+1;
            while(str[j++] == 'L') ++fr;
            if(v.empty()){
                v.push_back({i,left,fr,1});
            }
            else{
                auto prev = v.rbegin();
                int extraLeft= left-prev->left;
                int extraRight = prev->right;
                v.push_back({i,left,fr,prev->startTime+max(extraRight-extraLeft,0)});
            }
        }

    }
    for(auto p:v) p.show();


}
