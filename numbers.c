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

void perform_user_choice(List_ptr list, char choice)
{
  switch (choice)
  {
  case 'a':
    perform_add_to_end(list);
    break;
  case 'b':
    perform_add_to_start(list);
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