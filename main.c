#include <stdio.h>
#include <stdlib.h>

int health = 100;
int fire = 0;
int cellphone = 0;
int finished = 0;
int shotgun = 0;
int ammo = 0;
int potion = 0;
int key = 0;
int hasSword = 0;
int luckItem1 = 0;
int luckItem2 = 0;
int luckItem3 = 0;
int braveItem1 = 0;
int braveItem2 = 0;
int braveItem3 = 0;
int survivalItem1 = 0;
int survivalItem2 = 0;
int survivalItem3 = 0;
int hasFish = 0;
int brokenArm = 0;

int end();
void startFunc();
void runGame();
void stayPut();
void buildFire();
void fixCellphone();
void climbTree();
void chooseNewLocation();
void whiteRabbit();
void hill();
void valley();
void mountain();
void cave();
void cliff();
void river();
void fish();
void bear();
void beaver();
void waterfall();
void final();
int ending();
void torrey();
void ComeToPath();
void OutsideHouse();
void House();
void Shed();
void WoodsClearing();
void Tree();
void markingsExit();


 

char c;

char* inventory(int);

void flush(){
	fflush(stdout);
	fflush(stdin);
}


int main() {
	startFunc();
	return 0;
}

void startFunc() {
	printf("You Find yourself in the middle of nothing\n");
	printf("Please select an option using\n");
	printf("the integers on the left.\n\n");

	printf("Where do you want to go?\n");
	beginning:
	flush();
	printf("(1)the woods \n"
	"(2)follow the rabbit \n"
	"(3)up the hill \n"
	"(4) \n"
	"(5)follow the sound of running water\n ");
	printf("\n\n");
	scanf("%c", &c);
	switch(c){
		case '1' : printf("going into the woods\n");
				   stayPut();
		case '2' : printf("going uphill\n");
				   torrey();
		case '3' : printf(" following the white rabbit\n");
				   whiteRabbit();
		case '4' : printf("1)Try and find some higher ground /n");
				   hill();
		case '5' : printf("following the sound of running water.\n");
				   river("\nYou have followed the sound of running water and come across"
        			" a large river; almost\n30 meters across. There are large rocks and the"
				" current seems moderately strong.\nSelect your next move:\n1. Attempt"
        			" to catch a fish\n2. Travel upstream\n3. Travel downstream\n4. Cross"
        			" the river\n5. Go back\n\n");
		default  : goto beginning;
	}
}
	void whiteRabbit() {
	flush();
	printf("You fall into a rabbit hole!\n");
	printf("There is a potion and a key on a table, and a really small door. The door is only big enough to fit a mouse.");
	start:
	printf("(1)Drink the potion \n");
	printf("(2)Grab the key \n");
	printf("(3)Squeeze through the door \n");
	//if(item1) printf(", (a)go to final area");
	printf("\n");
	scanf("%c", &c);
	switch(c){
		case '1' : printf("You drink the potion\n");
				   potion=1; goto start;
		case '2' : printf("The key is now in your pocket\n");
					key=1; goto start;
		case '3' : if(potion & key) printf("You go through the door!");
					else printf("you cant go through the door");
		default  : goto start;
	}
}
	void final() {
	final:
	flush();
	printf("(1) end this adventure (2) do nothing");
	printf("\n");
	scanf("%c", &c);
	switch(c){
		case 'n' : printf("\n");
				   printf("doing nothing again\n"); goto final;
		case 'e' : printf("ENDING!\n");
				   printf("\n"); break;
		default  : goto final;
	}
	
	if(potion && key){
		printf("Congratulations!");
		end();
	} else {
		printf("You failed to get the items");
		if(!potion && !key) printf("You didn't get either");
		else if(!potion) printf("you forgot item1");
		else printf("you forgot item2");
		end();
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

// Laura's part
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
    	You warm yourself up around the fire and pack the extra materials you gathered in your \
    	backpack so that you can make a fire again if you need to. Achievement unlocked: Fire building\n");
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
  	health = 0;
  	ending();
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
    	Nothing comes up on the screen but you feel the phone getting warm in your hands. \
    	You think that this must be a good sign, and wait as the phone gets warmer and warmer. \
    	Suddenly, you realize that you must have connected the wrong wires to the wrong terminals\
    	and that the battery must be short-circuiting! Unfortunately, you are not able to \
    	disconnect the wires in time and the phone blows up in your hands. A sharp piece of metal \
    	flies from the phone and into your temple, and you feel the blood starting to trickle down \
    	your face as everything fades to black...\n\t\t\tGAME OVER\n");
   	finished = 1;
   	health = 0;
   	ending();
   	
  }
}


