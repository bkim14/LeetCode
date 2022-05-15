#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        // 1 2 3 4 2 4 6 8
        int length = changed.size();
        if (length & 1) return {};

        int* countArray = new int[1000000 + 1];//맵?

        memset(countArray, 0x00, sizeof(int) * 1000000 + 1);

        vector<int> orderedKeys;
        for (int x : changed) {
            countArray[x]++;
            orderedKeys.push_back(x);
        }

        sort(orderedKeys.begin(), orderedKeys.end());
        vector<int> res; //정답

        for (int x : orderedKeys) {
            if (!countArray[x]) continue;

            if (countArray[2 * x]) { //0이면? changed에 0이 하나밖에 없다.
                res.push_back(x);
                countArray[2 * x]--;
                countArray[x]--;
                if (countArray[x] < 0) return {}; //0인 경우 처리
                if (res.size() == length / 2) return res;
            }
        }
        return {};

    }
};



int main() {
    Solution s;
    int arr[4]={0,0,0,0};
    vector<int> input(arr, arr + sizeof(arr) / sizeof(int));
    s.findOriginalArray(input);

	return 0;
}