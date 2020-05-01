#ifndef __NUMBERS_H
#define __NUMBERS_H

#define PRINT_STRING(string) printf("%s\n", string)
#define CLEAR_BUFFER() while ((getchar()) != '\n') {};

void display_menu();
void perform_user_choice(List_ptr list, char choice);
void read_number(char *message, int *value);
void perform_add_to_end(List_ptr list);

#endif
