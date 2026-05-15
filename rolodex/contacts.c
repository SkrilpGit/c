#include <stdio.h>
#include <string.h>
#include "contacts.h"

int add_contact(const char *filename, Contact new_contact) {
    // TODO: Implement file append logic
    /* look for file with *filename, if no create it.
     * a Contact contains an name[char] and phone[char]
     * add the name[char]s to the file
     * add a separator "\"
     * add the phone[char]s and "\n"
     */
    FILE *fptr;
    printf("opening %s...\n", filename);

    // open or create a new file with the filename in append mode
    fptr = fopen(filename,"a");

    if (fptr == NULL){
        printf("Error opening file %s\n", filename);
        return 1;
    }

    //printf("name size = %lu\n",strcspn(new_contact.name,"\n"));
    // you can use strcspn() to look for a character that isn't in a string
    // to return the size of that string lmao
    // but we're not doing that because apparently appending is as simple as
    // fprintfing into the file pointer
    fprintf(fptr, "%s\\", new_contact.name);
    fprintf(fptr, "%s\n", new_contact.phone);
    fclose(fptr);
    return 0; 
}

void list_contacts(const char *filename) {
    // TODO: Implement file read and print logic
    FILE *fptr;
    printf("opening %s...\n", filename);

    // open or create a new file with the filename in append mode
    fptr = fopen(filename,"r");

    if (fptr == NULL){
        printf("Error opening file %s\n", filename);
    }

    int nlc = 0; //new-line-characters
    char buffer[100];
    while(fgets(buffer,100,fptr))
        printf("%s",buffer);
}

int delete_contact(const char *filename, const char *name_to_delete) {
    // TODO: Implement temporary file swap logic
    return 0;
}
