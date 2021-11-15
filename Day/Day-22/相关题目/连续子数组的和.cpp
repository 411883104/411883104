class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxx=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(sum<0)
            {
                sum=nums.at(i);//如果前面的和小于零，则从当前开始算。
            }
            else
            {
                sum+=nums.at(i);
            }
            maxx=max(sum,maxx);//每一次都取最大值。
        }
        return maxx;
    }
};
