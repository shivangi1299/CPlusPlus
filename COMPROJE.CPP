#include<iostream>
#include<conio.h>
#include<cstdio>
#include<iomanip>
#include<string.h>
#include<unistd.h>
#include<windows.h>
using namespace std;

struct word1
{
int l1;
char plyr1[15];
char guess1[15];
char lets1[30];
char g1;
}obj1;

struct word2
{
int l2;
char plyr2[15];
char guess2[15];
char lets2[30];
char g2;
}obj2;

int check1 (char let2[30], char f)
{
int r=0;
for(int k=0; let2[k]!='\0'; k++)
 {
  if(let2[k]==f)
  r++;
 }
return(r);
}

int check2 (char let1[30], char g)
{
int q=0;
for(int m=0; let1[m]!='\0'; m++)
 {
  if(let1[m]==g)
  q++;
 }
 return(q);
}

int main ()
{
//clrscr();
int n1=1, n2=1, c1=0, c2=0, r, q;
cout<<setw(45)<<"HANGMAN";
cout<<endl;
cout<<"Welcome to the game of Hangman!\n";
cout<<"\nINSTRUCTIONS-\n";
cout<<"This a double player game. Player 1 and Player 2 have to enter their words. Each player has to guess their opponent's word. Both players have 10 chances each.  All the letters of the word will first appear as '-'. The guessing should be done  by entering one letter at a time. If the letter is in the word, it will replace the '-' and appear in the correct position, and if not, the no. of chances will  reduce by 1. Both the players will have to  guess simultaneously and the one to guess first will be declared the winner.\n";
cout<<"\n**NOTE** THE GAME MUST BE PLAYED ONLY USING CAPITAL LETTERS\n         TO BE FAIR, MAKE SURE THAT BOTH PLAYERS ENTER WORDS WITH SAME NO. OF LETTERS";
cout<<setw(40)<<"\nALL THE BEST!\n";
cout<<"\nSo are you ready?\n";
cout<<"Let the game begin!\n";
cout<<"\nPlayer 1 enter your word (make sure Player 2 isn't looking)- ";
gets(obj1.plyr1);
obj1.l1=strlen(obj1.plyr1);
system("cls");
int i,j,a1,a2,x,y;
for( i=0; i<obj1.l1; i++)
{
obj1.guess1[i]='-';
}
obj1.guess1[i]='\0';
cout<<"Player 2 enter your word (make sure Player 1 isn't looking)- ";
gets(obj2.plyr2);
obj2.l2=strlen(obj2.plyr2);
system("cls");
for(j=0; j<obj2.l2; j++)
{
obj2.guess2[j]='-';
}
obj2.guess2[j]='\0';
cout<<"\nWe're good to go!\n";
cout<<"\nPlayer 1- ";
puts(obj2.guess2);
cout<<"\nPlayer 2- ";
puts(obj1.guess1);
cout<<"\nBoth players have 10 chances remaining\nStart guessing letter by letter!\n";
for( a1=10, a2=10, x=0, y=0; n1!=0 && n2!=0; )
{
 if(a1>0)
 {
 label1:
 cout<<"\nPlayer 1: ";
 cin>>obj2.g2;
 obj2.lets2[x]=obj2.g2;
 x++;
 obj2.lets2[x]='\0';
 r= check1(obj2.lets2, obj2.g2);
 if(r>1)
 {
  cout<<"\nYou have already used this letter. Please enter another.\n";
  goto label1;
 }
 for(i=0; i<obj2.l2; i++)
 {
  if(obj2.g2==obj2.plyr2[i])
  {
   obj2.guess2[i]=obj2.g2;
   c1++;
  }
 }
 }
 if(a2>0)
 {
 label2:
 cout<<"Player 2: ";
 cin>>obj1.g1;
 obj1.lets1[y]=obj1.g1;
 y++;
 obj1.lets1[y]='\0';
 q= check2(obj1.lets1, obj1.g1);
 if(q>1)
 {
 cout<<"\nYou have already used this letter. Please enter another.\n";
 goto label2;
 }
 for(j=0; j<obj1.l1; j++)
 {
  if(obj1.g1==obj1.plyr1[j])
  {
   obj1.guess1[j]=obj1.g1;
   c2++;
  }
 }
 }
 cout<<"\nPlayer 1: ";
 puts(obj2.guess2);
 if(c1==0)
 a1--;
 cout<<"         "<<a1<<" chance(s) remaining";
 c1=0;
 cout<<"\nPlayer 2: ";
 puts(obj1.guess1);
 if(c2==0)
 a2--;
 cout<<"         "<<a2<<" chance(s) remaining";
 c2=0;
 cout<<endl<<endl;
 n1=strcmp(obj2.guess2, obj2.plyr2);
 n2=strcmp(obj1.guess1, obj1.plyr1);
 if(a1==0)
 cout<<"\nPlayer 1 is out of chances.\n";
 if(a2==0)
 cout<<"\nPlayer 2 is out of chances.\n";
 if(a1<1 && a2<1)
 {
 cout<<"Sorry! Better luck next time to both the players!\n";
 break;
 }
}

if(n1==0 || n2==0)
{
 if(n1==n2)
 {
  cout<<"\nCongratulations to both the players! You completed in "<<a1<<" chance(s) remaining.";
 }
 else
 {
  if(n1==0)
  cout<<"\nCongratulations to Player 1! You completed in "<<a1<<" chance(s) remaining.";
  else
  cout<<"\nCongratulations to Player 2! You completed in "<<a2<<" chance(s) remaining.";
 }
}
getch();
}
