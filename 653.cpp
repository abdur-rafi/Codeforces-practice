#include <bits/stdc++.h>
using namespace std;
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
typedef long long ll;

struct node{
    int t;
    int a,b;
};

bool comp(node a,node b){
    return (a.t<b.t);
}

int main(){
       int n,k;scanf("%d %d",&n,&k);
       node arr[n];
       loop(i,n,0){
        int a,b,c;scanf("%d %d %d",&a,&b,&c);
        arr[i] = {a,b,c};
       }
       sort(arr,arr+n,comp);
       bool vis[n];
       loop(i,n,0) vis[i] = false;
        int alice = k, bob  = k;
        int res = 0;
        vector<int> Alice,Bob;
        for(int i=0;i<n;++i){
            if(alice == 0 && bob == 0) break;
            if(arr[i].a == 1 && arr[i].b == 1){
                if(alice == 0){
                    if(!Alice.empty()){
                        res -= Alice[Alice.size()-1] ;
                        Alice.pop_back();
                    }
                }
                alice = max(0,alice-1);
                if(bob == 0){

                    if(!Bob.empty()){
                        res -= Bob[Bob.size()-1];
                        Bob.pop_back();
                    }
                }
                bob = max(0,bob-1);
                vis[i] = true;
                res += arr[i].t;
            }
            else if(arr[i].a == 1 && alice > 0){
                --alice;
                vis[i] = true;
                res += arr[i].t;
                Alice.push_back(arr[i].t);
            }
            else if(arr[i].b == 1 && bob > 0 ){
                --bob;
                vis[i] = true;
                res += arr[i].t;
                Bob.push_back(arr[i].t);
            }
        }

    /*    for(node p:selected){
            printf("s: %d %d %d\n",p.t,p.a,p.b);
        }*/

        if(alice > 0 || bob > 0){
            printf("-1");
            return 0;
        }
     /*   vector<int> Alice,Bob;
        for(node p:selected){
            if(p.a && p.b){
                ;
            }
            else if(p.a) Alice.push_back(p.t);
            else Bob.push_back(p.t);
        } */
        vector<int> rep;
        loop(i,n,0){
            if(arr[i].a == 1 && arr[i].b == 1 && vis[i] == false){
                rep.push_back(arr[i].t);
            }
        }
        int i =(int) Alice.size() - 1;
        int j =(int) Bob.size() - 1;
    //    printf(" size: %d %d\n",i,j);

        if(!rep.empty()){
        for(auto time:rep){
            if((i < 0 )|| (j < 0)) break;
            if(time < (Alice[i]+Bob[j])){
                res -= Alice[i];
                res -= Bob[j];
                res += time;
                --i;
                --j;
            }
            else break;
        }
        }
        printf("%d\n",res);

    return 0;
}
