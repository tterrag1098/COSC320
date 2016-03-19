#include "BucketSorter.h"
#include "InsertionSorter.h"

BucketSorter::BucketSorter(int max) : max(max), Sorter("Bucket"){}

BucketSorter::~BucketSorter(){}

Node::Node(){}

Node::~Node(){}

void BucketSorter::sort(int *arr, int size)
{
    reset();
    int num = max / 10;
    Node *buckets[num];
    for (int i = 0; op(), i < num; i++)
    {
        buckets[i] = new Node();
    }
    for (int j = 0; op(), j < size; j++)
    {
        Node *n = buckets[arr[j] / 10];
        Node *temp = n->next;
        n->next = new Node(arr[j]);
        n->next->next = temp;
    }
    int idx = 0;
    for (int k = 0; op(), k < num; k++)
    {
        idx = buckets[k]->sort(this, arr, idx);
    }
}

int Node::sort(BucketSorter *parent, int *arr, int off)
{
    if (prev)
    {
        // Only sort from the root
        prev->sort(parent, arr, off);
    }

    Node *cur = next;
    int size = 0;
    while (cur) {
        size++;
        cur = cur->next;
    }

    cur = next;
    int temp[size];
    for (int i = 0; parent->op(), i < size; i++) {
        temp[i] = cur->value;
        cur = cur->next;
    }

    InsertionSorter sorter;
    sorter.sort(temp, size);
    for (int j = 0; parent->op(), j < size; j++) {
        arr[j + off] = temp[j];
    }
    return off + size;
}
