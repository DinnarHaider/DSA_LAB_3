#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(string& str)
{
  
     char* left = str.data();
     char* right = left + str.length() - 1;
    while (left < right)
    {
        if (*left != *right)
            {return false;}
        left++;   
        right--;
    }
    return true;
}
int main()
{
    string test;
    cout<<"Enter the word and we will check whether it is a palindrome or not:";
    cin>>test;
    if (isPalindrome(test))
        cout << "It is a palindrome" << endl;
    else
        cout << "It is not a palindrome" << endl;

    return 0;
}