//输入一条字符串，找出最长的一个单词
#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> longestword(string sen)
{
    string new_str;
    string max_str;
    string min_str;
    for(auto c:sen)
    {
        //判断是不是字母或数字
        if((c>='a')&&(c<='z'))
            new_str.push_back(c);
        else if((c>='A')&&(c<='Z'))
            new_str.push_back(c);
        else if((c>='0')&&(c<='9'))
            new_str.push_back(c);
    //如果是符号，把已经已截取的单词保存到max_str中，清空new_str,保存了当前最长的
        else
        {
            if(new_str.length() >max_str.length())
                max_str = new_str;
            else 
                min_str =new_str;
                
            new_str.clear();
        }
        
        
    }
    //最后的检查长短
    if(new_str.length()> max_str.length())
        max_str = new_str;
    else 
        min_str = new_str;
    return {max_str,min_str};
}

int main()
{
    string str;
    vector<string> retstr;
    getline(cin,str);
    retstr = longestword(str);
    
    cout<<"the longest word is "<< retstr[0]<<endl;
    cout<<"the shortest word is "<< retstr[1]<<endl;
    return 0;
}
