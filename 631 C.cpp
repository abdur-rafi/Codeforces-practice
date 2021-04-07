#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;scanf("%d %d",&n,&m);
    int color[m];
    for(int i=0;i<m;++i) scanf("%d",color+i);
    int box[m];
    for(int i=0;i<m;++i) box[i] = 0;
    int mx = -1;
    int mx_id = 0;

    for(int i=0;i<m;++i){
        box[i] = i;
        if(box[i]+color[i]-1 > mx){
            mx = box[i]+color[i]-1;
            mx_id = i;
        }
        if(mx>=n){
            printf("-1");
            return 0;
        }
    }
    int shift[m];
    for(int i=0;i<m;++i) shift[i] = 0;

    int lft = n-1 - (mx_id+color[mx_id]-1) ;
    for(int i = 0; i < mx_id;++i){
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
    int pre = 0;
    for(int i=1;i<m;++i){
        box[i] += shift[i-1]+pre;
        pre += shift[i-1];
    }
    if(lft){
        if(mx_id == m-1){
            printf("-1");
            return 0;
        }
        box[m-1] = n-1-(color[m-1]-1);
        for(int i=m-2;i>mx_id;--i){
            box[i] = box[i+1]-1;
        }
        int curr = box[mx_id+1];
        int lft2 = curr - (box[mx_id]+color[mx_id]-1) -1;
        lft2 = max(0,lft2);
        int shiftr = 0;
        for(int i = m-1;i > mx_id;--i){
            if(color[i]-1 < lft2){
                box[i] = box[i] - (color[i]-1);
                box[i] -= shiftr;
                shiftr += color[i]-1;
                lft2 -= color[i]-1;
            }
            else{
                box[i] = box[i] - lft2;
                box[i] += shiftr;
                lft2 = 0;
                break;
            }
        }
        if(lft2){
            printf("-1");
            return 0;
        }

    }
    for(int i=0;i<m;++i){
        printf("%d ",box[i]+1);
    }



}
