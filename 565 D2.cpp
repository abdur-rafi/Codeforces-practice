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
vector<int> np;
vector<int> p;
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
     //   inp.push_back(d);
        if(prime[d])
            p.push_back(d);
        else
            np.push_back(d);
    }
  //  sort(inp.begin(),inp.end());
    sort(p.begin(),p.end());
    sort(np.begin(),np.end());
    vector<int> res;
    for(auto q = np.rbegin(); q != np.rend();++q)
    {
        int f = *q;
     //   cout << "f : " << f << '\n';
        if(inphash[f] == 0)
            continue;
        if(f % 2 == 0)
        {
            int d = f/2;
            if(inphash[d])
            {
                inphash[d]--;
                inphash[f]--;
                res.push_back(f);
            }
        }
        else
        {
         //   cout << "fdsf";
            for(auto p = primelist.begin(); p != primelist.end();++p)
            {
                if(f % (*p) == 0)
                {
                    int d = f / (*p);
                    if(inphash[d])
                    {
                        inphash[d]--;
                        inphash[f]--;
                        res.push_back(f);
                    }
                    break;
                }
                else
                {
                    ll d = (*p) * (*p);
                    if(d > f)
                        break;

                }
            }
        }
    }
    for(auto q = p.begin();q != p.end();++q)
    {
        int d = *q;
        if(inphash[d] == 0)
            continue;
        if( d-1 < primelist.size() && inphash[primelist[d-1]] )
        {
            inphash[d]--;
            inphash[primelist[d-1]]--;
            res.push_back(d);
        }
    }
    for(auto p = res.begin(); p != res.end();++p)
        cout << *p << ' ';
}

