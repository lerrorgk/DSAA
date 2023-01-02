#include <iostream>

using namespace std;

struct ListNode {
    long coef, expon;
    ListNode *next;
    ListNode(long x, long y) : coef(x), expon(y), next(nullptr) {}
    ListNode() : coef(0), expon(0), next(nullptr) {}
};

int main() {
    long T;
    scanf("%ld", &T);
    while(T--){
        long n;
        scanf("%ld", &n);

        auto *dummyHeadA = new ListNode();
        ListNode *cur1 = dummyHeadA;
        for (long i = 0; i < n; i++) {
            long temp1, temp2;
            scanf("%ld %ld", &temp1, &temp2);
            if(temp1 != 0){
                auto* newNode = new ListNode(temp1, temp2);
                cur1->next = newNode;
                cur1 = cur1->next;
            }
        }


        long m;
        scanf("%ld", &m);
        auto *dummyHeadB = new ListNode();
        ListNode *cur2 = dummyHeadB;
        for (long j = 0; j < m; j++) {
            long temp1, temp2;
            scanf("%ld %ld", &temp1, &temp2);
            if(temp1 != 0){
                auto* newNode = new ListNode(temp1, temp2);
                cur2->next = newNode;
                cur2 = cur2->next;
            }
        }

        auto *dummyHeadResult = new ListNode();
        long count = 0;
        ListNode *curR = dummyHeadResult;
        ListNode *curA = dummyHeadA->next;
        ListNode *curB = dummyHeadB->next;
        while (curA != nullptr && curB != nullptr){
            if(curA->expon == curB->expon){
                long newCoef = curA->coef + curB->coef;
                if(newCoef != 0){
                    auto* newNode = new ListNode(newCoef, curA->expon);
                    curR->next = newNode;
                    curR = curR->next;
                    count++;
                }
                curA = curA->next;
                curB = curB->next;
            } else if(curA->expon < curB->expon){
                auto* newNode = new ListNode(curA->coef, curA->expon);
                curR->next = newNode;
                curR = curR->next;
                curA = curA->next;
                count++;
            } else{
                auto* newNode = new ListNode(curB->coef, curB->expon);
                curR->next = newNode;
                curR = curR->next;
                curB = curB->next;
                count++;
            }
        }


        if(curA != nullptr)
            curR->next = curA;
        else if(curB != nullptr)
            curR->next = curB;


        while(curR->next != nullptr){
            count++;
            curR = curR->next;
        }

        ListNode *cur3 = dummyHeadResult->next;
        if(count == 0){
            printf("0\n");
        } else{
            for(int i = 0; i < count; i++) {
                if(cur3->coef < 0){
                    printf("-");
                }
                if(cur3->coef > 0 && i > 0){
                    printf("+");
                }
                if(cur3->expon == 0){
                    printf("%ld", abs(cur3->coef));
                }
                else if(cur3->expon == 1 && (cur3->coef == 1 || cur3->coef == -1)){
                    printf("x");
                }
                else if(cur3->expon == 1 && cur3->coef != 1 && cur3->coef != -1){
                    printf("%ldx", abs(cur3->coef));
                }
                else if(cur3->expon != 0 && cur3->expon != 1 && (cur3->coef == 1 || cur3->coef == -1)){
                    printf("x^%ld", cur3->expon);
                }
                else{
                    printf("%ldx^%ld", abs(cur3->coef),cur3->expon);
                }
                cur3 = cur3->next;
            }
            printf("\n");
        }
    }
}
