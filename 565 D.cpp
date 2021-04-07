#include <bits/stdc++.h>

using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
#define inp(x) cin >> x
#define VI vector<int>
#define V vector

int const M =  2750131;

bool prime[M+1];
vector<int> primelist;
int inphash[M+1];
vector<int> inp;
void SieveOfEratosthenes(int n)
{

    for (int p=2; p*p<=M; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
}
int b_search(int n)
{
    int i = 0;
    int j = primelist.size();
    int m;
    while(i <= j)
    {
        m = (i+j) >> 1;
        if(primelist[m] == n)
            return m;
        else if(primelist[m] < n)
            i = m+1;
        else
            j = m-1;
    }
    return -1;
}
int main()
{
    loop(i,M+1,0)
        prime[i] = true;
    SieveOfEratosthenes(M);
    loop(i,M+1,2)
    {
        if(prime[i])
            primelist.push_back(i);
    }
    int n;
    cin >> n;
    loop(i,2*n,0)
    {
        int d;
        cin >> d;
        inphash[d]++;
        inp.push_back(d);
    }
    sort(inp.begin(),inp.end());
    vector<int> res;
    for(int i = 0; i < 2*n ;++i)
    {
        if(inphash[inp[i]] == 0)
            continue;
        if(prime[inp[i]])
        {
            int d = inp[i]*inp[i];
            if(d <= M && inphash[d])
            {
                res.push_back(d);
                inphash[inp[i]]--;
                inphash[d]--;
            }
            else
            {
                if( inp[i]-1 <= primelist.size() && inphash[primelist[inp[i]-1]] )
                {
                    inphash[inp[i]]--;
                    inphash[primelist[inp[i]-1]]--;
                    res.push_back(inp[i]);
                }
            }
        }
        else
        {
            if(inp[i] % 2 == 0)
            {
                int d = inp[i]/2;
                if(inphash[d])
                {
                    inphash[d]--;
                    inphash[inp[i]]--;
                    res.push_back(inp[i]);
                }
            }
            else
            {
                for(auto p = primelist.begin(); p != primelist.end();++p)
                {
                    if(inp[i] % (*p) == 0)
                    {
                        int d = inp[i] / (*p);
                        if(inphash[d])
                        {
                            inphash[d]--;
                            inphash[inp[i]]--;
                            res.push_back(inp[i]);
                        }
                        break;
                    }
                    else
                    {
                        ll d = (*p) * (*p);
                        if(d > inp[i])
                            break;
                    }
                }
            }
        }
    }
    for(auto p = res.begin(); p != res.end();++p)
        cout << *p << ' ';
}
