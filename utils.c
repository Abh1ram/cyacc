#include "utils.h"

struct expr_type 
create_const_expr(char *const_str) {
  struct expr_type e;
  e.type = get_const_type(const_str);
  e.ptr = CONST_PTR;
  e.val.const_str = const_str;

  return e;
}


void 
copy_name (char **buf, char *name) {
  if (!name)
    return;
  *buf = malloc((strlen(name)  + 1)* sizeof(char));
  strcpy(*buf, name);
  return;
}

void 
list_join (struct list **l, struct list **m) {
	if (!*l) {
		*l = *m;
		return;
	}
	struct list *node = *l;
	while (node->next) 
		node = node->next;

	node->next = *m;
	return;
}

void 
list_append_elem (struct list **l, struct list *elem) {
	if (!l)
		return;

	if (!*l) {
		*l = elem;
		return;
	}
	struct list *node = *l;
	while (node->next)
		node = node->next;
	node->next = elem;
	return;
}

void 
list_prepend_elem (struct list **l, struct list *elem) {
	if (!l)
		return;
	elem->next = *l;
	*l = elem;
	return;
}

struct list *
list_create_elem (void *data) {
	struct list *newnode = malloc(sizeof(struct list));
	newnode->data = data;
	newnode->next = NULL;

	return newnode;
}

void *
list_pop_front (struct list **l) {
	if (!l || !*l)
		return NULL;
	struct list *elem = *l;
	*l = elem->next;
	void *data = elem->data;
	free(elem);
	return data;
}