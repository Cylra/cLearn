#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isInt(string str)
    {
        int len = str.size();
        bool bInt = true;
        if(!(str[0] == '+' || str[0] == '-' || isdigit(str[0]))){
            bInt = false;
        }
        int i;
        for(i=1; i <len; i++){
            if(isalpha(str[i])){
                bInt = false;
                break;
            }
        }
        return bInt;
    }

    int StrToInt(string str) {
        vector<int> v1;
        if(str == ""){
            return 0;
        }
        if(!isInt(str)){
            return 0;
        }
        int hasSign; //是否有符号
        if(str[0] == '+'){
            hasSign = 1;
        }
        else if(str[0] == '-'){
            hasSign = -1;
        }
        else{
            hasSign = 0;
        }

        int i;
        for(i=str.size()-1; i > 0; i--)
        {
            v1.push_back(str[i] - '0');
        }
        if(hasSign == 0){
            v1.push_back(str[0] - '0');
        }
        int sum = 0;
        int len = v1.size();
        for(i=0; i<len; i++){
            sum = sum + v1[i] * pow(10, i);
        }
        if(-1 == hasSign){
            sum = -sum;
        }
        return sum;
    }
};

int main()
{
    Solution s1;
    string str = "-123456789";
    cout << str.c_str()  << endl;
    cout << s1.StrToInt(str) << endl;
    return 0;
}