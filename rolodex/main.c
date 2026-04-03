#include <stdio.h>
#include <string.h>
#include "contacts.h"

int main() {
    const char *db_file = "my_contacts.txt";
    int choice;
    Contact c;

    do {
        printf("\n--- Contact Manager ---\n");
        printf("1. Add Contact\n2. List Contacts\n3. Exit\n");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1) break;
        getchar(); 

        if (choice == 1) {
            printf("Enter name: ");
            fgets(c.name, MAX_NAME, stdin);
            c.name[strcspn(c.name, "\n")] = 0;

            printf("Enter phone: ");
            fgets(c.phone, MAX_PHONE, stdin);
            c.phone[strcspn(c.phone, "\n")] = 0;

            add_contact(db_file, c);
        } else if (choice == 2) {
            list_contacts(db_file);
        }
    } while (choice != 3);

    return 0;
}
