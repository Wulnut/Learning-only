//https://leetcode-cn.com/problems/two-sum/

/**
 * 用到了一个知识点就是使用sort()函数经行自定义，来对vector<rank>容器进行排序
 *   #include <algorithm>
     #include <vector>

    vector<int> vec;
    //比较函数，这里的元素类型要与vector存储的类型一致
    bool compare(int a,int b)
    {
    return a<b; //升序排列
    }

    std::sort(vec.begin(),vec.end(),compare);

 * 由于sort()函数如果不声明比较函数就是默认升序，从小到大
 * 
 * 1.利用find()函数来对vector进行查找
 *    源码：
 *          
 *      vector<int> vec;
 *      int a = 0;
 *      vector<int>::iterator ite = vec.find(vec.begin(), vec.end(), a);
 * 
 *  
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> result;

        for (int i = 0; i < nums.size() - 1; ++ i) {
            for (int j = i + 1; j < nums.size(); ++ j) {
                if (nums[i] + nums[j] == target) {

                    result.push_back(i);
                    result.push_back(j);
                    
                }
            }
        }

        return result;

}

vector<int> twoSum_2(vector<int>& nums, int target) {
        //Key是数字，value是该数字的index
        unordered_map<int, int> hash;
        vector<int> result;
        int numsSize = int(nums.size());

        for (int i = 0; i < numsSize; ++ i){
        
            int numberToFind = target - nums[i];

            //如果找到numberToFind，就return
            if (hash.find(numberToFind) != hash.end()){
            
                result.push_back(hash[numberToFind]);
                result.push_back(i);
                return result;
            }

            //如果没有找到，把该数字的index放到hash表中
            hash[nums[i]] = i;
        }
        
        return result;
}


int main() {

    int a[3] = {3, 2, 4};

    vector<int> result;
    vector<int> nums(a, a + 3);

    result = twoSum(nums, 6);

    for (const auto& i : result) {
        cout << i << endl;
    }

    return 0;
}

// 为了对运行时间复杂度进行优化，我们需要一种更有效的方法来检查数组中是否存在目标元素。如果存在，我们需要找出它的索引。保持数组中的每个元素与其索引相互对应的最好方法是什么？哈希表。

// 通过以空间换取速度的方式，我们可以将查找时间从 O(n)O(n) 降低到 O(1)O(1)。哈希表正是为此目的而构建的，它支持以 近似 恒定的时间进行快速查找。我用“近似”来描述，是因为一旦出现冲突，查找用时可能会退化到 O(n)O(n)。但只要你仔细地挑选哈希函数，在哈希表中进行查找的用时应当被摊销为 O(1)O(1)。
