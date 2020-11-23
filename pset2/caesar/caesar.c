#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

void next_letter(string letter, int user_code)
{
    int length_letter = strlen(letter);
    char cipher_code[length_letter+1];
    for (int i=0; i< length_letter; i++)
    {
        char l = (char)(letter[i]);
        if ((l >= 'a') && (l<= 'z'))
            {
                int value_char = (int)(l-'a');
                int cipher_key = ((value_char%26 + user_code%26) % 26) + (int)'a';
                // printf("cipherKey: %i\n", cipher_key);
                cipher_code[i]= (char)cipher_key;
            }
        else if ( (l >= 'A') && (l <= 'Z'))
            {
                int value_char = (int)(l-'A');
                int cipher_key = ((value_char%26 + user_code%26) % 26) + (int)'A';
                // printf("cipherKey: %i\n", cipher_key);
                cipher_code[i]= (char)cipher_key;

            }
        else {
            cipher_code[i]= l;
        }

    }
    cipher_code[length_letter] = '\0';
    printf("ciphertext: %s\n", cipher_code);

}
bool isValidInt(string arg)
{
    for (int i=0; i<strlen(arg); i++)
    {
        if(arg[i]<'0' || arg[i]>'9')
            return false;
    }
    return true;
}


int main(int argc, string argv[])
{
    if ((argc != 2) || (!isValidInt(argv[1])))
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    printf("%s\n", argv[0]);
    int user_code = atoi(argv[1]);
    string letter = get_string("plaintext: ");
    next_letter(letter, user_code);
    return 0;
}