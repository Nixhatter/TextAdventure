#include <stdio.h>
#include <stdlib.h>


int health = 100;
int fire = 0;
int cellphone = 0;
int finished = 0;

void runGame();
void stayPut();
void buildFire();
void fixCellphone();
void climbTree();
void chooseNewLocation();

char c;

char* inventory(int);

void flush(){
	fflush(stdout);
	fflush(stdin);
}

int main() {
	printf("HELLO\n");
	printf("PLEASE HELP ME\n");
	printf("I HATE C\n\n");
	
	int item1=0;
	int item2=0;

	printf("Welcome to the world\n");
	area1:
	flush();
	printf("(n)do nothing, (a)go to area 2");
	printf("\n");
	scanf("%c", &c);
	switch(c){
		case 'a' : printf("going to area 2\n");
				   printf("Grabbed item 1\n"); 
				   item1=1;
				   goto area2;
		case 'n' : printf("doing nothing\n");
				   printf("really...\n"); break;
		default  : goto area1;
	}
	
	area2:
	flush();
	printf("(n)do nothing");
	if(item1) printf(", (a)go to final area");
	printf("\n");
	scanf("%c", &c);
	switch(c){
		case 'a' : printf("going to final area, grabbed item2\n");
				   item2=1; goto final;
		case 'n' : printf("do nothing\n");
		default  : goto area2;
	}
	
	final:
	flush();
	printf("(e) end this adventure (n) do nothing");
	printf("\n");
	scanf("%c", &c);
	switch(c){
		case 'n' : printf("\n");
				   printf("doing nothing again\n"); goto final;
		case 'e' : printf("ENDING!\n");
				   printf("\n"); break;
		default  : goto final;
	}
	
	if(item1 && item2){
		printf("Congratulations!");
		return end();
	} else {
		printf("You failed to get the items");
		if(!item1 && !item2) printf("You didnt get either");
		else if(!item1) printf("you forgot item1");
		else printf("you forgot item2");
		return end();
	}
}

char* inventory(int item){
	switch(item){
		case 0 : return "you have nothing\n";
		case 1 : return "you have item 1\n";
		default : return "default\n";
	}
}

int end(){
	flush();
	scanf("%c",&c);
	return 0;
}


int getUserInput (char* message, int low, int high) {
  int userInput;
  int inputOK = 0;
  int result;

  while (! inputOK) {
    printf("%s",message);
    printf("Please enter the number of the option you would like: ");
    result = scanf("%d", &userInput);
    if (result == 1) {
      if (userInput >= low && userInput <= high)
        inputOK = 1;
      else
        printf("Input is outside legal bounds.\n");
    }
    else {
      printf("Must enter an integer. Exiting program.\n");
      exit(1);
    }
  }
  return userInput;
}

/*
int main() {
  printf("You decide to stay where you are for now.\n");
  runGame();
  return 0;
}
*/

void runGame() {
  stayPut();
}

void stayPut() {
  int choice = getUserInput("What will you do next?\n\t1. Look around for materials to build a\
  	fire from\n\t2. Try to call for help on your cellphone\n\t3. Climb a tree to get a good look around.\n", 1, 3);
  if (choice == 1)
    if (fire != 1)
      buildFire();
    else {
      printf("\nYou remember that you have already tried this. You choose another option.\n");
      stayPut();
  }
  else if (choice == 2)
    fixCellphone();
  else if (choice == 3)
    climbTree();
}


void buildFire() {
  printf("\n\nYou look around and find some driftwood, sticks, dry leaves, flint and some old magazines.\n");
  int choice = getUserInput("\nWhat will you build your fire out of?\n\t\
  	1.Dry leaves and sticks\n\t2.Driftwood and magazines\n", 1, 2);
  if (choice == 1) {
    printf("\n\nYou have managed to get a fire started with the flint, sticks and dry leaves.\
    	You warm yourself up around the fire and pack the extra materials you gathered in your backpack so that you can make a fire again if you need to. Achievement unlocked: Fire building\n");
    fire = 1;
    stayPut();
  }
  else if (choice == 2) {
    printf("\n\n\tYou use the flint and are able to start a fire! \
    	You watch as the colours of the magazine cover begin to melt and the fire gives off a dark smoke.\
    	You lean in to warm yourself closer to the fire, and begin to feel dizzy. Little did you know, \
    	but the salt from the seawater in the driftwood and the paints and chemicals used in the ink of \
    	the magazine are giving off a toxic smoke as they burn. Your last thoughts are of regret that you \
    	didn't finish reading that book on how to survive in the woods that you got last Christmas. \
    	Everything fades to black... \n\t\t\tGAME OVER\n");
  finished = 1;
  }
}


