/*
Problem Description:
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> results;
        vector<string> temp;
        BackTracking(s,results,temp,0);
        return results;
    }
    
    void BackTracking(string s,vector<vector<string>>& results,vector<string>& temp,int start)
    {
        int n=s.size();
        if(start==n)
        {
            results.emplace_back(temp);
            return;
        }
        string tempStr="";
        for(int i=start;i<n;i++)
        {
            tempStr=s.substr(start,i-start+1);
            if(isPalindrome(tempStr))
            {
                temp.emplace_back(tempStr);
                BackTracking(s,results,temp,i+1);
                temp.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s)
    {
        bool flag=true;
        int n=s.size();
        for(int i=0,j=n-1;i<j;i++,j--)
        {
            if(s[i]!=s[j])
            {
                flag=false;
                break;
            }
        }
        return flag;
    }
};