void chooseNewLocation() {
  // Choose between climbing a tree or going back to the original 5 options
  int choice = getUserInput("\nWhat will you choose?\n\t1. Climb the tallest tree you see near you\n\t\
  	2. Choose one of the original 5 choices\n", 1, 2);
  if (choice == 1)
    climbTree();
  else if (choice == 2)
  // return to the original five choices
    startFunc();
    
}

void climbTree() {
  printf("\n\nYou decide to climb a tall tree.You see a cliff and a cabin.\n");
  char choices[] = "What will you do?\n\t1. Go to the cliff\n\t2. Go to the cabin\n";
  char specialChoice[] = "\t3. Try your phone and see if there is cell service up here\n";
  printf("%s", choices);
  int choice;
  if (cellphone == 1) {
    printf("%s", specialChoice);
    choice = getUserInput("", 1, 3);
  }
  else
    choice = getUserInput("", 1, 2);

  if (choice == 1)
    cliff();
  else if (choice == 2)
    OutsideHouse();
  else if (choice == 3)
    printf("\n\nYou open up the cellphone and to your surprise, there is cell service! \
    You call 911 and get through to an operator.\nThey are able to find your location and they \
    send a helicopter to save you.\n\t\t\tVICTORY!!\nCongratulations, you've won!\n");
    finished = 1;
    ending();
}


