#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[2*n];
    for(int i = 0; i < 2*n;++i)
    {
        cin >> arr[i];
    }
    sort(arr,arr+2*n);
    int a = 0;
    int b = 0;
    for(int i = 0; i < n;++i)
        a += arr[i];
    for(int i = n; i < 2*n;++i)
        b += arr[i];
    if(a != b)
    {
        for(int i = 0; i < 2*n;++i)
            cout << arr[i] << ' ';
    }
    else
        cout << -1 ;
}
