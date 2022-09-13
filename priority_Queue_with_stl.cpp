#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> PAIR;

int main(void)
{
    // maximum priority queue
    priority_queue<int, vector<int>> pq;
    pq.push(1);
    pq.push(5);
    pq.push(3);

    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    // minimum priority queue
    priority_queue<PAIR, vector<PAIR>, greater<PAIR>> minPQ;

    minPQ.push(make_pair(1, 9));
    minPQ.push(make_pair(4, 2));
    minPQ.push(make_pair(6, 1));

    while(!minPQ.empty())
    {
        cout << minPQ.top().first << "|" << minPQ.top().second << endl;
        minPQ.pop();
    }
}