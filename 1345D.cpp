#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1010][1010];
int vis[1010][1010];
bool isCorrect(){
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j) vis[i][j] = 0;
    }
    int row[n],col[m];
    int free_row[n],free_col[m];
    for(int i=0;i<n;++i){
        int bl = 0,wh=0;
        for(int j=0;j<m;++j){
            if(a[i][j] == 0){
                if(bl == 1) wh = 1;
            }
            else{
                if(bl && wh) return false;
                bl = 1;
             }
        }
    }
    for(int j=0;j<m;++j){
        int bl = 0,wh=0;
        for(int i=0;i<n;++i){
            if(a[i][j] == 0){
                if(bl == 1) wh = 1;
            }
            else{
                if(bl && wh) return false;
                bl = 1;
             }
        }
    }
    for(int i=0;i<n;++i){
        int f = 0;
        for(int j=0;j<m;++j){
            if(a[i][j] == 1){
                f = 1;
                break;
            }
        }
        if(!f) free_row[i] = 1;
        else free_row[i] = 0;
    }
    for(int j=0;j<m;++j){
        int f = 0;
        for(int i=0;i<n;++i){
            if(a[i][j] == 1){
                f = 1;
                break;
            }
        }
        if(!f) free_col[j] = 1;
        else free_col[j] = 0;
    }
    for(int i=0;i<n;++i) row[i] = 0;
    for(int i=0;i<m;++i) col[i] = 0;
    for(int i = 0;i<n;++i){
        for(int j=0;j<m;++j){
            if(free_col[j] && free_row[i]){
                col[j] = 1;
                row[i] = 1;
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(a[i][j]){
                row[i]=1;
                col[j]=1;
            }
        }
    }
    for(int i=0;i<n;++i)
        if(!row[i]) return false;
    for(int i=0;i<m;++i)
        if(!col[i]) return false;
    return true;
}
void bfs(int i,int j){
    queue<pair<int,int>> q;
    q.push({i,j});
    vis[i][j] = 1;
    while(!q.empty()){
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        int left=0,right=0,up=0,down=0;
        if(u-1>=0&&!vis[u-1][v] && a[u-1][v]){
            q.push({u-1,v});vis[u-1][v] = 1;

        }
        if(v-1>=0&&!vis[u][v-1] && a[u][v-1]){
            q.push({u,v-1});vis[u][v-1] = 1;

        }
        if(u+1<n&&!vis[u+1][v] && a[u+1][v]){
            q.push({u+1,v});vis[u+1][v] = 1;
        }
        if(v+1<m&&!vis[u][v+1] && a[u][v+1]){
            q.push({u,v+1});vis[u][v+1]=1;
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    int bl = 0;
    for(int i=0;i<n;++i){
        char str[m+1];
        scanf("%s",str);
        for(int j=0;j<m;++j){
            if(str[j] == '.') a[i][j] = 0;
            else a[i][j] = 1,++bl;
        }
    }
    if(bl == 0){
        printf("0\n");
        return 0;
    }
    if(!isCorrect()){
        printf("-1");
        return 0;
    }
    if(min(n,m) == 1 && bl != 0 && bl != n*m){
        printf("-1\n");
        return 0;
    }
    int res = 0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(!vis[i][j] && a[i][j]){
                bfs(i,j);
                ++res;
            }
        }
    }
    printf("%d\n",res);

}
