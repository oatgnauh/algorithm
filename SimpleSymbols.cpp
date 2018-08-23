#include <iostream>
#include<string>
#include<vector>

using namespace std;

string SimpleSymbols(string str) { 
    vector<char> flag;
    for(int i = 0;i<str.length();i++)
    {
        if(isalpha(str[i]))
        {
            if(str[i-1]=='+'&& str[i+1]=='+')
                flag.push_back(1);
            else
                flag.push_back(0);
        }
    }
    for(auto it = flag.begin();it != flag.end();++it)
    {
        if(*it==0)
            return "false";
    }
    return "true";

  // code goes here   
 
            
}

int main()
{
    string str("f++d+");
    cout<<SimpleSymbols(str);
}
/*
使用 c++ 语言, 使函数 SimpleSymbols (str) 接受传递的 str 参数,
 并通过返回字符串 true 或 false 来确定它是否是可接受的序列。
 str 参数将由 + 和 = 符号组成, 它们之间有几个字母 (即 + + d + == = = =),
  而字符串为 true 每个字母都必须由 + 符号包围。所以左边的字符串是假的。
  该字符串将不为空, 并且将至少有一个字母。*/