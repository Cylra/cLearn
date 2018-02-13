#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> tmp;
        int i,j, len = num.size();
        if(size > len || 0 == size ){
            return tmp;
        }
        int count;
        vector<int> result;
        for(i=0; i < len-size+1; i++){
            count = 0;
            //cout << "i=" << i << endl;
            for(j=i; j< len; j++){
                //cout << "---j=" << j << endl;
                //cout << "---num[j]=" << num[j] << endl;
                tmp.push_back(num[j]);
                count++;
                if(count == size)
                    break;
            }
            if(count == size){
                int k;
                for(k=0; k<tmp.size(); k++){
                    cout << tmp[k] << " ";
                }
                cout << endl;
                //寻找最大值
                int max = 0;
                for(k=0; k<tmp.size(); k++){
                    if(tmp[k] > max){
                        max = tmp[k];
                    }
                }
                result.push_back(max);
            }
            tmp.clear();
        }
        return result;
    }
};

int main()
{
    Solution s1;
    vector<int> num = {2,3,4,2,6,2,5,1};
    s1.maxInWindows(num, 3);
    return 0;
}