#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List_ptr create_list(void)
{
  List_ptr list = malloc(sizeof(List));
  if (list != NULL)
  {
    list->head = NULL;
    list->last = NULL;
    list->count = 0;
  }
  return list;
}

Node_ptr create_node(int value)
{
  Node_ptr new_node = malloc(sizeof(Node));
  if (new_node != NULL)
  {
    new_node->value = value;
    new_node->next = NULL;
  }
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
  Node_ptr *ptr_to_set = &list->head;
  if (new_node == NULL)
  {
    return Memory_Not_Available;
  }
  if (list->head != NULL)
  {
    ptr_to_set = &list->last->next;
  }
  (*ptr_to_set) = new_node;
  list->last = new_node;
  list->count++;
  return Success;
}

Status add_to_start(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);
  if (new_node == NULL)
  {
    return Memory_Not_Available;
  }
  if (list->head == NULL)
  {
    list->last = new_node;
  }
  new_node->next = list->head;
  list->head = new_node;
  list->count++;
  return Success;
}

Node_ptr get_node_at(List_ptr list, int position)
{
  Node_ptr p_walk = list->head;
  for (int i = 0; i < position; i++)
  {
    p_walk = p_walk->next;
  }
  return p_walk;
}

Status insert_at(List_ptr list, int value, int position)
{
  if (position == 0)
  {
    return add_to_start(list, value);
  }
  if (position < 0 || position > list->count)
  {
    return Failure;
  }
  Node_ptr new_node = create_node(value);
  if (new_node == NULL)
  {
    return Memory_Not_Available;
  }
  if (position == list->count)
  {
    list->last = new_node;
  }
  Node_ptr before_node = get_node_at(list, position - 1);
  new_node->next = before_node->next;
  before_node->next = new_node;
  list->count++;
  return Success;
}

Status add_unique(List_ptr list, int value)
{
  int index = search_node(list, value);
  if (index != -1)
  {
    return Failure;
  }
  return add_to_end(list, value);
}

Status remove_from_start(List_ptr list)
{
  Node_ptr head = list->head;
  if (head == NULL)
  {
    return Failure;
  }
  list->head = head->next;
  list->count--;
  free(head);
  return Success;
}

Status remove_from_end(List_ptr list)
{
  if (list->count <= 1)
  {
    return remove_from_start(list);
  }
  Node_ptr before_node = get_node_at(list, list->count - 2);
  Node_ptr temp = before_node->next;
  before_node->next = NULL;
  list->last = before_node;
  list->count--;
  free(temp);
  return Success;
}

Status remove_at(List_ptr list, int position)
{
  if (position == 0)
  {
    return remove_from_start(list);
  }
  if (position < 0 || position >= list->count)
  {
    return Failure;
  }
  Node_ptr before_node = get_node_at(list, position - 1);
  if (position == list->count - 1)
  {
    list->last = before_node;
  }
  Node_ptr temp = before_node->next;
  before_node->next = temp->next;
  list->count--;
  free(temp);
  return Success;
}

Status clear_list(List_ptr list)
{
  Status status = Failure;
  while (list->count > 0)
  {
    status = remove_from_end(list);
  }
  return status;
}

void destroy_list(List_ptr list)
{
  clear_list(list);
  free(list);
}

int search_node(List_ptr list, int value)
{
  int index = -1;
  Node_ptr p_walk = list->head;
  for (int i = 0; i < list->count; i++)
  {
    if (p_walk->value == value)
    {
      index = i;
      break;
    }
    p_walk = p_walk->next;
  }
  return index;
}

Status remove_first_occurrence(List_ptr list, int value)
{
  int index = search_node(list, value);
  if (index == -1)
  {
    return Failure;
  }
  return remove_at(list, index);
}

Status remove_all_occurrences(List_ptr list, int value)
{
  Status status = remove_first_occurrence(list, value);
  if (status == Failure)
  {
    return Failure;
  }
  while (status == Success)
  {
    status = remove_first_occurrence(list, value);
  }
  return Success;
}
