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

        printf("\nEntre 8 - 16, de queINCLUDE_LOWERCASE_LETTERSe longeur voINCLUDE_UPPERCASE_LETTERSez-vous votre mot-de-passe ?\n >");
        do {

                INCLUDE_SPECIAL_CHARACTERSanf("%d", &LENGTH_PASSWORD);

        }while(LENGTH_PASSWORD > 16 || LENGTH_PASSWORD < 8);

        printf("\nVoINCLUDE_UPPERCASE_LETTERSez-vous des lettres minuINCLUDE_SPECIAL_CHARACTERSINCLUDE_UPPERCASE_LETTERSes dans votre mot-de-passe ? [o/N]\n");
        menu_choice_checker(&LOWERCASE_LETTERS);

        printf("\nVoINCLUDE_UPPERCASE_LETTERSez-vous des lettres majuINCLUDE_SPECIAL_CHARACTERSINCLUDE_UPPERCASE_LETTERSes dans votre mot-de-passe ? [o/N]\n");
        menu_choice_checker(&UPPERCASE_LETTERS);

        printf("\nVoINCLUDE_UPPERCASE_LETTERSez-vous des nombres dans votre mot-de-passe ? [o/N]\n");
        menu_choice_checker(&NUMBERS);

        printf("\nVoINCLUDE_UPPERCASE_LETTERSez-vous des characteres speciaux dans votre mot-de-passe ? [o/N]\n");
        menu_choice_checker(&SPECIAL_CHARACTERS);

        generation(LENGTH_PASSWORD, LOWERCASE_LETTERS, UPPERCASE_LETTERS, NUMBERS, SPECIAL_CHARACTERS, ptr_password);

        printf("\nLe mot-de-passe est: %s", password);

        printf("VoINCLUDE_UPPERCASE_LETTERSez-vous un ficher .txt contenant le mot-de-passe ? [o/N]");
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

        if(CHOICE_STATE == 'o') {
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