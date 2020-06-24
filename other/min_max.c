#include "tree_int.h"

const ElemType* BstTreeMax(const Node *n)
{
    if (IsEmptyTree(n)) {
        return NULL;
    }

    while (!IsEmptyTree(RightTree(n))) {
        n = RightTree(n);
    }

    return &(n->value);
}

void TreeMinRec(const Node *n, const ElemType **min)
{
    if (IsEmptyTree(n)) {
        return;
    }

    if (n->value < **min) {
        *min = &n->value;
    }

    TreeMinRec(LeftTree(n), min);
    TreeMinRec(RightTree(n), min);
}

const ElemType* TreeMin(const Node* n)
{
    if (IsEmptyTree(n)) {
        return NULL;
    }

    const ElemType *min = GetRootValueTree(n);
    TreeMinRec(n, &min);
    return min;
}

int main(void) 
{
    ElemType v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    Node* n = CreateRootTree(&v[5], 
        CreateRootTree(
            &v[3],
            CreateRootTree(&v[2], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&v[8], CreateEmptyTree(), CreateEmptyTree())
            ),
        CreateRootTree(
            &v[10], 
            CreateEmptyTree(),
            CreateEmptyTree())
        );
    
    const ElemType *max = BstTreeMax(n);
    const ElemType *min = TreeMin(n);
    DeleteTree(n);
}

