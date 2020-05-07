#include <stdio.h>
#include "../list.h"
#include "test.h"

int assert(int actual, int expected)
{
  return actual == expected;
}

void display_pass_or_fail(int status)
{
  status ? printf(PASS) : printf(FAIL);
}

void test_clear_list(List_ptr list)
{
  add_to_end(list, 1);

  PRINT_STRING("\nclear_list");

  int status = assert(clear_list(list), Success);
  status = status && assert(list->count, 0);
  display_pass_or_fail(status);
  PRINT_STRING("should clear the list and set to zero");

  status = assert(clear_list(list), Failure);
  status = status && assert(list->count, 0);
  display_pass_or_fail(status);
  PRINT_STRING("should not clear the list if it is an empty list");
}

void test_search_node(List_ptr list)
{
  add_to_end(list, 1);

  PRINT_STRING("\nsearch_node");

  int status = assert(search_node(list, 1), 0);
  display_pass_or_fail(status);
  PRINT_STRING("should give the position if the item is present in the list");

  status = assert(search_node(list, 2), -1);
  display_pass_or_fail(status);
  PRINT_STRING("should give -1 if the item is not present in the list");

  clear_list(list);
}

int main(void)
{
  List_ptr list = create_list();
  if (list == NULL)
  {
    PRINT_STRING("Memory_Not_Available");
    return 0;
  }

  test_clear_list(list);
  test_search_node(list);

  return 0;
}