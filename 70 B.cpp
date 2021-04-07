 #include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
struct data{
    ll val, fre;
};
int main(){
    string str;cin>>str;
    for(int x=0;x<10;++x){
        for(int y=0;y<10  ;++y){
            ll c[10][10];
            loop(i,10,0){
                loop(j,10,0) c[i][j]=-1;
            }
            set<ll> s2;
            s2.insert(0);
            for(auto be:s2){
                queue<data>q;
                q.push({be,0});
                set<ll> s;
                s.insert(be);
              //  if(be==8) cout<<"dfasf";
                while(!q.empty()){
                    ll d=q.front().val;
                    ll fr=q.front().fre;
                    s2.insert(d);
                    q.pop();
                    if(c[be][d]==-1) c[be][d]=fr;
                    else c[be][d]=min(c[be][d],fr);
                    if(s.find(d+x)==s.end()) s.insert((d+x)%10),q.push({(d+x)%10,fr+1});
                    if(s.find(d+y)==s.end()) s.insert((d+y)%10),q.push({(d+y)%10,fr+1});
                }
            }
            ll res=0;
            for(int i=str.size()-2;i>=0;--i){
                ll v=str[i]-'0';
                ll p=str[i+1]-'0';
                if(c[p][v]==-1){
                    res=-1;
                    break;
                }
                res+=c[p][v];
             //   printf("p:%lld v:%lld %lld\n",p,v,c[p][v]);
            }
            cout<<res<<' ';

        }
        cout<<'\n';
    }
    return 0;
}
