#include <iostream>
#include <climits>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val):val(val), next(nullptr){}
};

ListNode* insertElement(ListNode* head, int position, int num);
ListNode* changeElement(ListNode* head, int position, int changedVal);
ListNode* findElement(ListNode* head, int left, int right, int k);

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    scanf("%d %d", &n, &m);

    ListNode *dummyHead = new ListNode(0);
    ListNode *cur1 = dummyHead;
    for (int i = 0; i < n; i++) {
        ListNode* newNode = new ListNode(0);
        scanf("%d", &newNode->val);
        cur1->next = newNode;
        cur1 = cur1->next;
    }
    ListNode *head = dummyHead->next;


//    ListNode *curt1 = dummyHead->next;
//    while(curt1 != nullptr){
//        printf("%d ", curt1->val);
//        curt1 = curt1->next;
//    }

//    ListNode *curt0 = head;
//    int countt0 = 0;
//    while(curt0 != nullptr){
//        countt0++;
//        head = insertElement(head, countt0, curt0->val + 1);
//        curt0 = curt0->next;
//    }

    while(m--){
        char operation = 'A';
        cin >> operation;
        if(operation == 'I'){
            int p = 0, v = 0;
            cin >> p >> v;
            printf("%c %d %d", operation, p, v);
        } else if(operation == 'M'){
            int p = 0, v = 0;
            cin >> p >> v;
            printf("%c %d %d", operation, p, v);
        } else{
            int l = 0, r = 0, k = 0;
            cin >> l >> r >> k;
            printf("%c %d %d %d", operation, l, r, k);
        }
    }
//    ListNode *cur2 = head;
//    while(cur2 != nullptr){
//        printf("%d ", cur2->val);
//        cur2 = cur2->next;
//    }

}

ListNode* insertElement(ListNode* head, int position, int num){
    ListNode* newNode = new ListNode(num);
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode *cur = dummyHead;
    while(--position)
        cur = cur->next;
    newNode->next = cur->next;
    cur->next = newNode;
    return dummyHead->next;
}


ListNode* changeElement(ListNode* head, int position, int changedVal){
    ListNode *cur = head;
    int count = 0;
    while(cur != nullptr){
        count++;
        if(count == position){
            cur->val = changedVal;
            break;
        }
        cur = cur->next;
    }
    return head;
}

ListNode* findElement(ListNode* head, int left, int right, int k){
    int domain = right - left + 1;

    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode *cur = dummyHead;
    while(left--)
        cur = cur->next;

    ListNode *leftHead = cur;
    int min = INT_MAX;
    while(domain--){
        if(cur->val < min)
            min = cur->val;
        cur = cur->next;
    }

    while(domain--){
        if(leftHead->val < min)
            k--;

        leftHead = leftHead->next;
    }
}
