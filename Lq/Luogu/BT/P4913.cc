/*
 * @Author: Outsider
 * @Date: 2023-02-24 08:58:45
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-24 09:55:27
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\BT\P4913.cc
 */
#include <iostream>

using namespace std;

class Tree
{
public:
    Tree *ll, *rr;
    int nn;
};
Tree *tree;

pair<int, int> tt[1000010];
int build(Tree *&tree)
{
    if (tree->nn == 0)
        return 0;
    tree->ll = new Tree();
    tree->ll->nn = tt[tree->nn].first;
    tree->rr = new Tree();
    tree->rr->nn = tt[tree->nn].second;
    int l = build(tree->ll);
    int r = build(tree->rr);
    return max(l, r) + 1;
}

int deep(Tree *tree)
{
    if (tree->nn == 0)
    {
        return 0;
    }
    int left = deep(tree->ll);
    int right = deep(tree->rr);
    return max(left, right) + 1;
}

int main()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> tt[i].first >> tt[i].second;
    }
    tree = new Tree();
    tree->nn = 1;
    cout << build(tree) << endl;
}