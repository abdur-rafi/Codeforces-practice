#include <iostream>
#include <algorithm>

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
    int n;
    cin >> n;
    int arr[n];
    loop(i,n,0)
        cin >> arr[i];
    int a = 0, b = 0;
    loop(i,n,0)
    {
        if(arr[i] % 2 == 0)
            ++a;
        else
            ++b;
    }
    if(a && b)
    {
        sort(arr,arr+n);
        loop(i,n,0)
            cout << arr[i] << ' ';
    }
    else
    {
        loop(i,n,0)
            cout << arr[i] << ' ';
    }
}
