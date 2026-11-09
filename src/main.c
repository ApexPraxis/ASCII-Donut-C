#include<stdio.h>
int main(){
char screen[5][10];
for(int y = 0; y < 5; y++){
    for(int x = 0; x < 10; x++){
        screen[y][x] = '.';
    }
}

    return 0;
}