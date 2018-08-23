#include <iostream>
using namespace std;

string LetterChanges(string str) { 
    for(auto &c :str)
    {
        if(isalpha(c))
        {
            if(c=='z')
                c = 'a';
            else if(c=='Z')
                c='A';
            else
             c = c +1;
        }
    }
  // code goes here   
  return str; 
            
}

int main() { 
  
  // keep this function call here
  string str("hello world");
  cout << LetterChanges(str);
  return 0;
    
}