/*
 * @Author: Outsider
 * @Date: 2021-11-22 14:43:22
 * @LastEditors: Outsider
 * @LastEditTime: 2021-11-22 15:01:24
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test2\HafuTree.cpp
 */

#include<iostream>
using namespace std;


int main()
{
    string str="The Chinese official said he viewed the Trump Presidency not as an aberration but as the product of a failing political system. This jibes with other accounts. The Chinese leadership believes that the United States,  and  Western  democracies in  general,  haven’t  risen  to  the challenge of a globalized economy, which necessitates big changes in production patterns, as well as major upgrades in education and public infrastructure. In Trump and Trumpism, the Chinese see an inevitable backlash to this failure.";
    int upper[27]={0};
    int lower[27]={0};
    for(int i=0;i<str.length();i++)
    {
        if(65<=str[i]&&str[i]<=91)
            upper[str[i]-64]++;
        if(97<=str[i]&&str[i]<=123)
            lower[str[i]-96]++;
    }
    for(int i=1;i<27;i++)
        cout<<upper[i]<<' ';
    cout<<endl;
    for(int i=1;i<27;i++)
        cout<<lower[i]<<' ';
    cout<<endl;
    system("pause");
}