void fixCellphone() {
  printf("\n\nYou open up your cellphone and see that it is completely out of battery. \
  You vaguely remember reading an article on how to build your own battery powered charger. \
  It seemed difficult, and you are without a soldering iron, but you think it might be worth a shot. \
  You search around the area and miraculously find some copper wires on the ground. \
  You dig out some batteries from the bottom of your backpack and try to remember the steps to build the charger.\
  You manage to MacGyver a battery that you think will work, now you just have to decide how to connect the wires\
  to your phone's battery. ");
  int choice = getUserInput("\nWhat will you do? \n\t\
  	1. Take the battery out of your phone and try to attach the wires to it\n\t2.\
  	Leave the battery in your phone and root around through the power socket with the wires\n", 1, 2);
  if (choice == 1) {
    cellphone = 1;
    printf("\n\nYou are able to get a charge on your cellphone! \
    	Achievement unlocked: Charged cellphone\nUnfortunately, there is no service where you are.\
    	You need to move to a new location in order to get cell service and call for help.\n");
    chooseNewLocation();
  }

  else if (choice == 2) {
    printf("\n\nYou eagerly push the power button on your phone and wait to see what happens. \
    	Nothing comes up on the screen but you feel the phone getting warm in your hands. You think that this must be a good sign, and wait as the phone gets warmer and warmer. Suddenly, you realize that you must have connected the wrong wires to the wrong terminals and that the battery must be short-circuiting! Unfortunately, you are not able to disconnect the wires in time and the phone blows up in your hands. A sharp piece of metal flies from the phone and into your temple, and you feel the blood starting to trickle down your face as everything fades to black...\n\t\t\tGAME OVER\n");
  }
}


void chooseNewLocation() {
  // Choose between climbing a tree or going back to the original 5 options
  int choice = getUserInput("\nWhat will you choose?\n\t1. Climb the tallest tree you see near you\n\t\
  	2. Choose one of the original 5 choices\n", 1, 2);
  if (choice == 1)
    climbTree();
  else if (choice == 2)
    //startGame();
    printf("\nThis is where you would return to the original 5 choices!\n");
}

void climbTree() {
  printf("\n\nYou decide to climb a tall tree.You see a beach, a cliff, a cabin and SOMETHING FROM ALICE IN WONDERLAND.\n");
  char choices[] = "What will you do?\n\t1. Go to the beach\n\t2. Go to the cliff\n\t\
  	3. Go to the cabin\n\t4. Go to the THING FROM ALICE IN WONDERLAND\n";
  char specialChoice[] = "\t5. Try your phone and see if there is cell service up here\n";
  printf("%s", choices);
  int choice;
  if (cellphone == 1) {
    printf("%s", specialChoice);
    choice = getUserInput("", 1, 5);
  }
  else
    choice = getUserInput("", 1, 4);

  if (choice == 1)
    printf("Branch to beach path\n");
    //beach();
  else if (choice == 2)
    printf("Branch to cliff path\n");
    //cliff();
  else if (choice == 3)
    printf("Branch to cabin path\n");
    //cabin();
  else if (choice == 4)
    printf("Branch to Alice In Wonderland path\n");
    //aliceInWonderland();
  else if (choice == 5)
    printf("\n\nYou open up the cellphone and to your surprise, there is cell service! \
    You call 911 and get through to an operator.\nThey are able to find your location and they \
    send a helicopter to save you.\n\t\t\tVICTORY!!\nCongratulations, you've won!\n");
    finished = 1;
}

