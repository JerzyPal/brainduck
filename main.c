#include <stdio.h>
#include <stdlib.h>
#define PROGMEM 1000
#define ROW 10
unsigned char mem[PROGMEM];
long int pointer = 0;
void interpret(char letter)
{


switch(letter)
    {
    case'<':
        if(pointer>0)
            pointer--;
        break;
    case'>':
        if(pointer<PROGMEM)
            pointer++;
        break;
    case'+':
        mem[pointer]++;
        break;
    case'-':
        mem[pointer]--;
        break;
    case'.':
        break;
    case',':
        break;
    case'[':
        break;
    case']':
        break;

    }


}


void printMem()
{
    for(int i=0;i<PROGMEM/ROW;i++)
        {
        for (int j=0;j<ROW;j++)
            {
            printf("%d ",mem[i*ROW+j]);
            }
        printf("\n");
        }



return;
}


//branduck
int main()
{
    for(int i=0;i<PROGMEM;i++)
        {
            mem[i]=0;
        }
//    printMem();

    char prog[]="++++++++>++++>>>>>>>>>>+++>++<--";
    for(int i=0;i<sizeof(prog)/sizeof(prog[0]);i++){
    interpret(prog[i]);

    }
    printMem();

printf("%d",PROGMEM);





    return 0;
}
