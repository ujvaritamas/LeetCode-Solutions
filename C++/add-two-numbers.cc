#include <iostream>
#include <vector>
using namespace std;

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


//TODO correction needed
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector <int> v1, v2, sum;
        v1 = getNumbers(l1);
        v2 = getNumbers(l2);
        sum = addNumbers(v1, v2);

        printVector(v1);
        printVector(v2);
        printVector(sum);

        ListNode* ret = convertVectorToListNode(sum);
        return ret;
    }
private:
    void printVector(vector<int> v1){
        for(auto i:v1){
            cout <<i<<" ";
        }
        cout << endl;
    }

    struct NumberCarry{
        int val;
        int carry;
    };

    NumberCarry addTwoDigit(int d1, int d2, int carry){
        NumberCarry res = {0,0};
        int temp = d1+d2+carry;

        if(temp>=10){
            res.carry = 1;
            res.val = temp-10;
        }
        else{
            res.val = temp;
        }
        return res;
    }

    vector<int> addNumbers(vector<int> v1, vector<int> v2){
        vector <int> ret;
        int v1_size = v1.size();
        int v2_size = v2.size();
        int size = max(v1_size, v2_size);

        int element1;
        int element2;
        NumberCarry sum_res = {0,0};


        for (int i = 0; i < size; i++) {
            element1 = i<v1_size ? v1[i] : 0;
            element2 = i<v2_size ? v2[i] : 0;

            sum_res = addTwoDigit(element1, element2, sum_res.carry);
            ret.push_back(sum_res.val);
        }

        if (sum_res.carry){
            ret.push_back(sum_res.carry);
        }

        return ret;
    }


    vector<int> getNumbers(ListNode* l) {
        vector<int> nums;
        while (l) {
            nums.push_back(l->val);
            l = l->next;
        }
        return nums;
    }

    ListNode* convertVectorToListNode(vector<int> v) {
        ListNode* ret = nullptr;

         while (!v.empty())
        {
            ListNode* node = new ListNode(v.back());
            v.pop_back();
            node->next = ret;
            ret = node;
            cout<<node<<" "<<ret<<" "<<ret->val <<"->"<<ret->next <<endl;
        }
        return ret;
    }
};

class Solution2{
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int carry = 0;

            ListNode* ret

            while(l1 != nullptr || l2!=nullptr){
                int sum =carry;

            if (l1 != nullptr) {
                sum = sum+ l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum = sum+ l2->val;
                l1 = l2->next;
            }

                if (sum>=10){
                    sum = sum-10;
                    carry=1;
                }
                else{
                    carry=0;
                }


            }
        }
};