#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        int div = sum/2 +1;
        vector<vector<int> > result;
        vector<int> tmp;
        int i, j, All;
        for(i=1; i<div; i++){
            j = i;
            All = 0;
            cout << "循环初始值=" << i << endl;
            while(All < sum){
                All += j; 
                tmp.push_back(j);
                j++;
            }
            cout << "-----累加值=" << All << endl;
            if(All == sum){
                result.push_back(tmp);
            }
            tmp.clear();
        }
        return result;
    }
};

int main()
{
    Solution s1;
    s1.FindContinuousSequence(100);
    return 0;
}