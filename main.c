#include <stdio.h>
#include <stdlib.h>



#define PROGMEM 1000
#define ROW 10
#define LOOPMAX 256
#define ENDBRACKET 1
#define STARTBRACKET 0



unsigned char mem[PROGMEM]={0};
long int pointer = 0;
int loop[LOOPMAX][3] = {0};
int loopcounter = -1;
void interpret(char letter, int *exepoint)
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
        putchar(mem[pointer]);
        break;
    case',':
        mem[pointer] = getchar();
        break;
    case'[':
        if(mem[pointer] !=0 )
        {
        loopcounter++;
        loop[loopcounter] = *exepoint;
        }
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



void loopprocessing(int *progpoint, char bracket)
{

    if (bracket == STARTBRACKET)
    {
    loop[loopcounter][1]=1;

    }
    else //ENDBRACKET
    {
    loop[loopcounter][1]=1;

    }

}




//branduck
int main()
{


    char prog[]="++++++++>++++>>>>>>>>>>+++>++<--";


    /*

     [ 0 *1
     [ 1 *1
     ] 1 *2
     [ 2 *1
     ] 2 *2
     ] 0 *2
     [ 3 *1


    */

    for(int i=0;i<sizeof(prog)/sizeof(prog[0]);i++){
    if(prog[i]=='[')
    loopprocessing(&i,STARTBRACKET);
    else if(prog[i]==']')
    loopprocessing(&i,ENDBRACKET);
    }

    loopcounter = -1;

    for(int i=0;i<sizeof(prog)/sizeof(prog[0]);i++){
    interpret(prog[i], &i);

    }
    printMem();

//printf("%d",PROGMEM);





    return 0;
}
