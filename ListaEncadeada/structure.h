typedef struct no No;
struct no{
    int id;
    No *prox;
};

typedef struct list List;
struct list{
    No *inicio;
};

No* mallocNo(int id);
void insertList(List *ptr, No *n);
void removeList(List *ptr, int id);
void printList(List *ptr);
void searchList(List* ptr, int id);