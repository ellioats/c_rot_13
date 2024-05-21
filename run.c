// Elliot Currie
// Tuesday, May 21. 2024

#include "rot13.h"

void menu();
void devInfo();
void refine(char * input, char ** output);


int main() {

    // for entering phrase
    char str_input[15];
    char * refined_arr;

    // for menu navigation
    char option[2];
    char * overflow = NULL;
    int choice;

    // returned arr
    char * ret_arr;

    puts("welcome to the ROT-13 Encryption Tool...");
    puts("please refer to the following menu for your next steps...");

    menu();

    while(choice != 3) {

        fgets(option, 2, stdin);
        choice = (int) strtod(option, &overflow);
        getchar();
        switch(choice) {
            case 1: 
            
                printf("Please enter your phrase (no more than 15 characters, please): ");
                fgets(str_input, 15, stdin);

                // printf("DEBUG: you entered: %s\n", str_input);

                refine(&str_input[0], &refined_arr);
                puts("DEBUG: refine method finished");

                rotate(&refined_arr[0], &ret_arr);

                
                break;
            case 2:
                devInfo();
                break;

        }
        puts("");
        if (!(choice == 3))
            menu();
    }
    // program exits
    return 0;
}

void refine(char * input, char ** output) {
    *output = (char *) (malloc(sizeof((strlen(input) + 1))));
    // printf("DEBUG: strlen of input = %i\n", strlen(input));

    int outputCounter = 0;

    for (int x = 0; x < strlen(input); x++) {
        // printf("DEBUG: ITR COUNT: %i\n", x);
        // printf("output counter: %i\n", outputCounter);

        if (input[x] == '\n' || input[x] == '\0' || input[x] == ' ') {
            // printf("DEBUG: escape sequence found, continuing...\n");
            continue;
        }
        
        (*output)[outputCounter] = input[x];
        // printf("value of %c appended to output arr...\n", input[x]);
        outputCounter++;
    }
}

void menu() {
    puts("1 - Enter a new phrase");
    puts("2 - Developer Info");
    puts("3 - Exit");
}

void devInfo() {
    puts("\nDeveloped by Elliot Currie");
    puts("Date of Development: Tuesday, May 21. 2024");
    puts("Contact: emwcurrie@gmail.com");
}