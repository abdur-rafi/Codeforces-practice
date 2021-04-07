#include <bits/stdc++.h>
using namespace std;

string max_palindrome(string mid){
    if(mid.size() < 2) return mid;
    string rev = mid;
    reverse(rev.begin(),rev.end());
    mid = mid + "#" + rev;
    int prefix[mid.size()+100];
    prefix[0] = 0;
    int i = 1;
    int j = 0;
    while(i<mid.size()){
        if(mid[i] ==  mid[j]){
            prefix[i] = j+1;
            i++;
            j++;
        }
        else{
            if(j != 0){
                j = prefix[j-1];
            }
            else{
                prefix[i] = 0;
                ++i;
            }
        }
    }
    return mid.substr(0,j);
}

bool check(string r){
    int i = 0;
    int j = r.size()-1;
    while(i<=j){
        if(r[i] != r[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int main(){
    int t;cin>>t;
    while(--t>=0){
    string s;
    cin>>s;
    if(check(s)){
        cout<<s<<"\n";
        continue;
    }
    int n = s.size();
    int i=0,j=n-1;
    string pre,mid;
    while(i<j){
        if(s[i] == s[j]){
            pre += s[i];
            ++i;
            --j;
        }
        else{
            mid = s.substr(i,j-i+1);
            break;
        }
    }
    string s1 = max_palindrome(mid);
    reverse(mid.begin(),mid.end());
    string s2 = max_palindrome(mid);
    string res;
    if(s1.size() > s2.size()) res = s1;
    else res = s2;
    res = pre + res;
    reverse(pre.begin(),pre.end());
    res += pre;
    cout<<res<<"\n";
    }
}
