#include <bits/stdc++.h>

using namespace std;
int main()
{
    int x,y,z;
    cin >> x >> y >> z;
    x -= y;
    if(z >= abs(x) && z != 0)
    {
        cout << "?";
    }
    else if(x > 0)
        cout << '+';
    else if(x < 0)
        cout << '-';
    else if(x == 0)
        cout << '0';
}
