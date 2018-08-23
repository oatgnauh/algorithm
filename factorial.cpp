#include<iostream>
#include<stdio.h>
using namespace std;
int FirstFactorial(int num) //输出阶乘结果
{
   for(int i = num-1; i>0;i--)
        num = num*i;
    return num;
}

int main()
{
    int data;
    cin>>data;
    cout<<FirstFactorial(data);
    return 0;
        
}