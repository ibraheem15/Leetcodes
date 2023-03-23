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
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if (digits.size() == 0)
            return ans;
        string s;
        int n = digits.size();
        vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; // 0,1,2,3,4,5,6,7,8,9
        for (int i = 0; i < n; i++)
        {
            int digit1 = digits[i] - '0';
            // check for next digit if it is null then add space
            int digit2 = digits[i + 1]; // if only 1 digit is present then it will be null
            int digit3 = digits[i + 2];
            int digit4 = digits[i + 3];
            if ((digit2 == NULL && i < 1))
            {
                digit2 = 0;
                digit3 = 0;
                cout << "digit1: " << digit1 << " digit2: " << digit2 << endl;
                for (int k = 0; k < v[digit1].size(); k++)
                {
                    s.push_back(v[digit1][k]);
                    ans.push_back(s);
                    s.pop_back();
                }
            }
            else if (digit3 == NULL && i < 1)
            {
                digit2 = digits[i + 1] - '0';
                digit3 = 0;
                cout << "digit1: " << digit1 << " digit2: " << digit2 << endl;
                for (int k = 0; k < v[digit1].size(); k++)
                {
                    for (int l = 0; l < v[digit2].size(); l++)
                    {
                        if (v[digit2][l] == NULL)
                            v[digit2][l] = ' ';
                        s.push_back(v[digit1][k]);
                        s.push_back(v[digit2][l]);
                        ans.push_back(s);
                        s.pop_back();
                        s.pop_back();
                    }
                }
            }
            else if (digit4 == NULL && i < 1)
            {
                digit2 = digits[i + 1] - '0';
                digit3 = digits[i + 2] - '0';
                cout << "digit1: " << digit1 << " digit2: " << digit2 << endl;
                for (int k = 0; k < v[digit1].size(); k++)
                {
                    for (int l = 0; l < v[digit2].size(); l++)
                    {
                        for (int m = 0; m < v[digit3].size(); m++)
                        {
                            s.push_back(v[digit1][k]);
                            s.push_back(v[digit2][l]);
                            s.push_back(v[digit3][m]);
                            ans.push_back(s);
                            s.pop_back();
                            s.pop_back();
                            s.pop_back();
                        }
                    }
                }
            }
            else
            {
                digit2 = digits[i + 1] - '0';
                digit3 = digits[i + 2] - '0';
                digit4 = digits[i + 3] - '0';
                for (int j = i + 1; j < n; j++)
                {
                    cout << "digit1: " << digit1 << " digit2: " << digit2 << endl;
                    // if (digits[j] != 0)
                    //     digit2 = digits[j] - '0';
                    // if (digit2 == NULL)
                    //     digit2 = 0;
                    for (int k= j + 1; k < n; k++)
                    {
                        for (int l = k + 1; l < n; l++)
                        {
                            for (int m = 0; m < v[digit1].size(); m++)
                            {
                                for (int n = 0; n < v[digit2].size(); n++)
                                {
                                    for (int o = 0; o < v[digit3].size(); o++)
                                    {
                                        for (int p = 0; p < v[digit4].size(); p++)
                                        {
                                            s.push_back(v[digit1][m]);
                                            s.push_back(v[digit2][n]);
                                            s.push_back(v[digit3][o]);
                                            s.push_back(v[digit4][p]);
                                            ans.push_back(s);
                                            s.pop_back();
                                            s.pop_back();
                                            s.pop_back();
                                            s.pop_back();
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};


int main()
{
    Solution s;
    vector<string> ans = s.letterCombinations("234");
    for (auto i : ans)
        cout << i << endl;
    return 0;
}