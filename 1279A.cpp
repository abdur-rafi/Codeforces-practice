#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        int r,g,b;scanf("%d %d %d",&r,&g,&b);
        priority_queue<int> pq;
        pq.push(r);pq.push(b);pq.push(g);
        int mx = pq.top();pq.pop();
        int mx2 = pq.top();pq.pop();
        int mx3 = pq.top();pq.pop();
        if(mx2+mx3 < mx-1) printf("No\n");
        else printf("Yes\n");
    }

}
