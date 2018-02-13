#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isOdd(int a)
    {
        return (a%2 ==1)? true:false;
    }
    void reOrderArray(vector<int> &array) {
        vector<int> tmp = array;
        int num = array.size();
        int i,j,k=0;
        for(i=0; i < num; i++)
        {
            if(isOdd(tmp[i])){
                array[k++] = tmp[i];
            }
        }
        for(i=0; i < num; i++)
        {
            if(!isOdd(tmp[i])){
                array[k++] = tmp[i];
            }
        }
    }
};

int main()
{
    Solution s1;
    vector<int> array = {1,2,3,4,5,6,7,8,9,10};
    int i;
    int num = array.size();
    for(i=0; i < num; i++)
    {
        cout << array[i] << endl;
    }
    s1.reOrderArray(array);
    for(i=0; i < num; i++)
    {
        cout << array[i] << endl;
    }
    return 0;
}