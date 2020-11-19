#include<stdio.h>
#include<cs50.h>
#include<string.h>

void mario_left(int height, int row_num)
{
    for (int i=0; i< (height-row_num); i++)  printf(" ");
    for (int j = 0; j < row_num; j++) printf("#");
}

void mario_right(int height, int row_num)
{
    for (int j = 0; j < row_num; j++) printf("#");
    for (int i=0; i < (height-row_num); i++)printf(" ");
}


int main(void)
{
    
    int height;
    do
    {
      height = get_int("Height: \n");  
    } while (height >8 || height <1);
    
    for (int i=1; i<=height; i++)
        {

            mario_left(height, i);
            printf("  ");

            mario_right(height, i);
            printf("\n");
        }
}