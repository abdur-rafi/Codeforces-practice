#include <bits/stdc++.h>

using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    vector<bool> ah(n+1,true);
    vector<PII> ap(n);
    vector<int> atr(n);
    vector<int> res(n);
    loop(i,n,0)
    {
        cin >> a[i];
        ap[i].first = a[i];
        ap[i].second = i;
    }
    int l = 0;
    sort(ap.begin(),ap.end(),greater<PII>());
    for(auto b : ap)
    {
        if(ah[b.second])
        {
            int c = b.second;
            ah[c] = false;
            res[c] = l+1;
            int e,f;
            for(int j = 0; j < k;++j)
            {
                ++c;
                e = c;
                if(c < n && ah[c])
                {
                    res[c] = l+1;
                    ah[c] = false;
                }
                else if(c >= n)
                {
                    e = n;
                    break;
                }
                else if(!ah[c])
                {
                    c = atr[c];
                    --j;
                }
            }
            c = b.second;
            for(int j = 0; j < k;++j)
            {
                --c;
                f = c;
                if(c > -1 && ah[c])
                {
                    res[c] = l+1;
                    ah[c] = false;
                }
                else if(c < 0)
                {
                    f = -1;
                    break;
                }
                else if(!ah[c])
                {
                    c = atr[c];
                    --j;
                }
            }
            if(e < n)
                atr[e] = f;
            if(f > -1)
                atr[f] = e;
            l = (l+1) % 2;
        //    cout << "l : " << l << '\n';
        }
    }
    for(auto g : res)
        cout << g;
}
