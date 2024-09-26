#include <iostream>
#include <vector>
#include <string>
using namespace std;


void longestCommonSubstring(const string &str1, const string &str2) {
    int n = str1.length();
    int maxLength = 0;      
    int endIndex = 0;        

    vector<vector<int > > lookup(n + 1, vector<int>(n + 1, 0));
 
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {

            if (str1[i - 1] == str2[j - 1]) 
            {
                lookup[i][j] = lookup[i - 1][j - 1] + 1;  

                if (lookup[i][j] > maxLength) 
                {
                    maxLength = lookup[i][j];
                    endIndex = i - 1;  
                }
            }
        }
    }

    cout << "Lookup Table:\n";
    for (const auto &row : lookup) 
    {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Retrieve and print the longest common substring
    string longestSubstr = str1.substr(endIndex - maxLength + 1, maxLength);
    cout << "Longest Common Substring: " << longestSubstr << " (Length: " << maxLength << ")" << endl;
}

int main() 
{
    string str1, str2;
cout << "Enter the first string: ";
getline(cin, str1);
str1 = str1.substr(0, str1.find_last_not_of(" \n\r\t") + 1); 

cout << "Enter the second string: ";
getline(cin, str2);
str2 = str2.substr(0, str2.find_last_not_of(" \n\r\t") + 1); 

    longestCommonSubstring(str1, str2);

    return 0;
}

