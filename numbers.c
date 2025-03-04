#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "numbers.h"

void display_status(Status status, char *error_message)
{
  char *message = "Invalid status.";
  char *success_message = "Done.";
  char *memory_unavailable_message = "Memory not available.\nTry again later.";
  if (status == Success)
  {
    message = success_message;
  }
  if (status == Failure)
  {
    message = error_message;
  }
  if (status == Memory_Not_Available)
  {
    message = memory_unavailable_message;
  }
  PRINT_STRING(message);
}

void read_number(char *message, int *value)
{
  PRINT_STRING(message);
  scanf("%d", value);
  CLEAR_BUFFER();
}

void perform_add_to_end(List_ptr list)
{
  int number;
  read_number("Enter the number you want to insert at the end", &number);
  Status status = add_to_end(list, number);
  display_status(status, "Failed to add the number to the end of the list.");
}

void perform_add_to_start(List_ptr list)
{
  int number;
  read_number("Enter the number you want to insert at the beginning", &number);
  Status status = add_to_start(list, number);
  display_status(status, "Failed to add the number to the start of the list.");
}

void perform_insert_at(List_ptr list)
{
  int number, position;
  read_number("Enter the number you want to insert", &number);
  read_number("Enter the position where you want to insert", &position);
  Status status = insert_at(list, number, position);
  display_status(status, "The position you want to insert is invalid.");
}

void perform_add_unique(List_ptr list)
{
  int number;
  read_number("Enter the unique number you want to insert at the end", &number);
  Status status = add_unique(list, number);
  display_status(status, "The number you entered is already present in the list.");
}

void perform_remove_from_start(List_ptr list)
{
  Status status = remove_from_start(list);
  display_status(status, "The list is empty.");
}

void perform_remove_from_end(List_ptr list)
{
  Status status = remove_from_end(list);
  display_status(status, "The list is empty.");
}

void perform_remove_at(List_ptr list)
{
  int position;
  read_number("Enter the position which you want to remove", &position);
  Status status = remove_at(list, position);
  display_status(status, "The position you want to remove is invalid.");
}

void perform_search(List_ptr list)
{
  int number;
  read_number("Enter the number you would like to search for?", &number);
  int result = search_node(list, number);
  Status status = Success;
  char *message = "Done.";
  if (result == -1)
  {
    status = Failure;
    message = "Failed.";
    printf("%d is not present in the list\n", number);
  }
  else
  {
    printf("%d is present in the list at position %d\n", number, result);
  }
  display_status(status, message);
}

void perform_remove_first_occurrence(List_ptr list)
{
  int number;
  read_number("Enter the number you would like to remove the first occurrence", &number);
  Status status = remove_first_occurrence(list, number);
  display_status(status, "The number you want to remove is not present in the list.");
}

void perform_remove_all_occurrences(List_ptr list)
{
  int number;
  read_number("Enter the number you would like to remove all the occurrences", &number);
  Status status = remove_all_occurrences(list, number);
  display_status(status, "The number you want to remove is not present in the list.");
}

void perform_clear_list(List_ptr list)
{
  Status status = clear_list(list);
  display_status(status, "The list you are trying to clear is empty");
}

void perform_user_choice(List_ptr list, char choice)
{
  system("clear");
  switch (choice)
  {
  case 'a':
    perform_add_to_end(list);
    display(list);
    break;
  case 'b':
    perform_add_to_start(list);
    display(list);
    break;
  case 'c':
    perform_insert_at(list);
    display(list);
    break;
  case 'd':
    perform_add_unique(list);
    display(list);
    break;
  case 'e':
    perform_remove_from_start(list);
    display(list);
    break;
  case 'f':
    perform_remove_from_end(list);
    display(list);
    break;
  case 'g':
    perform_remove_at(list);
    display(list);
    break;
  case 'h':
    perform_remove_first_occurrence(list);
    display(list);
    break;
  case 'i':
    perform_remove_all_occurrences(list);
    display(list);
    break;
  case 'j':
    perform_clear_list(list);
    display(list);
    break;
  case 'k':
    perform_search(list);
    display(list);
    break;
  case 'l':
    display(list);
    break;
  case 'm':
    destroy_list(list);
    break;
  default:
    PRINT_STRING("Invalid Choice!!!");
    break;
  }
  printf("\n\n");
}

void display_menu()
{
  PRINT_STRING("Main Menu");
  PRINT_STRING("---------");
  PRINT_STRING("(a) add a number to the end of the list");
  PRINT_STRING("(b) add a number to the start of the list");
  PRINT_STRING("(c) insert a number at a given position in the list");
  PRINT_STRING("(d) add a unique item on the list at the end");
  PRINT_STRING("(e) remove a number from the beginning of the list");
  PRINT_STRING("(f) remove a number from the end of the list");
  PRINT_STRING("(g) remove a number from a given position in the list");
  PRINT_STRING("(h) remove first occurrence of a number");
  PRINT_STRING("(i) remove all occurrences of a number");
  PRINT_STRING("(j) clear the whole list");
  PRINT_STRING("(k) check if a number exists in the list");
  PRINT_STRING("(l) display the list of numbers");
  PRINT_STRING("(m) exit");
  PRINT_STRING("Please enter the alphabet of the operation you would like to perform");
}

int main(void)
{
  List_ptr list = create_list();
  if (list == NULL)
  {
    display_status(Memory_Not_Available, "");
    return 0;
  }
  char choice;
  do
  {
    display_menu();
    choice = getchar();
    CLEAR_BUFFER();
    perform_user_choice(list, choice);
  } while (choice != 'm');

  return 0;
}