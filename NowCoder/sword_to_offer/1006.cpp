#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty())
            return 0;
        int count = rotateArray.size();
        int result = 0;
        for (int i = 0; i < count; i++)
        {
            cout << rotateArray[i] << endl;
            if(rotateArray[i] > rotateArray[i+1])
            {
                result = rotateArray[i+1];
                break;
            }
        }
        return result;
    }
};

int main()
{
    Solution s1;
    vector<int> rotateArray = {3, 4, 5, 1, 2};
    s1.minNumberInRotateArray(rotateArray);
    return 0;
}