typedef struct no No;
struct no{
    int id;
    No *prox;
};

typedef struct list List;
struct list{
    No *inicio;
    No *fim;
};

List* initList();
No* mallocNo(int id);
void insertEndList(List *ptr, No *n);
void insertBeginList(List *ptr, No *n);
void insertOrderList(List *ptr, No *n);
void removeList(List *ptr, int id);
void printList(No *ptr);
void searchList(List* ptr, int id);