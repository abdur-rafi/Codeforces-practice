#include <iostream>
#include <string>
using namespace std;
string inp;
int fre(string d)
{
    int c = 0;
    int n = inp.size();
    for(int i = 0; i < n;++i)
    {
        if(inp[i] != d[i%3])
            ++c;
    }
    return c;
}
int main()
{
    int n;
    cin >> n;
    cin >> inp;
    int h = 1e9;
    string res;
    string d = "RGB";
    if(fre(d) < h)
    {
        h = fre(d);
        res = d;
    }
    d = "RBG";
    if(fre(d) < h)
    {
        h = fre(d);
        res = d;
    }
    d = "GRB";
    if(fre(d) < h)
    {
        h = fre(d);
        res = d;
    }
    d = "GBR";
    if(fre(d) < h)
    {
        h = fre(d);
        res = d;
    }
    d = "BRG";
    if(fre(d) < h)
    {
        h = fre(d);
        res = d;
    }
    d = "BGR";
    if(fre(d) < h)
    {
        h = fre(d);
        res = d;
    }
    cout << h << '\n';
    for(int i = 0; i < n;++i)
    {
        cout << res[i%3] ;
    }
}
