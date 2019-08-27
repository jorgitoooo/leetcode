/* ---------------
 * Jorge L. Garcia
 * 8/25/2019
 * ---------------
 * Two Sum 
 */

#include <unordered_map>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

std::vector<int> twoSum(const std::vector<int>& nums, const int target)
    {
        std::unordered_map<int,int> m;
        for(int i = 0; i < nums.size(); i++)
            if(m.find(target - nums[i]) != m.end()) return {m[target-nums[i]], i};
            else m[nums[i]] = i;
        
        return {}; 
    }

int main(int argc, char **argv)
{

	std::vector<int> vec = twoSum({1,5,-4,9}, 5);

	for(auto index : vec) std::cout << index << ' ';
	std::cout << '\n';

	return 0;
}
