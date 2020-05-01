#include <stdio.h>
#include "list.h"
#include "numbers.h"

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
  display(list);
}

void perform_add_to_start(List_ptr list)
{
  int number;
  read_number("Enter the number you want to insert at the beginning", &number);
  Status status = add_to_start(list, number);
  display(list);
}

void perform_insert_at(List_ptr list)
{
  int number, position;
  read_number("Enter the number you want to insert", &number);
  read_number("Enter the position where you want to insert", &position);
  Status status = insert_at(list, number, position);
  if (status == Failure)
  {
    PRINT_STRING("The position you want to insert is invalid");
  }
  display(list);
}

void perform_add_unique(List_ptr list)
{
  int number;
  read_number("Enter the unique number you want to insert at the end", &number);
  Status status = add_unique(list, number);
  if (status == Failure)
  {
    PRINT_STRING("The number you entered is already present at the end of the list");
  }
  display(list);
}

void perform_user_choice(List_ptr list, char choice)
{
  printf("\n\n");
  switch (choice)
  {
  case 'a':
    perform_add_to_end(list);
    break;
  case 'b':
    perform_add_to_start(list);
    break;
  case 'c':
    perform_insert_at(list);
    break;
  case 'd':
    perform_add_unique(list);
    break;
  case 'm':
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
  PRINT_STRING("(m) exit");
  PRINT_STRING("Please enter the alphabet of the operation you would like to perform");
}

int main(void)
{
  List_ptr list = create_list();
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