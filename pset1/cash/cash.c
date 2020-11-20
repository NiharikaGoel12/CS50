#include <stdio.h>
#include <cs50.h>
#include <math.h>

int total_coins(float change)
{
    int cents = round(change * 100);
    int coin_count = 0;
    int balance = cents;

    if (balance >= 25)
    {
        coin_count += (balance/25);
        balance = (balance%25);
        
    }

    if (balance >= 10)
    {
        coin_count += (balance/10);
        balance = (balance%10);
    }
    if (balance >= 5)
    {
        coin_count += (balance/5);
        balance= (balance%5);
    }

    if(balance >= 1)
    {
        coin_count += (balance/1);
        balance = (balance%1);
        
    }
    
    return coin_count;
}


int main(void)
{
    float change;
    do
    {
        change = get_float("Change owned: ");
    }
    while (change <0);
    printf("%i\n",total_coins(change));
    return 0;
}

