/*
   This code can be compiled and run ok.
     井字遊戲

   usage (how to run):
     ./hw5

   input file:
     none

   output file:
     none

   compile (how to compile):
     g++ -o hw5 hw5.cpp

   pseudocode:
     讓玩家選擇九宮格中要的位置，若O或X連成一線或者九格都填滿沒書沒贏，就停止遊戲

   coded by 江冠駒, ID: H24031354, email: kevin040208@gmail.com
   date: 2018.05.30
*/




#include<iostream>
#include <cstdio>


using namespace std;


int main(){
    //---begin--- PART 1: Declaration and print the board-----------
    int gamelist[9] = {-1,-1,-1,-1,-1,-1,-1,-1,-1},
    //一開始9格都是-1，若O選了的位置變0，若X選了的位置就變1，在遊戲中用來判斷輸贏
        testlist[8][3] = {{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{3,5,7}}, //贏的組合
        i, //for迴圈用
        o,x, //分別存O,X要填的位置
        check, //防呆用，check=0代表輸入的不是1~9的整數
        even; //判斷平手用，數gamelist中有幾個-1，若是0個代表平手
    char showlist[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '}; //一開始九宮格全是空白，在遊戲中用來顯示
    bool win;

    printf(" %d | %d | %d\n" , 1,2,3);
    printf("%s|%s|%s\n" , "---","---","---");
    printf(" %d | %d | %d\n" , 4,5,6);
    printf("%s|%s|%s\n" , "---","---","---");
    printf(" %d | %d | %d\n" , 7,8,9);
    cout << endl;
    printf(" %c | %c | %c\n" , showlist[0],showlist[1],showlist[2]);
    printf("%s|%s|%s\n" , "---","---","---");
    printf(" %c | %c | %c\n" , showlist[3],showlist[4],showlist[5]);
    printf("%s|%s|%s\n" , "---","---","---");
    printf(" %c | %c | %c\n" , showlist[6],showlist[7],showlist[8]);
    cout << endl;
    //---end--- PART 1: Declaration and print the board-------------

    //---begin--- PART 2: Game--------------------------------------
    win=1;
    //大while迴圈決定整個遊戲的結束，小while迴圈決定某一回O或X的結束
    //O先攻，X後攻
    while(win){
        while(1){ //O的回合開始
            check=0;
            even=0;
            cout << "(O) Select [1-9]: ";
            cin >> o;
            for(i=1;i<10;i++){
                if(o==i){check++;}
            }
            if(check==0){
                printf("Invalid input. Try again.");
                cout << endl;
                continue; //若輸入不合法就從新進O迴圈
            }
            else if(gamelist[o-1] != (-1)){
                printf("Cell %d has been filled. Try again." , o);
                cout << endl;
                continue; //若輸入的位置已有人填就從新進O迴圈
            }
            else{
                showlist[o-1] = 'O'; //O選的那一格變O
                gamelist[o-1] = 0; //O選的位置變0
                for(i=0;i<9;i++){
                    if(gamelist[i]==(-1)){even++;}
                }
                if(even==0){ //平手只會發生在9格全填滿還沒輸沒贏
                    cout << endl;
                    printf("Tie. Bye~");
                    cout << endl;
                    win = 0;
                }
                for(i=0;i<8;i++){
                    if(gamelist[testlist[i][0]-1]==0 && gamelist[testlist[i][1]-1]==0
                       && gamelist[testlist[i][2]-1]==0){
                        cout << endl;
                        printf("Player O win!");
                        cout << endl;
                        win = 0;
                    }
                }
                break;
            }//O的回合結束
        }
        cout << endl;
        printf(" %c | %c | %c\n" , showlist[0],showlist[1],showlist[2]);
        printf("%s|%s|%s\n" , "---","---","---");
        printf(" %c | %c | %c\n" , showlist[3],showlist[4],showlist[5]);
        printf("%s|%s|%s\n" , "---","---","---");
        printf(" %c | %c | %c\n" , showlist[6],showlist[7],showlist[8]);
        cout << endl;
        if(win == 0){break;} //若O贏了就跳出大迴圈，代表中途結束這回合，並且直接結束遊戲
        while(1){ //X的回合開始
            check=0;
            even=0;
            cout << "(X) Select [1-9]: ";
            cin >> x;
            for(i=1;i<10;i++){
                if(x==i){check++;}
            }
            if(check==0){
                printf("Invalid input. Try again.");
                cout << endl;
                continue; //若輸入不合法就從新進X迴圈
            }
            else if(gamelist[x-1] != (-1)){
                printf("Cell %d has been filled. Try again." , x);
                cout << endl;
                continue; //若輸入的位置已有人填就從新進X迴圈
            }
            else{
                showlist[x-1] = 'X';//X選的那一格變X
                gamelist[x-1] = 1; //X選的位置變1
                for(i=0;i<9;i++){
                    if(gamelist[i]==(-1)){even++;}
                }
                if(even==0){ //平手只會發生在9格全填滿還沒輸沒贏
                    cout << endl;
                    printf("Tie. Bye~");
                    cout << endl;
                    win = 0;
                }
                for(i=0;i<8;i++){
                    if(gamelist[testlist[i][0]-1]==1 && gamelist[testlist[i][1]-1]==1
                       && gamelist[testlist[i][2]-1]==1){
                        cout << endl;
                        printf("Player X win!");
                        cout << endl;
                        win = 0;
                    }
                }
                break;
            }//X的回合結束
        }
        cout << endl;
        printf(" %c | %c | %c\n" , showlist[0],showlist[1],showlist[2]);
        printf("%s|%s|%s\n" , "---","---","---");
        printf(" %c | %c | %c\n" , showlist[3],showlist[4],showlist[5]);
        printf("%s|%s|%s\n" , "---","---","---");
        printf(" %c | %c | %c\n" , showlist[6],showlist[7],showlist[8]);
        cout << endl;
    }
    //---end--- PART 2: Game----------------------------------------
    return 0;
}
