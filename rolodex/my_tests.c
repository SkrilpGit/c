#include <string.h>
#include <stdlib.h>
#include "contacts.h"

int main() {
    const char *db_file = "my_contacts.txt";

    Contact contact;
    for (int i = 0; i < 100; i++){

       for (int k = 0; k < 30; k++){
            char c = 65 + (rand() % 52);
            contact.name[k] = c;
       }
       for (int j = 0; j < 20; j++){
            char n = 48 + (rand() % 10);
            contact.phone[j] = n;
       }
       add_contact(db_file, contact);
    }
    list_contacts(db_file);
}
