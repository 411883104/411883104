/*
 * @Author       : Outsider
 * @Date         : 2023-06-04 15:22:57
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-06-04 15:36:41
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Eq\P8699.cc
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int c = 505;

int main()
{
    vector<int> nums;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        nums.push_back(i);
    }
    sort(nums.begin(), nums.end());
    int res = 0;
    do
    {
        int ans = 0;
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1] && nums[i] > nums[i - 1])
            {
                ans++;
            }
            else if (nums[i] < nums[i + 1] && nums[i] < nums[i - 1])
            {
                ans++;
            }
        }
        if (ans + 1 == k)
        {
            res++;
        }
    } while (next_permutation(nums.begin(), nums.end()));
    cout << res << endl;
    return 0;
}