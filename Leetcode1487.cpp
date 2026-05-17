#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string,vector<int>> mp;
        vector<int> number;
        for(int i=0;i<names.size();i++)
        {
            string s="";
            string num="";
            for(int j=0;j<names[i].size();j++)
            {
                if(names[i][j]=='(' || names[i][j]==')')
                {
                    continue;
                }
                if(isdigit(names[i][j]))
                {
                    num+=names[i][j];
                    continue;
                }
                s+=names[i][j];
            }
            int num1=0;
            if(num.size()>0)
            {
                num1=stoi(num);
            }
            if(mp.find(s)!=mp.end())
            {
                int digit=mp[s].back();
                if(digit>=num1)
                {
                    num1=digit+1;
                }
            }
            mp[s].push_back(num1);
            number.push_back(num1);
        }
        string s1="";
        vector<string> res;
        for(auto &p : mp)
        {
            for(int i=0;i<p.second.size();i++)
            {
                s1+=p.first;
                if(p.second[i]==0)
                {
                    res.push_back(s1);
                    s1.clear();
                    continue;
                }
                s1+='(';
                s1+=to_string(p.second[i]);
                s1+=')';
                res.push_back(s1);
                s1.clear();
            }
        }
        vector<string> ans1;
        for(int i=0;i<names.size();i++)
        {
            for(int j=0;j<names[i].size();j++)
            {
                if(names[i][j]=='(')
                {
                    names[i].erase(j);
                    break;
                }
            }
        }
        for(int i=0;i<names.size();i++)
        {
            string s2="";
            s2=names[i];
            if(number[i]>0)
            {
                s2+='(';
                s2+=to_string(number[i]);
                s2+=')';
            }
            ans1.push_back(s2);
        }
        return ans1;
    }
};