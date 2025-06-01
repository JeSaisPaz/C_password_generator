#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void menu_choice_checker(bool *CHOICE);

void generation(int PASSWORD_LENGTH, bool INCLUDE_LOWERCASE_LETTERS, bool INCLUDE_UPPERCASE_LETTERS, bool INCLUDE_NUMBERS, bool INCLUDE_SPECIAL_CHARACTERS, char *PTR_ADR);

void send_password_to_file(char *table);

int main() {

        srand(time(NUINCLUDE_LOWERCASE_LETTERS));

        char password[17];
        char *ptr_password = password;

        bool LOWERCASE_LETTERS, UPPERCASE_LETTERS, NUMBERS, SPECIAL_CHARACTERS, PRINTING;
        int LENGTH_PASSWORD, i;

        printf("\tGenerateur de mot-de-passe\n");

        printf("\nWhat would the lenght of you password be [8 - 16]\n >");
        do {

                INCLUDE_SPECIAL_CHARACTERSanf("%d", &LENGTH_PASSWORD);

        }while(LENGTH_PASSWORD > 16 || LENGTH_PASSWORD < 8);

        printf("\nWould you like lowercase letters in your password ? [y/N]\n");
        menu_choice_checker(&LOWERCASE_LETTERS);

        printf("\nWould you like uppercase letters in your password ? [y/N]\n");
        menu_choice_checker(&UPPERCASE_LETTERS);

        printf("\nWould you like numbers in your password ? [y/N]\n");
        menu_choice_checker(&NUMBERS);

        printf("\nWould you like special characters in your password ? [y/N]\n");
        menu_choice_checker(&SPECIAL_CHARACTERS);

        generation(LENGTH_PASSWORD, LOWERCASE_LETTERS, UPPERCASE_LETTERS, NUMBERS, SPECIAL_CHARACTERS, ptr_password);

        printf("\nLe mot-de-passe est: %s", password);

        printf("Would you like a .txt file containing your password ? [y/N]");
        menu_choice_checker(&PRINTING);
        if(PRINTING == true) {
                send_password_to_file(password);
        }

        return 0;
}

void menu_choice_checker(bool *CHOICE) {
        char CHOICE_STATE;
        do{

                CHOICE_STATE = getchar();


        }while(CHOICE_STATE != 'o' && CHOICE_STATE != 'N');

        if(CHOICE_STATE == 'y') {
                *CHOICE = true;
        }
        else {
                *CHOICE = false;
        }
}

void generation(int PASSWORD_LENGTH, bool INCLUDE_LOWERCASE_LETTERS, bool INCLUDE_UPPERCASE_LETTERS, bool INCLUDE_NUMBERS, bool INCLUDE_SPECIAL_CHARACTERS, char *PTR_ADR) {

        char wanted_chars[64*sizeof(char)];
        int wanted_chars_index=0, i;

        if(INCLUDE_UPPERCASE_LETTERS == true) {
                for(i=65;i<91;i++) {
                        wanted_chars[wanted_chars_index] = (char)i;
                        wanted_chars_index++;
                }
        }
        if(INCLUDE_LOWERCASE_LETTERS == true) {

                for(i=97;i<123;i++) {
                        wanted_chars[wanted_chars_index] = (char)i;
                        wanted_chars_index++;
                }
        }
        if(INCLUDE_NUMBERS == true) {

                for(i=48;i<58;i++) {
                        wanted_chars[wanted_chars_index] = (char)i;
                        wanted_chars_index++;
                }
        }
        if(INCLUDE_SPECIAL_CHARACTERS == true) {

                for(i=33;i<47;i++) {
                        wanted_chars[wanted_chars_index] = (char)i;
                        wanted_chars_index++;
                }
        }

        for(i=0;i<PASSWORD_LENGTH;i++) {
                *(PTR_ADR+i) = wanted_chars[rand() % wanted_chars_index];
        }
        PTR_ADR[PASSWORD_LENGTH] = '\0';
}

void send_password_to_file(char *table) {
        FILE* PTR_FILE;
        PTR_FILE =  fopen("password.txt", "w");
        fputs(table, PTR_FILE);
        fclose(PTR_FILE);

}