#include <vector>
#include <iostream>

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
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {

private:
    void printLinkedList(ListNode*);
    void insertNode(ListNode*, ListNode*);
    ListNode* insertList(ListNode*, ListNode*);
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        printLinkedList(lists[0]);
        ListNode* ret = lists[0];
        for (auto i= 1; i<lists.size(); i++){
             ret = insertList(ret, lists[i]);
        }
        printLinkedList(ret);

        return ret;
    }
};

void Solution::printLinkedList(ListNode* node){
    ListNode* tmpNode = node;
    cout<<"--------------------------------"<<endl;
    cout<<"root node value: "<<tmpNode->val<<endl;

    while(tmpNode){
        cout<<"val: "<<tmpNode->val<<" -> ";
        tmpNode = tmpNode->next;
    }
    cout<<"nullptr"<<endl;
    cout<<"--------------------------------"<<endl;
}

void Solution::insertNode(ListNode* cur, ListNode* insertNode){
    cout<<"INSERT after: "<<cur->val<<endl;

    insertNode->next = cur->next;
    cur->next = insertNode;
}

ListNode* Solution::insertList(ListNode* rootNode, ListNode* insertElements){
    ListNode* curNode;
    curNode = rootNode;

    if(!curNode){
        return insertElements;
    }

    while(insertElements){
        cout<<"insert element: "<<insertElements->val<<endl;
        while(curNode){
            cout<<"current element: "<<curNode->val<<endl;
            //bigger than the current or equal
            if(curNode->val <= insertElements->val){
                if(curNode->next){
                    //smaller than the next
                    if(curNode->next->val > insertElements->val){
                        ListNode* node = new ListNode(insertElements->val);
                        insertNode(curNode, node);
                        curNode = curNode->next;
                        break;
                    }
                    else{
                        curNode = curNode->next;
                        continue;
                    }
                }
                else{
                    ListNode* node = new ListNode(insertElements->val);
                    insertNode(curNode, node);
                    curNode = curNode->next;
                    break;
                }
            }
            curNode = curNode->next;

        }
        insertElements = insertElements->next;
    }
    return rootNode;
}
