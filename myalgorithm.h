#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string.h>
#include <math.h>
#include <ctype.h>
using namespace std;
/*

给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

*/
//时间复杂度O(N^2)
int removeDuplicates(vector<int>& nums) 
{
    auto it1 = nums.begin();
    while(it1 != nums.end())
    {
        auto it2 = it1+1;
        while(it2 != nums.end())
        {
            if(*it2 == *it1)
                it2 = nums.erase(it2);
            else
                it2++;
        }
        it1++;
    }
    return nums.size();

}
//时间复杂度O（n）
int anothersolution(vector<int> & nums)
{
    if (nums.size() == 0) return 0;
    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    nums.erase(nums.begin()+i+1,nums.end());
    return nums.size();
}
//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
void rotate(vector<int>& nums, int k) {
    vector<int> lastk;
    int size = nums.size();
    if(k> size)
        k = k % size;
    int j=k;
    for(;j>0;j--)
        lastk.push_back(nums[size-j]);  //保存后k位的数据
    int index =size -(size-k)-1;
    for(int i = size-1;i>index;i--)   
        nums[i] = nums[i-k];            //向后移动元素
    for(int h=0;h<k;h++)
        nums[h] = lastk[h];        //填充开始的一段数组
}
//判断时候有重复数字
bool containsDuplicate(vector<int>& nums) {
    int size(nums.size());
    if(size<2)
        return false;
    sort(nums.begin(),nums.begin()+size);
    int i =0;
    for(int j=1;j<size;j++)
    {
        if(nums[j]==nums[i])
            return true;
        i++;
    }
    return false;
}
//最佳股票收益
int maxProfit(vector<int>& prices) {
    vector<int> difference;
    for(int j = 1;j<prices.size();j++)
        difference.push_back(prices[j]-prices[j-1]);
    int max = 0;
    for(auto i: difference)
    {
        if(i>max)
            max = i;
    }
    return max;
    
}
//找出数组里面的单个元素
/*
一个数字异或它自己结果为0，异或0结果为它自己即a^a=0，a^0=a，且异或满足a^b^c=a^(b^c)
最后相同的都抵消为0，那个唯一的数字异或0为它自己即为答案
*/
int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int i : nums) {
        res ^= i;
    }
    return res;
}
//求数组交集
//undone...
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ret;
    auto it1 = nums1.begin();
    auto it2 = nums2.begin();
    while(it1 != nums1.end())
    {
        while(it2 != nums2.end())
        {
            if(*it2 == *it1)
                ret.push_back(*it2);
            it2++;
        }
        it1++;
    }
    return ret;
}
//合并数组成为整数加一再拆分
vector<int> plusOne(vector<int>& digits) {
    vector<int> ret,temp;
    int n = digits.size();
    long long num = 0;
    for(int i=0;i<digits.size();i++)
    {
        num = num +digits[i]* (long long)pow(10,--n);      //一旦数组规模变大，这种转化方法的代价是巨大的
    }
    num++;  //要考虑加一后进位造成的位数增加情况
    while(num)
    {
        temp.push_back(num%10);
        num /=10;
    }
    //得到倒序的数组
    for(auto it=temp.rbegin();it != temp.rend();it++)
        ret.push_back(*it);
   return ret;
}

vector<int> plusOne1(vector<int> &digits) {  
    int i,p,temp,len=digits.size();  
    for(i=0;i<len;++i)  
    {  
        if(digits[i]!=9)break;      //如果数组元素全部是9
    }  
    if(i==len)  //最高位进位，数组元素扩展一位最高位
    {  
        vector<int>result;  
        result.push_back(1);  
        for(i=0;i<len;++i)
            result.push_back(0);  
        return result;  
    }  
    digits[len-1]+=1;  //否则，最低位加一
    p=0;  
    for(i=len-1;i>=0;--i)  
    {  
        temp=digits[i]+p;  //产生进位的情况
        digits[i]=temp%10;  
        p=temp/10;  
        if(p==0)break;  
    }  
    return digits;  
}
//把数组中的0全部移到末尾
void moveZeroes(vector<int>& nums) 
{
    if(nums.size()==1 && nums[0]==0)
        nums.clear();
    int times=0;
    for(auto i: nums)
    {
        if(!i)
            times++;
    }
    auto it=nums.begin();
    while(it++ != nums.end())
    {
        if(*it == 0)
            it = nums.erase(it);
        else
            it++;
    }
    while(times)
    {
        nums.push_back(0);
        times--;
    }
}


void moveZeroes2(vector<int>& nums) {
    if(nums.size()==1 && nums[0]==0)
        return ;

    auto it=nums.begin();
    while(it != nums.end())
    {
        if(*it == 0)
        {
            it = nums.erase(it);
            nums.push_back(0);

        }
        else
            it++;
    }
  
}

