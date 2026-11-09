#include<stdio.h>
int main(){
char screen[5][10];
for(int y = 0; y < 5; y++){
    for(int x = 0; x < 10; x++){
        screen[y][x] = '.';
         if(x + y ==4){
         screen[y][x] = '*';
    }
}
} 

for (int y = 0; y < 5; y++)
{
    for (int x = 0; x < 10; x++)
    {
        printf("%c", screen[y][x]);
    }

    printf("\n");
}

    return 0;
}