#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    //使用非递归方法,避免栈溢出
    int Fibonacci(int n) {
        int i  = 0;
        int result = 0;
        int a=1,b=1;

        if(n<1)
            return 0;
        else if(n < 3){
            return 1;
        }
        else{
            for(i=3; i<=n; i++)
            {
                result = a+b;
                a = b;
                b = result;
            }
            return result;
        }
    }
};

int main()
{
    Solution s1;
    int i;
    for(i=1; i<=39; i++)
    {
        cout << s1.Fibonacci(i) << endl;
    }
    return 0;
}