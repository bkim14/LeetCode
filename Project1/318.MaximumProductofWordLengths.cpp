#include "stddef.h"
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
    static     bool cmp(string s1, string s2) {
        return s1.size() > s2.size();
    }
public:



    int toTheBit(string s) {
        int ret = 0;
        for (int i = 0;i < s.size();i++) {
            int bit = 1 << (s[i] - 'a');
            ret |= bit;
        }
        return ret;
    }

    int maxProduct(vector<string>& words) {

        sort(words.begin(), words.end(), cmp);

        vector<int> bits;
        for (string s : words) {
            bits.push_back(toTheBit(s));
        }
        int compLimit = 1;
        int ret = 0;
        for (int i = 0;i < words.size();i++) {
             for (int j = i + 1;j < words.size();j++) {
                if (!(bits[i] & bits[j])) {
                    int mult = words[i].size() * words[j].size();
                    ret = mult > ret ? mult : ret;
                }
            }
        }
        return ret;
    }
};

bool cmp(string s1, string s2) {
    return s1.size() > s2.size();
}

int main() {
    Solution s;
    vector<string> input;
    input.push_back("abcw");
    input.push_back("baz");
    input.push_back("foo");
    input.push_back("bar");
    input.push_back("xtfn"),
    input.push_back("abcdef");
    //sort(input.begin(), input.end(), &cmp);
    int x=s.maxProduct(input);
    return 0;
}