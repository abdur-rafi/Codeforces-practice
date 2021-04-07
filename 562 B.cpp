#include <iostream>

using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
#define inp(x) cin >> x
#define VI vector<int>
#define V vector
int main()
{
   int n,m;
   cin >> n >> m;
   int arr[m][2];
   loop(i,m,0)
   {
       cin >> arr[i][0] >> arr[i][1];
   }
   int a = arr[0][0];
   int frea = 0;
   int c,d;
   loop(i,m,0)
   {
       if(arr[i][0] == a || arr[i][1] == a)
            ++frea;
        else
        {
            c = arr[i][0];
            d = arr[i][1];
        }
   }
   int frec = 0,fred = 0;
   loop(i,m,0)
   {
       if(arr[i][0] != a && arr[i][1] != a)
       {
           if(arr[i][0] == c || arr[i][1] == c)
             frec++;
           if(arr[i][0] == d || arr[i][1] == d)
             fred++;
       }
   }
   if(frea+frec == m || frea+fred == m)
   {
       cout <<  "YES";
       return 0;
   }



   a = arr[0][1];
   frea = 0;
   loop(i,m,0)
   {
       if(arr[i][0] == a || arr[i][1] == a)
            ++frea;
        else
        {
            c = arr[i][0];
            d = arr[i][1];
        }
   }
   frec = 0;
   fred = 0;
   loop(i,m,0)
   {
       if(arr[i][0] != a && arr[i][1] != a)
       {
           if(arr[i][0] == c || arr[i][1] == c)
             frec++;
           if(arr[i][0] == d || arr[i][1] == d)
             fred++;
       }
   }
   if(frea+frec == m || frea+fred == m)
   {
       cout <<"YES";
       return 0;
   }
   cout << "NO";
   return 0;
}
