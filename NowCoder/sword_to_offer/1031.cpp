#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int m, i, j;
        vector<int> v1;
        for(i=1; i<=n; i++){
            m = i;
            while(m)
            {
                j = m%10;
                if(1 == j){
                    v1.push_back(j);
                }
                m = m/10;
            }
        }
        return v1.size();
    }
};

int main()
{
    Solution s1;
    cout << s1.NumberOf1Between1AndN_Solution(100) << endl;
    return 0;
}