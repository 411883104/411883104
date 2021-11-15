////#include<iostream>
////#include<map>
////using namespace std;
////map<int,int>m;
////int main()
////{
////    int n;
////    cin>>n;
////    for(int i=0;i<n;i++)
////    {
////        int x;
////        scanf("%d",&x);
////        m[x]++;
////    }
////    int sum=0;
////    map<int,int>::iterator it;
////    for(it=m.begin();it!=m.end();it++)
////    {
////        cout<<it->second<<endl;
////    }
////    cout<<sum<<endl;
////    return 0;
////}
//
//
//
//
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int c=1000005;
//int arr[c];
//int num[c];
//int finds(int x)
//{
//    if(arr[x]==x)
//       return x;
//    else
//        return arr[x]=finds(arr[x]);
//}
//int main()
//{
//    int n,m;
//    cin>>n>>m;
//    for(int i=1;i<=n;i++)
//    {
//        arr[i]=i;
//        cin>>num[i];
//    }
//    for(int i=0;i<m;i++)
//    {
//        int x,y;
//        cin>>x>>y;
//        int tx=finds(x);
//        int ty=finds(y);
//        arr[tx]=ty;
//        num[tx]=num[ty]=max(num[tx],num[ty]);
//        }
//    }
//    long long sum=0;
//    for(int i=1;i<=n;i++)
//    {   
//        sum+=num[finds(i)];
//    }
//    cout<<sum<<endl;
//    return 0;
//}



#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;
vector<int>q;
int main()
{
	q.push_back(5);
	for(int i=0;i<10;i++)
	{
		q.push_back(i);
	}
	vector<int>::iterator it=q.begin();
	cout<<q.size()<<endl;
	sort(it,it+q.size());
	for(int i=0;i<q.size();i++)
	{
		cout<<q.at(i)<<endl;
	}
	int arr[6];
	for(int i=0;i<6;i++)
	{
		cout<<&arr[i]<<endl;
	}
	int *p=arr;
	cout<<++p<<endl;
 } 
