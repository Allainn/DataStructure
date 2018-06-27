typedef struct no No;
struct no{
    int id;
    No *prox;
};

No* mallocNo(int id);
void insertList(No *ptr, No *n);
void removeList(No *ptr, int id);
void printList(No *ptr);
void searchList(No* ptr, int id);