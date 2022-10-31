#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <stdbool.h>
#define player1 'X'

#define player2 'O'


void printBoard(char table[])
{
    system("cls");
    printf("-------------\n| %c | %c | %c |\n| %c | %c | %c |\n| %c | %c | %c |\n-------------\n",table[0],table[1],table[2],table[3],table[4],table[5],table[6],table[7],table[8]);
}
bool winCheck(char table[])
{
    bool result=false;
    int possibilities[8][3]= {{1,2,3},{4,5,6}, {7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{3,5,7}};
    for(int i=0; i<=8; i++)
    {
        if((table[possibilities[i][0]-1]==table[possibilities[i][1]-1])&&(table[possibilities[i][1]-1]==table[possibilities[i][2]-1]))
        {
            result=true;
        }
    }

    return result;
}
int main()
{
    bool won=false;
    int key;
    printf("Enter to start");
    do
    {
        key=getch();
    }
    while (key!=13);
    system("cls");
    char game[9]= {'1','2','3','4','5','6','7','8','9'};
    int turn=0;
    int toPlay=1;

    printf("Started\n");
    printBoard(game);
    do
    {

if(turn>=9){
    break;
}
        int pcase;
        char played= toPlay==1?'X':'O';
        do
        {
            printf("Player%d turn n%d choose case:",toPlay,turn+1);
            scanf("%d",&pcase);
            printf("\n");
        }
        while(pcase<=0||pcase>9||game[pcase-1]=='X'||game[pcase-1]=='O');

        game[pcase-1]=played;
        toPlay=toPlay==1?2:1;
        printBoard(game);
        turn++;
        if(turn>=5)
        {
            won=winCheck(game);
        }

    }
    while (!won);
    int winner=toPlay==1?2:1;
    //system("cls");
    if(won){
      printf("Winner is player %d",winner);
    } else if(!won) {
    printf("Draw");
    }

    return 0;

}
