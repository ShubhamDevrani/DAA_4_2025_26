#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> map;

    int sum = 0;
    int maxLen = 0;

    map[0] = -1;
    for (int i=0; i<n; i++){
        char ch;
        cin >> ch;
        if (ch=='P')
            sum += 1;
        else
            sum -= 1;

        if(map.find(sum) != map.end()){
            int length = i - map[sum];
            maxLen = max(maxLen, length);
        } else {
            map[sum] = i;
        }
    }

    cout << maxLen << endl;

    return 0;
}