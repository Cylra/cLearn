#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        int i, len = str.size();
        string result;
        int pos;
        for(i=0; i<len; i++){
            pos = (i + n) % len;
            result.push_back(str[pos]);
        }
        return result;
    }
};

int main()
{
    Solution s1;
    string str = "abcXYZdef";
    cout << s1.LeftRotateString(str, 3) << endl;
    return 0;
}