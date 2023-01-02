#include <iostream>
#include <climits>

using namespace std;

struct ListNode {
    long val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(long x) : val(x), next(nullptr) {}
};

int main() {
    long count = 0, sum = 0, count1 = 0;
    long n, m;
    scanf("%ld %ld", &n, &m);

    ListNode *dummyHeadA = new ListNode();
    ListNode *cur1 = dummyHeadA;
    long min = LONG_MAX;
    for (long i = 0; i < n; i++) {
        long temp;
        scanf("%ld", &temp);
        ListNode* newNode = new ListNode();
        newNode->val = temp;
        if(temp < min)
            min = temp;
        if(temp <= m){
            m -= temp;
            count1++;
            sum += temp;
            cur1->next = newNode;
            cur1 = cur1->next;
        } else{
            delete newNode;
        }
    }

    count += count1 * (m / sum + 1);
    m = m % sum;

    while(m >= min){
        ListNode *cur2 = dummyHeadA;
        long sum2 = 0, count2 = 0;
        while(cur2->next != nullptr){
            long price = cur2->next->val;
            if(m >= price){
                m -= price;
                sum2 += price;
                count2++;
                cur2 = cur2->next;
            } else{
                ListNode* temp = cur2->next;
                cur2->next = cur2->next->next;
                delete temp;
            }
        }
        count += count2 * (m / sum2 + 1);
        m = m % sum2;
    }

    printf("%ld", count);
}
