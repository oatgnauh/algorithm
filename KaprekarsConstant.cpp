#include<iostream>
#include<vector>
#include <algorithm>  
using namespace std;

int  KaprekarsConstant(int number)
{
    int reverse = 0;
    int num = 0;
    int count = 0;
    vector<int> sorted;
    while(number!= 6174)
    {
        num = number;
        while(num)
        {
            sorted.push_back(num%10);   //每次把最低位装进去
            num /= 10;      //然后去掉最低位
        }
        sort(sorted.begin(),sorted.end());
        number = sorted[0] + sorted[1]*10 + sorted[2]*100 + sorted[3]*1000;
        reverse = sorted[0]*1000 + sorted[1]*100 + sorted[2]*10 + sorted[3];
        number = number - reverse;
        count ++;
        sorted.clear(); //如果不清除这个变量就会一直延长
    }
    return count;
   
}

int main()
{
    int num= 2111;

   cout<< KaprekarsConstant(num);
 
}