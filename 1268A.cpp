#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string findSum(string str1, string str2)
{
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);
 
    // Take an empty string for storing result
    string str = "";
 
    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
 
    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
 
        // Calculate carry for next step
        carry = sum/10;
    }
 
    // Add remaining digits of larger number
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
 
    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
}

int main(){
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;

	string pre;
	for(int i = 0; i < k; ++i)
		pre += str[i];

	string res = pre;

	for(int i = k; i < n;++i)
		res += res[i - k];

	if(res >= str){
		cout << res.size() << "\n" << res;
	}
	else{
		pre = findSum(pre, "1");
		res = pre;
		for(int i = k; i < n;++i)
			res += res[i - k];

		cout << res.size() << "\n" << res;
	}

	// cout << res;

}