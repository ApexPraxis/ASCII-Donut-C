#include<stdio.h>
int main(){
char screen[8][15];
for(int y = 0; y < 8; y++){
    for(int x = 0; x < 15; x++){
        screen[y][x] = '.';
         if( y == 0 || y == 7 || x == 0 || x == 14){
         screen[y][x] = '*';
    }
}
} 

for (int y = 0; y < 8; y++)
{
    for (int x = 0; x < 15; x++)
    {
        printf("%c", screen[y][x]);
    }

    printf("\n");
}

    return 0;
}
