#include <bits/stdc++.h>

using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
#define inp(x) cin >> x
#define VI vector<int>
#define V vector
int arr[] = {4,8,15,16,23,42};
int fre[6];
int main()
{
    int n;
    cin >> n;
    loop(i,n,0)
    {
      int a;
      cin >> a;
      loop(j,6,0)
      {
          if(a == arr[j])
          {
              if(a == 4)
                fre[0]++;
              else
              {
                  if(fre[j-1])
                  {
                      --fre[j-1];
                      ++fre[j];
                  }
              }
          }
      }
    }
    cout << n-6*fre[5]<< '\n';
    return 0;
}

