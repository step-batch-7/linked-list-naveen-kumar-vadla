#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List_ptr create_list(void)
{
  List_ptr list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
}

Node_ptr create_node(int value)
{
  Node_ptr new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

void display(List_ptr list)
{
  printf("List => ");
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    printf("%d ", p_walk->value);
    p_walk = p_walk->next;
  }
  printf("\n");
}

Status add_to_end(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);
  if (list->head == NULL)
  {
    list->head = new_node;
  }
  else
  {
    list->last->next = new_node;
  }
  list->last = new_node;
  list->count++;
  return Success;
}

Status add_to_start(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);
  if (list->head == NULL)
  {
    return add_to_end(list, value);
  }
  new_node->next = list->head;
  list->head = new_node;
  list->count++;
  return Success;
}

Node_ptr get_node_at(List_ptr list, int position)
{
  if (position < 1 || position > list->count)
  {
    return NULL;
  }
  Node_ptr p_walk = list->head;
  int count = 1;
  while (count < position)
  {
    p_walk = p_walk->next;
    count++;
  }
  return p_walk;
}

Status insert_at(List_ptr list, int value, int position)
{
  if (position == 1)
  {
    return add_to_start(list, value);
  }
  if (position == list->count + 1)
  {
    return add_to_end(list, value);
  }
  if (position > list->count + 1)
  {
    return Failure;
  }
  Node_ptr new_node = create_node(value);
  Node_ptr before_node = get_node_at(list, position - 1);
  new_node->next = before_node->next;
  before_node->next = new_node;
  list->count++;
  return Success;
}
