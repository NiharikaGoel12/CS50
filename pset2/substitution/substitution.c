#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

void decode_text(string secret_code, string plaintext)
{
    int length_plaintext = strlen(plaintext);
    char cipher_code[length_plaintext+1];
    for (int i=0; i< length_plaintext; i++)
    {
        if ((plaintext[i]>='a' && plaintext[i]<= 'z') || (plaintext[i]>='A' && plaintext[i]<= 'Z'))
        {
            if(plaintext[i]>='a' && plaintext[i]<= 'z')
            {
               int converted_val = (int)plaintext[i] - (int)'a';
               cipher_code[i] = secret_code[converted_val];
            }
            else
            {
                int converted_val = (int)plaintext[i] - (int)'A';
                cipher_code[i] = secret_code[converted_val];
            }
        }
        else
            cipher_code[i] = plaintext[i];
    }
    char cipher_text[length_plaintext+1];
    for (int i=0; i< length_plaintext; i++)
    {
        if(isupper(plaintext[i]))
            cipher_text[i] = toupper(cipher_code[i]);
        else
            cipher_text[i] = tolower(cipher_code[i]);
    }
    cipher_text[length_plaintext] ='\0';
    printf("ciphertext: %s\n", cipher_text);
}

bool condition_check(string secret_code)
{
    int length_secret_code = strlen(secret_code);

    for (int i=0; i< length_secret_code; i++)
        {
            if ((secret_code[i]>= 'a' && secret_code[i]<= 'z') || (secret_code[i]>= 'A' && secret_code[i]<= 'Z'))
                continue;
            else
                return false;
        }

    for (int i=0; i< length_secret_code-1; i++)
        {
            for(int j=i+1; j< length_secret_code; j++)
                {
                    if(secret_code[i] == secret_code[j])
                        return false;
                }
        }
    return true;
}


int main(int argc, string argv[])
{
    string secret_code = argv[1];
    if((argc!=2) || (!condition_check(secret_code)))
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    int length_secret_code = strlen(secret_code);
    if(length_secret_code!=26)
        {
            printf("Key must contain 26 characters.");
            return 1;
        }

    string plaintext = get_string("plaintext: ");
    decode_text(secret_code, plaintext);
    return 0;
}