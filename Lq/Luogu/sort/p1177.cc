// /*
//  * @Author: Outsider
//  * @Date: 2023-01-05 11:19:03
//  * @LastEditors: Outsider
//  * @LastEditTime: 2023-01-06 09:41:38
//  * @Description: In User Settings Edit
//  * @FilePath: \Lq\Luogu\sort\p1177.cc
//  */
// #include <iostream>

// using namespace std;

// int arr[100005];
// void swap(int &x, int &y)
// {
//     int temp = x;
//     x = y;
//     y = temp;
// }

// void pivot(int left, int right)
// {
//     int idx = left + ((right - left) >> 1);
//     if (arr[left] > arr[right])
//     {
//         swap(arr[left], arr[right]);
//     }
//     if (arr[idx] > arr[right])
//     {
//         swap(arr[idx], arr[right]);
//     }
//     if (arr[left] < arr[idx])
//     {
//         swap(arr[left], arr[idx]);
//     }
// }

// void isort(int left, int right)
// {
//     for (int i = left; i < right; i++)
//     {
//         for (int j = i + 1; j > 0; j--)
//         {
//             if (arr[j] < arr[j - 1])
//             {
//                 swap(arr[j], arr[j - 1]);
//             }
//         }
//     }
// }

// void qsort(int left, int right)
// {
//     int start = left, end = right;
//     while (start < end)
//     {
//         // int idx = start + (end - start) / 2;
//         pivot(start, end);
//         int cnt = arr[start];
//         while (start < end)
//         {
//             while (end > start && arr[end] >= cnt)
//             {
//                 end--;
//             }
//             arr[start] = arr[end];
//             while (start < end && arr[start] <= cnt)
//             {
//                 start++;
//             }
//             arr[end] = arr[start];
//             // idx = start;
//         }
//         arr[start] = cnt;
//         qsort(left, start - 1);
//         // qsort(start + 1, right);

//         start++;
//         left = start;
//         end = right;
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     qsort(0, n - 1);
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     cout << endl;
// }

// /*
//  * @Author: Outsider
//  * @Date: 2023-01-05 11:19:03
//  * @LastEditors: Outsider
//  * @LastEditTime: 2023-01-06 09:41:38
//  * @Description: In User Settings Edit
//  * @FilePath: \Lq\Luogu\sort\p1177.cc
//  */
// #include <iostream>

// using namespace std;

// int arr[100005];
// void swap(int &x, int &y)
// {
//     int temp = x;
//     x = y;
//     y = temp;
// }

// void pivot(int left, int right)
// {
//     int idx = left + ((right - left) >> 1);
//     if (arr[left] > arr[right])
//     {
//         swap(arr[left], arr[right]);
//     }
//     if (arr[idx] > arr[right])
//     {
//         swap(arr[idx], arr[right]);
//     }
//     if (arr[left] < arr[idx])
//     {
//         swap(arr[left], arr[idx]);
//     }
// }

// void isort(int left, int right)
// {
//     for (int i = left; i < right; i++)
//     {
//         for (int j = i + 1; j > 0; j--)
//         {
//             if (arr[j] < arr[j - 1])
//             {
//                 swap(arr[j], arr[j - 1]);
//             }
//         }
//     }
// }

// void qsort(int left, int right)
// {
//     int start = left, end = right;
//     while (start < end)
//     {
//         // int idx = start + (end - start) / 2;
//         pivot(start, end);
//         int cnt = arr[start];
//         int idx = start;
//         start -= 1;
//         end += 1;
//         while (start < end)
//         {
//             while (end > start && arr[--end] > cnt)
//                 ;
//             arr[idx] = arr[end];
//             while (start < end && arr[++start] < cnt)
//                 ;
//             arr[end] = arr[start];
//             idx = start;
//         }
//         arr[start] = cnt;
//         qsort(left, start - 1);
//         // qsort(start + 1, right);

//         start++;
//         left = start;
//         end = right;
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     qsort(0, n - 1);
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     cout << endl;
// }

#include <iostream>

using namespace std;

int arr[100005];
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void pivot(int left, int right)
{
    int idx = left + ((right - left) >> 1);
    if (arr[left] > arr[right])
    {
        swap(arr[left], arr[right]);
    }
    if (arr[idx] > arr[right])
    {
        swap(arr[idx], arr[right]);
    }
    if (arr[left] < arr[idx])
    {
        swap(arr[left], arr[idx]);
    }
}

void isort(int left, int right)
{
    for (int i = left; i < right; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
}

void qsort(int left, int right)
{
    int start = left, end = right;
    while (start < end)
    {
        // int idx = start + (end - start) / 2;
        pivot(start, end);
        int cnt = arr[start];
        int idx = start;
        // start -= 1;
        end += 1;
        while (start < end)
        {
            while (end > start && arr[--end] > cnt)
                ;
            // arr[idx] = arr[end];
            while (start < end && arr[++start] < cnt)
                ;
            // arr[end] = arr[start];
            // idx = start;
            swap(arr[start], arr[end]);
        }
        // arr[start] = cnt;
        swap(arr[idx], arr[start]);
        qsort(left, start - 1);
        // qsort(start + 1, right);

        start++;
        left = start;
        end = right;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    cout << endl;
}