#include <stdio.h>
#include <cs50.h>

void checksum(long cc)
{
    int count =0;
    long dd = cc;
     while (dd != 0)
     {
        dd= dd/10;
        count++;
    }
    // printf("Total digit count:%i\n", count);

    int credit[count];
    int i=0;
    int counter =0;
    while(cc !=0)
    {
        int r = cc%10;
        credit[i] = r;
        i++;
        cc = cc/10;
    }
    // printf("One value of array:%i\n", credit[count-1]);
    for (int k = 0; k < count; k++)
    {
        if(k%2==0)
            counter+= credit[k];
        else
        {
            counter += (credit[k]*2)%10;
            counter += (credit[k]*2)/10;
        }
    }
    // printf("Value of counter:%i\n", counter);
    if(counter%10 ==0)
    {
        if (count==15 && credit[count-1]==3 && (credit[count-2]== 3 || credit[count-2]==7))
            printf("AMEX\n");
        else if (count==16 && credit[count-1]==5 && (credit[count-2]==1 || credit[count-2]==2 || credit[count-2]==3 || credit[count-2]==4 || credit[count-2]== 5))
            printf("MASTERCARD\n");
        else if ((count==13 || count==16) && credit[count-1] ==4)
            printf("VISA\n");
        else
            printf("INVALID\n");
    }
    else
    printf("INVALID\n");

}

int main(void)
{
    long cc = get_long("Number: ");

    checksum(cc);
}