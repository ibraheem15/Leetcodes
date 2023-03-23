// 17. Letter Combinations of a Phone Number
// Medium

// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

/***********************
 **  Ibraheem Rehman  **
 **  SE-Q    21i-1102 **
 ***********************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    void recursion_sol(string digits, vector<string> &ans, int i, int n, vector<string> v, string s)
    {
        if (i >= n)
        {
            ans.push_back(s);
            return;
        }
        int x = digits[i] - '0';
        for (int j = 0; j < v[x].size(); j++)
        {
            s.push_back(v[x][j]);
            recursion_sol(digits, ans, i + 1, n, v, s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if (digits.size() == 0)
            return ans;
        string s;
        int n = digits.size();
        vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        recursion_sol(digits, ans, 0, n, v, s);
        return ans;
    }
};


int main()
{
    Solution s;
    vector<string> ans = s.letterCombinations("2");
    for (auto i : ans)
        cout << i << endl;
    return 0;
}