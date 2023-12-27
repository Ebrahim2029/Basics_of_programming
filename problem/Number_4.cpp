#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void initializeString(vector<string>& curr, int n) {
        string ans = "";
        for (int i = 0; i < n; i++)
            ans += ".";

        for (int i = 0; i < n; i++) {
            curr[i] = ans;
        }
    }

    void ans(vector<int>& col, vector<int>& d1, vector<int>& d2, int n, int i, vector<vector<string>>& res, vector<string>& curr) {
        if (i == n) {
            res.push_back(curr);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (!col[j] && !d1[i - j + n - 1] && !d2[i + j]) {
                col[j] = true;
                d1[i - j + n - 1] = true;
                d2[i + j] = true;
                curr[i][j] = 'Q';
                ans(col, d1, d2, n, i + 1, res, curr);
                col[j] = false;
                d1[i - j + n - 1] = false;
                d2[i + j] = false;
                curr[i][j] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> col(n, false);
        vector<int> d1(2 * n, false);
        vector<int> d2(2 * n, false);
        vector<vector<string>> res;
        vector<string> curr(n);
        initializeString(curr, n);
        ans(col, d1, d2, n, 0, res, curr);

        return res;
    }
};

int main() {
    Solution sol;
    int n = 4;
    vector<vector<string>> solutions = sol.solveNQueens(n);
    for (auto solution : solutions) {
        for (auto row : solution) {
            cout << row << endl;
        }
        cout << "------------------" << endl;
    }
    return 0;
}