// vector<int> twoSum(vector<int>& nums, const int target) 
// {
//     unordered_set<int> needed = {};
//     vector<int> result(2);
//     int other;
//     for(int i = 0; i < nums.size(); i++){
//         int remain = target - nums[i];
     
//         if(needed.count(nums[i]) != 0){
//             result[1] = i;
//             other = remain;
//             break;
//         }
//         else{
//             needed.insert(remain);
//         }
//     }

//     for(int j = 0; j < nums.size(); j++){
//         if(nums[j] == other){
//             result[0] = j;
//             break;
//         }
//     }
//     return result;
// }
//32位整数翻转，考虑翻转后溢出的情况
int reverse(int x) {
    int i=0;    //保存翻转后的整数
    while (x!=0)
    {
        int n=i*10+x%10;    //保存最低位的数字
        x=x/10;         //去掉最低位数字
        int temp=n/10;
        if(temp!=i)     //当i即溢出的时候，这两个值是不相等的
            return 0;
        i=n;
    }
    return i;
}



int firstUniqChar(string s) {
    int dic[26]={0};
    for(int i = 0;i < s.size(); i++)
    {
        dic[s[i] - 'a'] ++;
    }

    for(int i = 0;i < s.size(); i++)
    {
        if(dic[s[i] - 'a'] == 1)
            return i;
    }
    return -1;
}

bool isAnagram(string s, string t) {
    if(s.size() != t.size())
        return false;
    char word1[26]={0}, word2[26]={0};
    for(int i=0; i<s.size(); i++)
    {
        word1[s[i] - 'a'] ++;
        word2[t[i] - 'a'] ++;
    }
    for(int j=0; j<26;j++)
    {
        if(word1[j] != word2[j])
            return false;
    }
    return true;
}

bool isPalindrome(string s) {
    // std::string order("");
    // string disOrder("");
    vector<char> order;
    vector<char> disOrder;
    for(auto &c:s)
    {
        if(isalnum(c))
        {
            if(isalpha(c))
                c = tolower(c);
            order.push_back(c); 
        }
    }
    for(int i = order.size() - 1; i>=0; i--)
        disOrder.push_back(order[i]);
    if(order == disOrder)
        return true;
    else
        return false;
}

int myAtoi(string str) {
    vector<char> numStr;
    long long ret = 0;
    int firstPos = -1;
    if(!isdigit(str[0]) && str[0]!=' ' && str[0]!='-'&& str[0]!='+')  //".32","abc 123","42"
        return 0;
    if(str.size()==1 && (!isdigit(str[0])))
        return 0;
    for(int i=0; i<str.size(); i++)
    {
        if(!isdigit(str[i]))
            continue;
        else
        {
            firstPos = i;
            break;
        }
    }
    bool flag=false;
    for(auto index= str.begin()+firstPos;index!=str.end();index++)
    {
        if(!isdigit(*index) && flag)
            break;
        else
        {
            numStr.push_back(*index);
            flag = true;
        }
    }
    for(int j=numStr.size()-1;j>=0;j--)
    {
        ret += int(numStr[numStr.size()-j-1]-'0')*pow(10,j);
    }   
    
    if(str[firstPos-1]=='-')
        return (ret >2147483648)? -2147483648:-ret;
    else
        return (ret > 2147483647)? 2147483648:ret;
}

int strStr(string haystack, string needle) {    //my version
    if(needle.size()==0)
        return 0;
    int needleSize = needle.size();
    for(int i=0;i<haystack.size();i++)
    {
        if(haystack[i] == needle[0])
        {
            string sub = haystack.substr(i,needleSize);
            if(needle == sub)
                return i;
        }
    }
    return -1;
}

int strStr_pro(string haystack, string needle) {    //much better
    if(needle.empty())
        return 0;
    const int N = haystack.size()-needle.size()+1;
    for(int i=0; i<N; ++i){
        int j = i;
        int k = 0;
        while(j < haystack.size() && k<needle.size() && haystack[j]==needle[k]){
            ++j;
            ++k;
        }
        if(k==needle.size())
            return i;
    }
    return -1;
}

bool Find(int target, vector<vector<int> > array) {
    if(array.empty())
        return false;
    int rows = 0;
    int cols = array[0].size()-1;
    while(rows < array.size() &&  cols >=0)
    {
        if(array[rows][cols] == target)
            return true;
        else if(array[rows][cols] > target)
            cols--;
        else
            rows++;
    }
    return false;
}

void replaceSpace(char *str,int length) {
    int space = 0;
    for(char *iter =str; *iter != '\0';iter++)
    {
        if(*iter == ' ')
            space ++;
    }
    int p1=length;
    int p2 = length + space*2;
    char newStr[p2 + 1];
    while(p1>=0)
    {
        if(str[p1] != ' ')
            newStr[p2--] = str[p1];
        else
        {
            newStr[p2--] = '0';
            newStr[p2--] = '2';
            newStr[p2--] = '%';
        }
        p1--;
    }
    printf("%s",newStr);
    str = newStr;
}