class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxx=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(sum<0)
            {
                sum=nums.at(i);//���ǰ��ĺ�С���㣬��ӵ�ǰ��ʼ�㡣
            }
            else
            {
                sum+=nums.at(i);
            }
            maxx=max(sum,maxx);//ÿһ�ζ�ȡ���ֵ��
        }
        return maxx;
    }
};
