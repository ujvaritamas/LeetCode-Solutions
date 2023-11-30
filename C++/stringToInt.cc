#include <string>
#include <cctype>
#include <iostream>
#include <limits>

using namespace std;



class Solution {
private:
    const int CONVERSATION_NUMBER = 48;

    bool addCharToInt(long& result, const char& charToAdd){
        result = result*10+static_cast<int>(charToAdd)-Solution::CONVERSATION_NUMBER;
        if (result>INT_MAX){
            return true;
        }
        return false;
    }

    int clampConvert(long arg){
        arg= arg<INT_MIN? INT_MIN: arg;
        arg= arg>INT_MAX? INT_MAX: arg;
        return static_cast<int>(arg);
    }

public:
    int myAtoi(string s) {
        bool isFirstNumberFound = false;
        int sign = 1;
        long ret = 0;
        //string numberStr = "";
        bool isReadStarted = false;

        for(auto c:s){
            if(isdigit(c)){
                isFirstNumberFound = true;
                bool isOverflow= addCharToInt(ret, c);
                if(isOverflow){
                    break;
                }
                //numberStr += c;
            }
            else if(!isFirstNumberFound){
                if(c == ' '){continue;}
                else if(c =='-' || c=='+'){
                    sign = (c=='-')? -1: 1;
                    isFirstNumberFound = true;
                    //numberStr += c;
                    continue;
                }
                break;
            }
            else{
                break;
            }
        }
        return clampConvert(sign*ret);
    }
};