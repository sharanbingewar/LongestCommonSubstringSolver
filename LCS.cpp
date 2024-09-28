#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // for std::max
using namespace std;


void longestCommonSubstring(const string &str1, const string &str2) 
{
    int len1 = str1.length();
    int len2 = str2.length();

    
    if (len1 == 0 || len2 == 0) 
    {
        cout << "One of the strings is empty. No common substring." << endl;
        return;
    }

    int maxLength = 0;  
    int endIndex = 0;   

    // Using only two rows to optimize space complexity
    vector<vector<int > > lookup(2, vector<int>(len2 + 1, 0));

    for (int i = 1; i <= len1; ++i) 
    {
        for (int j = 1; j <= len2; ++j) 
        {
            if (str1[i - 1] == str2[j - 1]) 
            {
                lookup[i % 2][j] = lookup[(i - 1) % 2][j - 1] + 1;  

                if (lookup[i % 2][j] > maxLength) 
                {
                    maxLength = lookup[i % 2][j];
                    endIndex = i - 1;  
                }
            } else 
            {
                lookup[i % 2][j] = 0;  
            }
        }
    }

    cout << "\nLookup Table (Space Optimized):" << endl;
    for (int i = 1; i <= len1; ++i) 
    {
        for (int j = 1; j <= len2; ++j) 
        {
            cout << lookup[i % 2][j] << " ";
        }
        cout << endl;
    }


    if (maxLength == 0) 
    {
        cout << "No common substring found." << endl;
    } else 
    {
        
        string longestSubstr = str1.substr(endIndex - maxLength + 1, maxLength);
        cout << "Longest Common Substring: " << longestSubstr << " (Length: " << maxLength << ")" << endl;
    }
}

int main() 
{
    string str1, str2;
    
    cout << "Enter the first string: ";
    getline(cin, str1);
    
    cout << "Enter the second string: ";
    getline(cin, str2);

    longestCommonSubstring(str1, str2);

    return 0;
}
