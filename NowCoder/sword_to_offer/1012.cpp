#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
        int i;
        double ret = 1;
        //需要考虑负数
        if(0 == exponent)
        {
            ret = 1;
        }
        else if(exponent > 0)
        {
            for(i=1; i<=exponent; i++)
            {
                ret = ret *base;
            }
        }
        else
        {
            exponent = -exponent;
            for(i=1; i<=exponent; i++)
            {
                ret = ret *base;
            }
            ret = 1/ret;
        }
        return ret;
    }
};

int main()
{
    Solution s1;
    return 0;
}