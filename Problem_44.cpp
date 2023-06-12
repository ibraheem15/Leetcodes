/*
 * Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * The matching should cover the entire input string (not partial).
 */

/***********************
 **  Ibraheem Rehman  **
 **  SE-Q    21i-1102 **
 ***********************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int s_size = s.size();
        int p_size = p.size();
        int star_i = -1;
        int star_j = -1;
        int i = 0;
        int j = 0;
        for (i = 0, j = 0; i < s_size; ++i, ++j)
        {
            // if(s[i] == p[i])
            // { 
            //     continue;
            // }
            // else if(p[i] == '?' && s[i] != p[i])
            // {
            //     continue;
            // }
            // else if(p[i] == '*' && s[i] != p[i])
            // {
            //     return true;
            // }
            // else if(p[i] == '*' && s[i] == p[i])
            // {
            //     continue;
            // }
            // else
            // {
            //     return false;
            // }
            if (p[j] == '*')
            {
                star_i = i; // this is the index of the star in the pattern which is used to backtrack the string
                star_j = j; 
                --i; // this is used to backtrack the pattern to the previous index becauase the star can be used to match any sequence of characters
            }
            else 
            {
                if (s[i] != p[j] && p[j] != '?')
                {
                    if (star_i >= 0)
                    {
                        i = star_i++;
                        j = star_j;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        while (p[j] == '*')
        {
            ++j;
        }
        return j==p_size;
    }
};

int main()
{
    Solution obj;
    string s = "cb";
    string p = "aa";
    cout << obj.isMatch(s, p) << endl;
    return 0;
}