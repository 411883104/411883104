//统计数字 https://www.lanqiao.cn/problems/535/learning
#include<bits/stdc++.h>
using namespace std;
int nums[200010];
int main() {
    int n;    scanf("%d",&n);
    for(int i = 1; i <= n; i++)    scanf("%d",&nums[i]);
    sort(nums+1, nums+1+n);
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        cnt++;
        if(nums[i] != nums[i+1]) {
           printf("%d %d\n", nums[i], cnt);
           cnt = 0;
        }
    }
}