//torreys part
int ending(){
  if(luckItem1==1 && luckItem2==1 && luckItem3==1){
    finished=1;
    printf ("You've won the Lucky way!\n");
  }else if(braveItem1==1 && braveItem2==1 && braveItem3==1){
    finished=1;
    printf ("You've won the Brave way!\n");
  }else if(survivalItem1==1 && survivalItem2==1 && survivalItem3==1){
    finished=1;
    printf ("You've won the Survival way!\n");
  }else if (health<=0){
    finished=1;
    printf ("You have Died!\n");
  }

   void ComeToPath(){
    int choice;
    printf ("You come across a Path, you don't know where it leads but you can also see what looks to be an opening i bit deeper into the woods.\n");
    printf ("Would you like to:\n");
    printf ("1. See whats down the path.\n");
    printf ("2. Push your way to the clearing.\n");
    printf ("3. Head back to the Start\n");
    scanf("%d",&choice);
    if (choice==1){
      printf ("You make your way down the path!\n");
      location = "newLocation";
    }else if (choice==2){
      printf ("You start pushing your way through the brush towards the clearing\n");
      location = "newLocation";
    }else if (choice==3){
      printf ("You head back to where You Started\n");
      location = "newLocation";
    }
  }

  void OutsideHouse(){
    int choice;
    printf ("You come across a broken down house, you cant tell if anyone is living there or not. Theres also a shed behind the house which may have useful supplies.\n");
    printf ("Would you like to:\n");
    printf ("1. Throw a stone at the window to see if anyone is home.\n");
    printf ("2. Go in the house.\n");
    printf ("3. Walk to the shed in the back.\n");
    printf ("4. Head back to the Path\n");
    scanf("%d",&choice);
    if (choice==1){
      printf ("You throw a rock through the window, you then hear a loud bang and a pain in your chest! Guess someone was home!\n");
      health=0;
    }else if (choice==2){
      printf ("You make your way to the door.\n");
      location = "newLocation";
    }else if (choice==3){
      printf ("You make your way to the shed in the back.\n");
      location = "newLocation"
    }else if (choice==4){
      printf ("You head back to the path.\n");
      location = "newLocation";
    }
  }

  void House(){
    int choice;
    printf ("As you get to the door a man greets you and invites you inside. Its very simple, just a kitchen, table, bed and you see a shotgun leaning against the wall.\n");
    printf ("Would you like to:\n");
    printf ("1. Demand he gives you the shotgun.\n");
    printf ("2. Open cupboard\n");
    printf ("3. Ask for the shotgun.\n");
    printf ("4. Take ths shotgun.\n");
    printf ("5. leave the house\n");
    scanf("%d",&choice);
    if (choice==1){
      printf ("Oh he gives you the shotgun alright... right in the chest.\n");
      health=0;
    }else if (choice==2){
      printf ("You find shotgun ammo and take some\n");
      ammo=1;
      location = "newLocation";
    }else if (choice==3){
      printf ("No.... Did you honestly think that would work???\n");
      location = "newLocation";
    }else if (choice==4){
      printf ("You take the shotgun\n");
      shotgun=1;
      location = "newLocation";
    }else if (choice==5){
      printf ("You head back outside.\n");
      location = "newLocation";
    }
  }
  
  void Shed(){
    int choice;
    printf ("You walk up to what looks like a completely normal shed with a small window on the side.\n");
    printf ("Would you like to:\n");
    printf ("1. Look in the window.\n");
    printf ("2. Go inside.\n");
    printf ("3. Go back out front of the house.\n");
    scanf("%d",&choice);
    if (choice==1){
      printf ("It looks completely normal, a shovel, some gardening equipment and some random odds and ends.\n");
      location = "newLocation";
    }else if (choice==2){
      printf ("As you walk in something hits you in the back of the head and you black out....\n"); 
      location = "newLocation";
    }else if (choice==3){
      printf ("You walk back around front.\n");
      location = "newLocation";
    }
  }

  void WoodsClearing(){
    int choice;
    printf ("You come across an opening in the woods. There are some raspberry bushes, and apple tree and some strange markings on the ground faintly glowing.\n");
    printf ("Would you like to:\n");
    printf ("1. Go over to the berry bush.\n");
    printf ("2. Head to the apple tree.\n");
    printf ("3. Check out the strange markings.\n");
    printf ("4. Head back to the Path\n");
    scanf("%d",&choice);
    if (choice==1){
      printf ("You grab some berries from the bush and eat a few\n");
	  printf ("You feel your stomach rumble then your heart stop, guess those weren't raspberries....oh well, you really shouldn't trust the everything the narrator tells you!\n");
      health=0;
    }else if (choice==2){
      printf ("You make your way to the apple tree.\n");
      location = "newLocation";
    }else if (choice==3){
      printf ("You head towards the strange markings.\n");
      location = "newLocation";
    }else if (choice==4){
      printf ("You head back to the path.\n");
      location = "newLocation";
    }
  }

  void Tree(){
    int choice;
    printf ("You stand before a large apple tree, many apples have fallen to the grown but the best ones are still on the branches.\n");
    printf ("Would you like to:\n");
    printf ("1. Take an apple from the ground.\n");
    printf ("2. Try and knock an apples from the tree .\n");
    printf ("3. Go back to the opening.\n");
    scanf("%d",&choice);
    if (choice==1){
      printf ("You pick up an apple off the ground and inspect it, looks good so you take a big bite, turns out it was rotten to the core! your vision fades as you hit the ground. WHO EATS FOOD OFF THE FOREST FLOOOR!?!??!?\n");
      health=0;
    }else if (choice==2){
      printf ("You grab a small rock and throw it straight up at the apple above you as hard as you can. Your Athletics lvl isn't high enough so you miss the apple entirely and it comes down and hits you on the head. You really should have thought to maybe, you know... move?\n"); 
      health=0;
	  location = "newLocation";
    }else if (choice==3){
      printf ("You walk back to the clearing.\n");
      location = "newLocation";
    }
  }
  
  void markingsExit(){ //where someone else can come in
    int choice;
    printf ("The markings below your feet glow with an eerie faint purple light\n");
    printf ("Would you like to:\n");
    printf ("1. Stand on the markings.\n");
    printf ("2. Go back to the opening.\n");
    scanf("%d",&choice);
    if (choice==1){
      printf ("You fall over as a voice startles you saying \"Welcome to standing up school!\" \"and you fail...\" \n");
	  printf ("ACHIVEMENT GET: asdf movie refrence");
	  location = "newLocation";
    }else if (choice==2){
      printf ("You walk back to the clearing.\n");
      location = "newLocation";
    }
  }
	     
return 0;
}

