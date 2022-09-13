#include "bits/stdc++.h"

using namespace std;

int main(void)
{
    vector<int> V(3, -1);
    for(int i = 0; i < V.size(); i++)
    {
        cout << V[i] << " ";
    }
    cout << "\n\n";

    V.push_back(4);
    vector<int> :: iterator it;
    for(it = V.begin(); it != V.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // 'auto' Register in range based traversal
    for(auto element: V)
    {
        cout << element << " ";
    }
    cout << endl;
    // auto register in place of iterator
    for(auto it = V.begin(); it != V.end(); it++)
    {
        cout << *it << " ";
    }
}