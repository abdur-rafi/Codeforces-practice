#include <bits/stdc++.h>

using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
ll minll(ll a, ll b){
return (a>b)? b:a;
}
string l,r;

void sum(string &a,string &b)
{
    int k = a.size()-1;
    int carry = 0;
    for(int i = b.size()-1; i >= 0;--i)
    {
        int n1 = b[i]-'0';
        int n2 = a[k]-'0';
        int sum = n1+n2 +carry;
        carry = sum % 10;
        a[k] = sum + '0';
    }

}
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n % 2 == 1)
    {

        int i = (n/2) ;
        if(s[i]-'0' != 0)
        {
            if(s[i+1] == '0')
            {
                for(int j = 0; j <= i;++j)
                    l += s[j];
                for(int j = i+1;j < n;++j)
                    r += s[j];
            }
            else if(s[0] > s[i])
            {
                for(int j = 0; j < i;++j)
                    l += s[j];
                for(int j = i;j < n;++j)
                    r += s[j];
            }
            else if(s[0] < s[i])
            {
                for(int j = 0; j <= i;++j)
                    l += s[j];
                for(int j = i+1;j < n;++j)
                    r += s[j];
            }
            else
            {
                int k = 0;
                while(k+i < n && s[k] == s[i+k])
                    ++k;
                if(k+i == n)
                {
                    for(int j = 0; j <= i;++j)
                        l += s[j];
                    for(int j = i+1;j < n;++j)
                        r += s[j];
                }
                else
                {
                if(s[k] > s[i+k])
                {
                    for(int j = 0; j < i;++j)
                    l += s[j];
                    for(int j = i;j < n;++j)
                    r += s[j];
                }
                else if(s[k] < s[i+k])
                {
                for(int j = 0; j <= i;++j)
                    l += s[j];
                for(int j = i+1;j < n;++j)
                    r += s[j];
                }
                }
            }


        }

         else
        {
            int a1 = i;
            int a2 = i;
            while(a1 >= 0 && s[a1] == '0')
                --a1;
            while(a2 < n && s[a2] == '0')
                ++a2;
            if(n-a1-1 > a2)
            {
              //  cout << "fd";
                loop(j,a2,0)
                    l += s[j];
                loop(j,n,a2)
                    r += s[j];
            }
            else if(n-a1-1 < a2)
            {
                loop(j,a2,0)
                    l += s[j];
                loop(j,n,a2)
                    r += s[j];
            }
            else
            {
              //  cout << "FDd";
            //    cout <<"a2 : " << a2 << '\n';
                int k = 0;
                while(k+a2 < n && s[k] == s[a2+k])
                    ++k;
                if(k+a2 >= n)
                {
                    for(int j = 0; j < a2;++j)
                        l += s[j];
                    for(int j = a2;j < n;++j)
                        r += s[j];
                }
                else
                {
                if(s[k] < s[a2+k])
                {
                    for(int j = 0; j < a2;++j)
                    l += s[j];
                    for(int j = a2;j < n;++j)
                    r += s[j];
                }
                else if(s[k] > s[a2+k])
                {
                for(int j = 0; j < a1;++j)
                    l += s[j];
                for(int j = a1;j < n;++j)
                    r += s[j];
                }
            }
        }
    }

    }


    else
    {
        int a1 = n/2;
        int a2 = a1-1;
        if(s[a2] != '0')
        {
         //   cout << " adfsd";
            loop(i,a2+1,0)
                l += s[i];
            loop(i,n,a2+1)
                r += s[i];
        }
        else
        {
            int d = a1,e = a2;
            while(a1 >= 0 && s[a1] == '0')
                --a1;
            while(a2 < n && s[a2] == '0')
                ++a2;
             if(n-a1-1 > a2)
            {
              //  cout << "fd";
                loop(j,a2,0)
                    l += s[j];
                loop(j,n,a2)
                    r += s[j];
            }
            else if(n-a1-1 < a2)
            {
           //     cout << "Fd";
                loop(j,a2,0)
                    l += s[j];
                loop(j,n,a2)
                    r += s[j];
            }
            else
            {
              // cout << "FDd";
            //    cout <<"a2 : " << a2 << '\n';
                int k = 0;
                while(k+a2 < n && s[k] == s[a2+k])
                    ++k;
                if(k+a2 >= n)
                {
                    for(int j = 0; j < a2;++j)
                        l += s[j];
                    for(int j = a2;j < n;++j)
                        r += s[j];
                }
                else
                {
                if(s[k] < s[a2+k])
                {
                    for(int j = 0; j < a2;++j)
                    l += s[j];
                    for(int j = a2;j < n;++j)
                    r += s[j];
                }
                else if(s[k] > s[a2+k])
                {
                for(int j = 0; j < a1;++j)
                    l += s[j];
                for(int j = a1;j < n;++j)
                    r += s[j];
                }
            }
        }

        }
    }
//cout << l << ' ' << r;
    string a,b;
    if(l.size() > r.size())
    {
        a = l;
        b = r;
    }
    else
    {
        a = r;
        b = l;
    }
}
