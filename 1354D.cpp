#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
class fenwick_tree{
    int N;
    int *ftree;
public:
    fenwick_tree(int n);
    void build_tree(int a[]);
    int get_next(int v);
    int get_parent(int v);
    int query(int i);
    void update(int i,int val);
};
fenwick_tree::fenwick_tree(int n){
    N=n;
    ftree=new int[N+1];
    for(int i=0;i<=N;++i) ftree[i] = 0;
}
int fenwick_tree::get_parent(int v){
    int org=v;
    v= ~v;
    v+=1;
    v=org&v;
    return org-v;
}
int fenwick_tree::get_next(int v){
    int org=v;
    v= ~v;
    v+=1;
    v=org&v;
    return org+v;
}
void fenwick_tree::build_tree(int a[]){
    for(int i=1;i<=N;++i){
        int k=i;
        while(k<=N){
            ftree[k]+=a[i-1];
            k=get_next(k);
        }
    }
}
int fenwick_tree::query(int i){
    int parent=i+1;
    int res=0;
    while(parent>0){
        res+=ftree[parent];
        parent=get_parent(parent);
    }
    return res;
}
void fenwick_tree::update(int i,int val){
    int k=i+1;
    while(k<=N){
        ftree[k]+=val;
        k=get_next(k);
    }
}
int main(){
    int n,q;scanf("%d %d",&n,&q);
    fenwick_tree ftree(n+1);
    int a[n+1];
    for(int i=0;i<=n;++i) a[i] = 0;
    for(int i=0;i<n;++i){
        int b;scanf("%d",&b); a[b]++;
    }
    ftree.build_tree(a);
  //  printf("%d\n",ftree.query(4));

    for(int i=0;i<q;++i){
        int k;scanf("%d",&k);
        if(k>0){
            ftree.update(k,1);
        }
        else{
            k =abs(k);
            int ii=0;
            int j = n;
            int m;
            while(ii<=j){
                m = (ii+j)/2;
                if(ftree.query(m)<k) ii = m+1;
                else j = m-1;
            }
        //    printf("%d\n",j+1);
            ftree.update(j+1,-1);
        }
    }
    int f = 0;
    for(int i=1;i<=n;++i){
        if(ftree.query(i)-ftree.query(i-1)) {
      //      printf("i:%d q:%d\n",i,ftree.query(i));
            f = i;
        }
    }
    printf("%d",f);

}
