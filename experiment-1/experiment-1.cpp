#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

int op = 0;
int depth = 0;

void complexRec(int n)
{

    depth++;
    if (n <= 2)
    {
        depth--;
        return; // 1
    }

    int p = n;
    while (p > 0)
    { // log n
        vector<int> temp(n);
        for (int i = 0; i < n; i++)
        { // n
            temp[i] = i ^ p;
            op++;
        }
        p >>= 1;
    }
    // n log n -> time

    vector<int> small(n);
    for (int i = 0; i < n; i++)
    { // n
        small[i] = i * i;
        op++;
    }

    if (n % 3 == 0)
    { // 1
        reverse(small.begin(), small.end());
        op++;
    }
    else
    {
        reverse(small.begin(), small.end());
        op++;
    }

    complexRec(n / 2); // n/2
    complexRec(n / 2); // n/2
    complexRec(n / 2); // n/2
    depth--;
}

int main()
{
    auto start = high_resolution_clock::now();

    complexRec(20);

    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Execution time: " << duration.count() << endl;
    cout << "Number of operations: " << op << endl;
    cout << "Depth = " << depth;
}
// Recurence relation = 3 T(n/2) + n log n
// time complexity using master theorem : O(n^log(2)3)