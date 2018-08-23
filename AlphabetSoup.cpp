//对字母进行从小到大的排序,使用冒泡排序
#include<iostream>
#include<string>

using namespace std;

string AlphabetSoup(string str)
{
    for(int i = 0; i <str.length(); i++)
    {
        for(int j = str.length()-1;j >=i;j--)   //最重要的是这个循环的判断条件
        {
            if(str[i]>str[j])
            {
                char temp;
                temp = str[j];
                str[j]= str[i];
                str[i] = temp;
            }
        }
    }
    return str;
}

int main()
{
    string str("coderbyte");
    cout<<AlphabetSoup(str);
}