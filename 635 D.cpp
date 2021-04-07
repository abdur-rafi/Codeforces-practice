#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main(){
    int t;scanf("%d",&t);
    while(--t>=0){

        int nr,ng,nb;scanf("%d %d %d",&nr,&ng,&nb);
        ull red[nr],green[ng],blue[nb];

        for(int i=0;i<nr;++i) scanf("%llu",red+i);
        for(int i=0;i<ng;++i) scanf("%llu",green+i);
        for(int i=0;i<nb;++i) scanf("%llu",blue+i);

        sort(red,red+nr);
        sort(green,green+ng);
        sort(blue,blue+nb);
        int f = 0;
        ull res = 0;
        for(int i=0;i<nr;++i){
            int gid = upper_bound(green,green+ng,red[i]) - green;
      //      printf("gid:%d\n",gid);
            int prg = gid;
            if(gid == ng){
                --gid;
                --prg;
            }
            else if(gid > 0) prg--;
            int a[2];
            a[0] = prg;
            a[1] = gid;
       //     printf("gid:%d prg:%d\n",gid,prg);
            for(int j=0;j<2;++j){
                int bid = upper_bound(blue,blue+nb,green[a[j]]) - blue;
                int prb = bid;
                if(bid == nb){
                    --bid;
                    --prb;
                }
                else if(bid>0){
                    --prb;
                }
        //        printf("bid:%d prb: %d\n",bid,prb);
                ull cost = (red[i]-green[a[j]])*(red[i]-green[a[j]]);
                cost += (red[i] - blue[bid])*(red[i] - blue[bid]);
                cost += (green[a[j]]-blue[bid])*(green[a[j]]-blue[bid]);
                if(f == 0){
                    res = cost;
                    f = 1;
                }
         //       printf("cost:%llu\n",cost);
                res = min(res,cost);
                cost = (red[i]-green[a[j]])*(red[i]-green[a[j]]);
                cost += (red[i] - blue[prb])*(red[i] - blue[prb]);
                cost += (green[a[j]]-blue[prb])*(green[a[j]]-blue[prb]);
              //  printf("cost:%llu\n",cost);
                res = min(res,cost);
            }
        }
         for(int i=0;i<ng;++i){
            int gid = upper_bound(red,red+nr,green[i]) - red;
       //     printf("gid:%d\n",gid);
            int prg = gid;
            if(gid == nr){
                --gid;
                --prg;
            }
            else if(gid > 0) prg--;
            int a[2];
            a[0] = prg;
            a[1] = gid;
            for(int j=0;j<2;++j){
                int bid = upper_bound(blue,blue+nb,red[a[j]]) - blue;
                int prb = bid;
                if(bid == nb){
                    --bid;
                    --prb;
                }
                else if(bid>0){
                    --prb;
                }
                ull cost = (green[i]-red[a[j]])*(green[i]-red[a[j]]);
                cost += (green[i] - blue[bid])*(green[i] - blue[bid]);
                cost += (red[a[j]]-blue[bid])*(red[a[j]]-blue[bid]);

                res = min(res,cost);
                cost = (green[i]-red[a[j]])*(green[i]-red[a[j]]);
                cost += (green[i] - blue[prb])*(green[i] - blue[prb]);
                cost += (red[a[j]]-blue[prb])*(red[a[j]]-blue[prb]);
                res = min(res,cost);
            }
         }

            for(int i=0;i<nb;++i){
            int gid = upper_bound(green,green+ng,blue[i]) - green;
            int prg = gid;
            if(gid == ng){
                --gid;
                --prg;
            }
            else if(gid > 0) prg--;
            int a[2];
            a[0] = prg;
            a[1] = gid;
            for(int j=0;j<2;++j){
                int bid = upper_bound(red,red+nr,green[a[j]]) - red;
                int prb = bid;
                if(bid == nr){
                    --bid;
                    --prb;
                }
                else if(bid>0){
                    --prb;
                }
                ull cost = (blue[i]-green[a[j]])*(blue[i]-green[a[j]]);
                cost += (blue[i] - red[bid])*(blue[i] - red[bid]);
                cost += (green[a[j]]-red[bid])*(green[a[j]]-red[bid]);
                if(f == 0){
                    res = cost;
                    f = 1;
                }
                res = min(res,cost);
                cost = (blue[i]-green[a[j]])*(blue[i]-green[a[j]]);
                cost += (blue[i] - red[prb])*(blue[i] - red[prb]);
                cost += (green[a[j]]-red[prb])*(green[a[j]]-red[prb]);
                res = min(res,cost);
            }
        }

        printf("%llu\n",res);
    }

}