/*
MATT's CODE
*/

//GLOBAL VARIABLES
//int hasSword = 0;
//int hasShotgun = 0;

void river(char* message){

  int input = getUserInput(message,1,5);

  if (input == 1){
    fish("\nYou take off your shoes and walk into a shallow area of the river; fish"
         "swimming beneath you.\nYou put your hands into the water and wait for the"
         "right moment");
  }
  else if (input == 2){
    beaver();

  }
  else if (input == 3){
    bear("\nYou're walking along the river when you hear a rustling in the"
         " trees to your right.\nIt's a bear! You've been spotted! What do"
         " you wish to do?\n1. Climb a tree\n2. Fight\n3. Retreat\n\n");

  }
  else if (input == 4){
    waterfall();
  }
  else { //input == 5
    startFunc();
  }
}

void fish(char* message){

  if (brokenArm == 1){
    printf("You broke your arm falling out of a tree. How do you expect to catch a fish."
           " Back you go.\n");
    river("Select a different route this time:\n1. Attempt to catch a fish\n"
          "2. Travel upstream\n3. Travel downstream\n4. Cross the river\n5. Go back\n\n");
  }
  else if (hasFish == 1){
    printf("\nOh wait! You already have a fish. You can only hold one at a time!\n");
    river("Select a different route this time:\n1. Attempt to catch a fish\n"
          "2. Travel upstream\n3. Travel downstream\n4. Cross the river\n5. Go back\n\n");
  }
  else{
    int input = getUserInput("\nYou manage to catch a single fish. It's a salmon"
            " weighing about 10 lbs.\nDo you want to keep it?\n1. Yes\n2. No\n\n",1,2);

    if (input == 1){
      printf("\nGreat! You have a fish, maybe you can make a fire later and eat it!\n");
      hasFish = 1;
      river("Where would you like to go now?\n1. Attempt to catch a fish\n2. Travel upstream"
            "\n3. Travel downstream\n4. Cross the river\n5. Go back\n\n");
    }
    else{ // input == 2
      printf("\nYou place the fish back into the water.\n");
      river("Where would you like to go now?\n1. Attempt to catch a fish\n2. Travel"
            " upstream\n3. Travel downstream\n4. Cross the river\n5. Go back\n\n");
    }
  }
}

void bear(char* message){

  int input = getUserInput(message,1,3);

  if (input == 1){ //Climb tree
    printf("\nYou climb the nearest tree. You idiot... bears can climb trees\n");
    if (hasFish == 1){
      int input2 = getUserInput("You still have that fish in you back pocket. It may be"
                            " your only hope to survive.\nDo you want to use the fish?\n1."
                            " Yes\n2. No\n\n",1,2);

      if (input2 == 1){
        hasFish = 0;
        printf("/nYou throw the fish and divert the bear. You're safe... for now. Try and\n"
               "find some weapons for next time.");
        river("/nYou travel back upstream. What do you want to do now?\n1. Attempt to"
              " catch another fish\n2. Travel upstream\n3. Travel downstream\n4."
              " Cross the river\n5. Go back\n\n");
      }
      else{ //input2 == 2
        printf("\nThe bear attacks you viciously... he clearly wants that fish. You put"
               " up a good fight\n and walk away with your fish still in hand, but not"
               " without a few scratches\n");
        health -= 15;
        printf("You lose 15 health. Current health: %d. Try and find some weapons"
               "to protect yourself.\n", health);
        river("You travel back upstream. What do you want to do now?\n2. Travel"
              " upstream\n4. Cross the river\n5. Go back\n\n");
      }
    }
    else{ //hasFish == 0
      printf("\nThe bear knocks you out of the tree. You fall to the ground and injure"
             " your arm, but are able to run away back to safety\n");
      brokenArm = 1;
      health -= 10;
      printf("You lose 10 health. Current health: %d\n", health);
      river("Select your next move:\n1. Attempt to catch a fish\n2. Travel upstream\n"
            "4. Cross the river\n5. Go back\n\n");
    }
  }
  else if (input == 2){ //Fight
    if (hasSword == 1){ //Use sword to figh bear
      //VICTORY
      printf("\nYou draw your sword. The bear lets out a roar and begins to charge at you."
             "In an epic battle to the death\n you come out victorious. The bear is dead."
             "You skin it and make an awesome coat, like a boss.");
    }
    else if (shotgun == 1){ //Use shotgun to fight bear
       //VICTORY
      printf("\nThe bear begins to approach you, and begins to charge. You pull out your"
             "shotgun and fire on the bear.\nfrom 30 feet out. He's wounded but still"
             "coming. You fire two more shots on him and he falls to the ground.\n"
             "The bear is dead");
    }
    else{ //No weapons available
      printf("\n1v1 against a bear with no weapons... good choice\n");
      health -= 30;
      printf("You lose 30 health. Current health: %d\n", health);
      river("How are you even alive right now?! Select your next move:\n1.Attempt to"
            "catch a fish\n2. Travel upstream\n4. Cross the river\n5. Go back\n\n");
    }
  }
  else{ // (input == 3) -> Retreat
    printf("\nGood idea, that bear looks angry. Some weaponry might come in handy.");
    river("\nClose call but you've retreated safely. Select your next move:\n"
          "1. Attempt to catch a fish\n2. Travel upstream\n3. Travel downstream\n"
          "4. Cross the river\n5. Go back\n\n");
  }
}

