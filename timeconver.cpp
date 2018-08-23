#include <iostream>

#include<string>
using namespace std;

string TimeConvert(int num) 
{ 
    string ret;
    ret.push_back(num/60 + '0');
    ret.push_back('.');
    ret.push_back(num%60 + '0');
    return ret;
            
}
int main()
{
    int a = 126;
    cout<<TimeConvert(a);
}