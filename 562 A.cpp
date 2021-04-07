#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,a,x,b,y;
    cin >> n >> a >> x >> b >> y;
    vector<int> first;
    int i = a;
    do
    {
        if(i > n)
            i = 1;
        first.push_back(i);
        if(i == x)
            break;
        ++i;

    }while(1);
    vector<int> second;
    i = b;
    do
    {
        if(i < 1)
            i = n;
        second.push_back(i);
        if(i == y)
            break;
        --i;
    }while(1);
    bool pos = false;
    for(int j = 0; j < first.size() && j <second.size();++j)
    {
        if(first[j] == second[j])
        {
            pos = true;
            break;
        }
    }
    if(pos)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}

