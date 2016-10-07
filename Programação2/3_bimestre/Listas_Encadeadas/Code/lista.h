struct list{
	int info;	// This variable can be any other type
	list *next;
}list;
void begin(struct list *root);
void push(int value, struct list *root);
int pop(int value,struct list *root);
void find(int value,struct list *root);
void destroy(struct list *root);
int *list(struct list *root);
