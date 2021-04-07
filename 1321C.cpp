#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    string s;cin>>s;
    int res = 0;
    for(int i=25;i>=1;--i){
        if(s.size() < 2) break;
        bool neib = false;
        for(auto p=s.begin();p!=s.end();){
            if(*p == 'a'+i-1){
                neib=true;
                ++p;
            }
            else if(*p == 'a'+i){
                if(neib){
                    p = s.erase(p);
                    ++res;
                }
                else
                    ++p;
            }
            else{
                neib = false;
                ++p;
            }
        }
        neib = false;
        reverse(s.begin(),s.end());
        for(auto p=s.begin();p!=s.end();){
            if(*p == 'a'+i-1){
                neib=true;
                ++p;
            }
            else if(*p == 'a'+i){
                if(neib){
                    p = s.erase(p);
                    ++res;
                }
                else
                    ++p;
            }
            else{
                neib = false;
                ++p;
            }
        }
        reverse(s.begin(),s.end());
    }
    cout<<res;
}
