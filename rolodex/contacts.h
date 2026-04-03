#ifndef CONTACTS_H
#define CONTACTS_H

#define MAX_NAME 50
#define MAX_PHONE 20

typedef struct {
    char name[MAX_NAME];
    char phone[MAX_PHONE];
} Contact;

int add_contact(const char *filename, Contact new_contact);
void list_contacts(const char *filename);
int delete_contact(const char *filename, const char *name_to_delete);

#endif
