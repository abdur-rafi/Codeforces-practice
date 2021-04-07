#include <iostream>
#include <string>

using namespace std;
int n;
string s;
string t = "RGB";
char rem(char a,char b)
{
    for(int i = 0; i < 3;++i)
        if(t[i] != a && t[i] != b)
        return t[i];
}
int main()
{
    cin >> n;
    cin >> s;
    int c = 0;
    for(int i = 1; i < n;++i)
    {
        if(i+1 < n && s[i] == s[i-1] && s[i] == s[i+1])
        {
            s[i] = rem(s[i-1],s[i+1]);
            i += 1;
            ++c;
            continue;
        }
        if(s[i] == s[i-1])
        {
            if(i+1 < n)
                s[i] = rem(s[i-1],s[i+1]);
            else
                s[i] = rem(s[i-1],s[i]);
            ++c;
        }

    }
    cout << c << '\n' << s;
}