void waterfall(){
  printf("\nYou slipped on a wet rock crossing the river and the current was to strong"
         " for you to escape. \nUnfortunatley there was a waterfall up ahead and you"
         " plumeted to the bottom of the falls\n");
  health -= 10;
  printf("You lose 10 health. Current health: %d\n", health);
  //GO TO SOMEONE ELSES GAME
}

void beaver(char* message){
  printf("\nYou start the trek upstream and see a beaver dam up ahead. You're curious"
         " so you get as close as possible.\nA beaver sneaks up behind you and bites you"
         " in the ankle! Ouch!\n");
  health -= 5;
  printf("You lose 5 health. Current health: %d\n", health);
  river("Looks like upstream was a bad idea. You hobble back to th main river."
        " Select your next move:\n1. Attempt to catch a fish\n2. Travel upstream\n"
        "3. Travel downstream\n4. Cross the river\n5. Go back\n\n");
}
//jon's stuff

void hill(){
int i;
printf("You climb a small hill and that hopes that it might provide a better view are shattered, there is a valley and a mountain in the distance and forest all around. No sign of civilization to be found./n ");
printf("Current health: %d /n",health); 
printf("1)Is that the sounds of bees?Lets try and get some honey! /n");
printf("2)Rest on the hill. Maybe you're tired, mabe you're lazy. Either way rest a while. /n");
printf("3)Explore into the valley and towards the mountain./n");
//printf("4)/n");
scanf("%d", &i);
if(i==1){
	printf("The bee's swarm you you and string angrily, really you should have seen this coming./n  -10 health /n");
	health= health-10;
	hill();	
}
if(i==2){
	printf("The Sun light comforts you like an old friends and you quickly fall sleep. When you awake you find you have an unbearable sun burn and cant help but think what a bad idea this was./n -10 health /n");
	health=health-10;
	hill();
}
if(i==3){
	printf("The walk down into the valley is an uneasy one. There are many stones along the path and you nearly trip several times./n");
	valley();	
}
if(i==4){
}
else{
	printf("invalid input");
	hill();
}
}
void valley(){
int i;
printf("The valley is beautiful and fully of vibrant flowers. The foot of the mountain is close by and the shadow it casts provides slight respite. /n");
printf("Current health: %d /n", health); 
printf("1)Stay a while and pick flowers, what could go wrong? /n");
printf("2)Trying to prove that you're tough, lets climb that mountain and show them who's boss./( who are you talking to?/) /n");
printf("3)This valley looks full of life perhaps there is food near by, lets take a look./n");
//printf("4)/n");
scanf("%d", &i);
if(i==1){
}
if(i==2){
	printf("You put all your energy into the climb berfore you, you are lucky not to fall, but the effort alone just might kill you./n -10 health /n");
	health=health-10;
	mountain();
}
if(i==3){
}
if(i==4){
}
else{
	printf("invalid input");
	valley();
}
}
void mountain(){
int i;
printf("You reach a flat point in the mountain, an old camp site? You can't be sure. In front of you there is a dark cave, as well as a winding path that skirts the edge of the mountain. /n ");
printf("Current health: %d /n",health); 
printf("1)The path along the edge of the cliff doesn't look safe, are you still trying to prove you're tough, if so why not give it a shot. /n");
printf("2)Adventure calls and every good adventure needs a cave! You rush forward into the mount of the cave seeking fortune or whatever./n");
printf("3)Up this high you hear the rude bleating of a mountain goat, you think he'd make a fine coat to keep you warm. After him!/n");
printf("4)Your on a mountain, how could you pass up the chance to yodel?/n");
scanf("%d", &i);
if(i==1){
	printf(" you slowly ease yourself along the thin path, hugging close to the rock wall in front of you./n");
	cliff();
}
if(i==2){
	printf("As you heroically sruge into the cave you realise just how idiot of an idea this was./n");
	cave();
}
if(i==3){
	printf("You are fast, but the mountain goat is.. well a goat and much more suit to this kind of thing, you take a nasty fall down the mountain, what ever were you thinking?/n -40 health /n"); 
	health=health-40;
	valley();
}
if(i==4){
	printf("There are few moments in ones life where they feel truly free, when you saw the small rock slide your caterwauling created, it was not one of them./n -30 health /n");
		health=health-30;
		mountain();
}
else{
	printf("invalid input");
	mountain();
	}
}
void cave(){
int i;
printf("The cave is dark and you can barely make out your surroundings. There are rocks more rocks and some rocks you think might actually be bones, but most likely still just rocks, you hope /n");
printf("1)You've come this far, why not go a little farther, deeper into the cave! /n");
printf("2)You really hope that those rocks aren't bones, but lets check just to be sure./n");
printf("3)Your laziness knows no bounds.Lets have a nap, at least you won't be rained on. /n");
printf("4)Mysterious cave mushrooms, what a great idea! /n");
printf("5)Leave the cave, it's too dark in here anyhow./n" );
scanf("%d", &i);
if(i==1){
}
if(i==2){
	if(hasSword!=1){
		printf("Of course its a dead body your luck isn't good enough for it not to be, but hey he's got a sword that you can take!/n");
		hasSword=1;
		cave();
	}
	else{
		printf("You've already gotten the sword why not let the dead rest./n");
		cave();
	}
}
if(i==3){
}
if(i==4){
}
if(i==5){
	printf("You leave the cave seeking the light of day once again./n");
	mountain();
}
else{
	printf("invalid input");
	cave();
	}
}
void cliff(){
int i;
printf("The narrow ledge you stand upon is making unnerving cracking sounds. You're pretty sure this is the end, but seeing as you went out onto the cliff in the first place I wouldn't trust your judgement./n ");
printf("1)Hey you saw this in a video game once, its called the leap of faith, why not try it you've already proven you're stupid enough./n");
printf("2)Forward is the only option, continue along the already falling apart cliff edge, I'm sure you'll be just fine./n");
printf("3)Hmm lets pick another direction, why not try climbing up higher, that seems like a good idea./n");
printf("4)Go back the way you came. See this wasn't a good idea./n"); 
//printf("4)/n");
scanf("%d", &i);
if(i==1){
	printf("You leap from the cliff edge and assume you are going to die as you free fall./n"); 
	waterfall();
}
if(i==2){
	printf("The ledge buckles under your weight and you tumble down the sheer mountain face towards the valley below./n -30 health /n");
	health=health-30;
	valley();
}
if(i==3){
	printf("The climb not only wastes tons of time but you end up back by the cave, well done you achieved nothing. Other then getting a nasty gash in your hand./n -10 health /n");
	health=health-10;
	mountain();
}
if(i==4){
	printf("Well you didnt waste any time so i guess this wasn't a total loss./n");
	mountain();	
}
else{
	printf("invalid input");
	cliff();
	}
}	



