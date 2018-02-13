#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int tmp;
        if(stack1.empty() && stack2.empty())
        {
            cout << "The queue is empty";
        }
        else if(!stack2.empty())  //栈2不空,直接pop
        {
            tmp = stack2.top();
            stack2.pop();
        }
        else if(!stack1.empty())  //栈1全部pop,并push进入栈2
        {
            while(!stack1.empty())
            {
                tmp = stack1.top();
                stack1.pop();
                stack2.push(tmp);
            }
            stack2.pop();
        }
        return tmp;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main()
{
    Solution s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    return 0;
}