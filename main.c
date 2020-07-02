#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    unsigned int value;
    struct Node* next;
} Node;


void printLinkedList(const Node* head);
void pushBack(Node** head, int value);

Node* findFirstOdd(Node* head);
Node* findLastOdd(Node* head);
// Node* getLast(Node* head);
Node* getPrev(Node* head, Node* el);
void deleteLastOdd(Node* pd, Node* head);
void freeList(Node* head);

int main(void)
{
    system("chcp 1251");
    Node* head = NULL;
    Node* pdel;
    Node* pst = head;
    unsigned int temp = 0;
    printf("Введіть значення елементів списку. Щоб закінчити ввід, введіть будь-який символ!\n");
    while (scanf_s("%u", &temp) != 0)
    {
        pushBack(&head, temp);
    }
    printLinkedList(head);
    for (int i = 0; i < 3; i++)
        deleteLastOdd(findLastOdd(head), head);

    printLinkedList(head);
    freeList(head);
    system("pause");
    return 0;
}

void deleteLastOdd(Node* pd, Node* head)
{
    Node* pdel = pd;

    if (pdel == NULL) return;
    if (pdel == head)
    {
        if (head->next == NULL)
        {
            free(head);
            printf("Список порожній!!!");
            system("pause");
            exit(1);
        }
        head = head->next;
        free(pdel);
        *pdel = *head;
        return;
    }
    Node* prev = getPrev(head, pdel);
    while (prev->next != pdel)
        prev = prev->next;
    prev->next = pdel->next;
    free(pdel);
}

Node* findLastOdd(Node* head)
{
    Node* el = NULL;
    while (head != NULL)
    {
        if (head->value & 1 == 1)
            el = head;
        head = head->next;
    }
    return el;
}

Node* getPrev(Node* head, Node* el) {
    if (head == NULL || el == NULL || head->next == NULL) {
        return NULL;
    }
    while (head->next != el) {
        head = head->next;
    }
    return head;
}

Node* findFirstOdd(Node* head)
{
    while (head != NULL)
        if (head->value & 1 == 1)
            return head;
        else
            head = head->next;
    return NULL;
}

void pushBack(Node** head, int value)
{
    Node* tmp = (Node*)malloc(sizeof(Node));
    static Node* last;
    tmp->value = value;
    tmp->next = NULL;
    if (*head == NULL)
        last = tmp;
    if ((*head) == NULL)
        (*head) = tmp;
    else
    {
        last->next = tmp;
        last = tmp;
    }
}

// Node* getLast(Node* head) {
//     if (head == NULL) {
//         return NULL;
//     }
//     while (head->next) {
//         head = head->next;
//     }
//     return head;
// }

void printLinkedList(const Node* head) {
    while (head) {
        printf("%u ", head->value);
        head = head->next;
    }
    printf("\n");
}

void freeList(Node* head)
{
    Node* pel = head;
    while (pel != NULL) {
        head = head->next;
        free(pel);
        pel = head;
    }
}
