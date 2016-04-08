# Play21
A short piece of code based on the game 21


/* based on the game 21 (a card game), where the aim is to get as close to
21 as possible when being given cards from a shuffled pack*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//This is a 'dice' function - it generates a random number between 1-12
int shuffle(void)
{
  srand(time(NULL));
  return(rand()%12)+1;
}

//This takes the input from the user
//It checks if the person would like to continue playing
int check()
{
  printf("\n>Would you like to roll?\n");
  char line[10], input[10];
  fgets(line, 10, stdin);
  sscanf(line, "%s", input);
  if (strcmp(input, "yes")==0){
    return 1;
  }
  if (strcmp(input, "no")==0){
    return 0;
  }
  if (strcmp(input, "yes")!=0 && strcmp(input, "no")!=0)
  {
    printf("Please type yes or no, you typed %s.\n", input);
    return check();
  }
  return 0;
}

/*This finds the difference between the player's number and 21. It then
makes this positive so that it is easier to compare to see who has won*/
int pos (int x){
  x = 21 - x;
  if (x<0){
    return -x;
  }
  else{
    return x;
  }
}

//This compares the result of the user with the result of the computer
void comp(int plyr, int AI)
{
  if (pos(plyr) == pos(AI)){
    printf("\nIt's a draw!! You have %d, and the other player has %d\n\n", plyr, AI);
  }
  if (pos(plyr)<pos(AI)){
        printf("\nCongratulations!! You have won!\nYou got %d and the other player got %d\n\n", plyr, AI);
  }
  if (pos(plyr)>pos(AI)){
    printf("\nSorry, you have lost. The other player won with a score of %d\n\n", AI);
  }
}


/*This uses the check function to see if the user wants to roll
It then calls the shuffle function to generate numbers for both the
user and the other player*/
int main()
{
  int sort1 = 0;
  int sort2 = 0;
  int p = 0;
  int a = 0;
  int b = check();
  while (a<16 || b==1){
      if(a<16){
        sort1 = shuffle();
        a = a + sort1;
      }
      printf("\nThe other player has %d\n", a);
      if (b==1){
        sort2 = shuffle();
        while (sort1 == sort2){
          sort2 = shuffle();
          }
        p = p + sort2;
      }
        printf("You now have %d\n\n", p);
        b = check();
      }
      if (a>=16 && b==0)
        comp(p, a);
  return 0;
}
