#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        vector<int> v1;
        int i, len = array.size();
        int sum;
        int j;
        for(j=0; j< len; j++)
        {
            sum = 0;
            for(i=j; i<len; i++){
                sum += array[i];
                v1.push_back(sum);
            }
        }

        sort(v1.begin(),v1.end());
        reverse(v1.begin(),v1.end());
        // for(i=0; i<v1.size(); i++)
        //     cout << v1[i] << " ";
        // cout << endl;
        return v1[0];
    }
};

int main()
{
    Solution s1;
    vector<int> array = {1,-2,3,10,-4,7,2,-5};
    cout << s1.FindGreatestSumOfSubArray(array) << endl;
    return 0;
}