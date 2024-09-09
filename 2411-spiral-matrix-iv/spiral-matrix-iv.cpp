/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* temp) {
        vector<vector<int>> ans(m,vector<int>(n,-1) );
        bool right = true,left = false,top = false,down=false;
        int i=0,j=0;
        while (temp) {
            ans[i][j] = temp->val;
            temp = temp->next;
            if (right) {
                if (j + 1 >= n || ans[i][j + 1] != -1) {
                    right = false;
                    down = true;
                    i++;
                } else {
                    j++;
                }
            } else if (down) {
                if (i + 1 >= m || ans[i + 1][j] != -1) {
                    down = false;
                    left = true;
                    j--;
                } else {
                    i++;
                }
            } else if (left) {
                if (j - 1 < 0 || ans[i][j - 1] != -1) {
                    left = false;
                    top = true;
                    i--;
                } else {
                    j--;
                }
            } else if (top) {
                if (i - 1 < 0 || ans[i - 1][j] != -1) {
                    top = false;
                    right = true;
                    j++;
                } else {
                    i--;
                }
            }
        }
        return ans;
    }
};