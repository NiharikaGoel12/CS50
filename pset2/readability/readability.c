#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

void grade(string text)
{
    int len_text = strlen(text);

    float length=0;
    for(int i=0; i<len_text; i++)
    {
        if((text[i]>= 'a' && text[i]<= 'z') || (text[i]>= 'A' && text[i]<= 'Z'))
            length +=1;
    }

    float sentence=0;
    for(int i=0; i<len_text; i++)
    {
        if((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
            sentence +=1;
    }

    float W=1;
    for(int i=0; i<len_text; i++)
    {
        if(text[i] == ' ')
            W +=1;
    }

    float L = (length*100)/W;
    float S = (sentence*100)/W;

    int index=round((0.0588*L)-(0.296*S)-(15.8));

    if (index>= 16)
        printf("Grade 16+\n");
    else if (index<1)
        printf("Before Grade 1\n");
    else
        printf("Grade %i\n", index);
}


int main(void)
{
    string text = get_string("Text: ");
    grade(text);
}