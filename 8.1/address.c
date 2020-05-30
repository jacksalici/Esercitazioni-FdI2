#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

struct Address {
	char name[40];
	char street[50];
	int number;
	char city[30];
	char province[3];
	char postal_code[6];
};
typedef struct Address ElemType;


struct Item
{
	ElemType value;
	struct Item *next;
};
typedef struct Item Item;



/*****************************************************************************/
/*                                 Element                                   */
/*****************************************************************************/


int ElemCompare(const ElemType *e1, const ElemType *e2) {
	return strcmp(e1->name, e2->name);
}

ElemType ElemCopy(const ElemType *e) {
	ElemType *t = malloc(sizeof(ElemType));
	t->name = e->name;
	t->street = e->street;
	t->number = e->number;
	t->city = e->city;
	t->province = e->province;
	t->postal_code = e->postal_code;
}
void ElemDelete(ElemType *e) {
	free(e);
}
int ReadElem(FILE *f, ElemType *e) {
	return fscanf(f, "%s %s %d %s %s %s", e->name, e->street, &e->number, e->city, e->province, e->postal_code);
}
int ReadStdinElem(ElemType *e) {
	return scanf("%s %s %d %s %s %s", e->name, e->street, &e->number, e->city, e->province, e->postal_code);
}
void WriteElem(const ElemType *e, FILE *f) {
	fprintf(f, "%s %s %d %s %s %s", e->name, e->street, &e->number, e->city, e->province, e->postal_code);
}
void WriteStdoutElem(const ElemType *e) {	printf("%s %s %d %s %s %s", e->name, e->street, &e->number, e->city, e->province, e->postal_code);}
/*****************************************************************************/
/*                          Item & Primitives                                */
/*****************************************************************************/

Item* CreateEmptyList(void)
{
	return NULL;
}

Item* InsertHeadList(const ElemType *e, Item* i)
{
	Item *t = malloc(sizeof(Item));
	t->value = ElemCopy(e);
	t->next = i;
	return t;
}

bool IsEmptyList(const Item *i)
{
	return i == NULL;
}

const ElemType* GetHeadValueList(const Item *i)
{
	if (IsEmptyList(i)) {
		printf("ERROR: Alla funzione 'GetHeadList()' e' stata passata una lista vuota (NULL pointer).\n");
		exit(1);
	}
	else {
		return &i->value;
	}
}

Item* GetTailList(const Item* i)
{
	if (IsEmptyList(i)) {
		printf("ERROR: Alla funzione 'GetTail()' e' stata passata una lista vuota (NULL pointer).\n");
		exit(2);
	}
	else {
		return i->next;
	}
}

Item* InsertBackList(Item* i, const ElemType *e)
{

	Item* n = InsertHeadList(e, CreateEmptyList());

	if (IsEmptyList(i)) {
		return n;
	}

	Item* tmp = i;
	while (!IsEmptyList(GetTailList(tmp))) {
		tmp = GetTailList(tmp);
	}

	tmp->next = n;
	return i;
}

void DeleteList(Item* i)
{
	while (!IsEmptyList(i)) {
		Item* tmp = i;
		i = i->next;
		ElemDelete(&tmp->value);
		free(tmp);
	}
}
/*****************************************************************************/
/*                                 Ex 1	                                     */
/*****************************************************************************/
const ElemType* Find(const Item* i, const char *name) {	ElemType *t;	while (1) {		t = GetHeadValueList(i);		if (t->name == name)			return t;		i = GetTailList(i);	}	return NULL;}/*****************************************************************************/
/*                                 Ex 2	                                     */
/*****************************************************************************/

Item* Delete(Item* i, const char *name) {
	ElemType *t;	Item *new = CreateEmptyList();	while (i->next!=NULL) {		t = GetHeadValueList(i);		if (t->name != name)			new = InsertHeadList(t, new);		i = GetTailList(i);	}	return new;
}

/*****************************************************************************/
/*                                 Ex 3	                                     */
/*****************************************************************************/

Item* Sort(Item* i) {	//working in progress}


/*****************************************************************************/
/*                                 Ex 4	                                     */
/*****************************************************************************/

Item* Filtra(Item* i, const char *city) {
	ElemType *t;	Item *new = CreateEmptyList();	while (i->next != NULL) {		t = GetHeadValueList(i);		if (t->city == city)			new = InsertHeadList(t, new);		i = GetTailList(i);	}	return new;
}



/*****************************************************************************/
/*                                 Ex 5	                                     */
/*****************************************************************************/

Item* Reverse(const Item* l) {
	ElemType *t;	Item *new = CreateEmptyList();	while (l->next != NULL) {		t = GetHeadValueList(l);		new = InsertBackList(t, new);		l = GetTailList(l);	}	return new;
}

/*****************************************************************************/
/*                                 Ex 7	                                     */
/*****************************************************************************/

Item* Append(const Item* l1, const Item* l2) {	ElemType *t;	Item *new = CreateEmptyList();	while (l1->next != NULL) {		t = GetHeadValueList(l1);		new = InsertHeadList(t, new);		l1 = GetTailList(l1);	}	while (l1->next != NULL) {		t = GetHeadValueList(l2);		new = InsertHeadList(t, new);		l2 = GetTailList(l2);	}	return new;}
