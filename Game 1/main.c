#include <gb/gb.h>
#include <stdio.h>
//#include <stdlib.h>
#include "alpha.c"
#include "helloWorld.c"
#include "blankScreen.c"
#include "sprites.c"
#include "cave_splash_data.c"
#include "cave_splash_map.c"
#include <string.h>

char triv[20][200];
int ans[20]={1,0,0,1,1,0,1,1,0,1,1,1,1,0,1};
void getQ();
void restart();
void checkInput();
void updateSwitches();
void fadeout();
void fadein();
void splashscreen();
void chblankscreenON();
void chblankscreenOFF();
void charfiller(int);
void question(int);
int takeInput(int);

int check(int,int);
int choice;
UINT8 player[2],i,a;


//triv[3]="What's larger? na. 2  b.19";





void main() {
    

	splashscreen();
	getQ();
	
	while(1) {
		restart(); 
		//question(str);
   	 	//printf("\n%s",triv[0]);
		//charfiller(16);
		//chblankscreenON();
		question(0);
		if (takeInput(0)==1){
			question(1);
			if (takeInput(1)==1){
				question(2);
				if (takeInput(2)==1){
					question(3);
					if (takeInput(3)==1){
						question(4);
						if (takeInput(4)==1){
							question(5);
							if (takeInput(5)==1){
								printf("Correct");
							
								question(6);
								if (takeInput(6)==1){
									printf("Correct");
								
									question(7);
									if (takeInput(7)==1){
										printf("Correct");
									
										question(8);
										if (takeInput(8)==1){
											printf("Correct");
										
											question(9);
											if (takeInput(9)==1){
												printf("Correct");
											
												question(10);
												if (takeInput(10)==1){
													printf("Correct");
												
													question(11);
													if (takeInput(11)==1){
														printf("Correct");
													
														question(12);
														if (takeInput(12)==1){
															printf("Correct");
														
															question(13);
															if (takeInput(13)==1){
																printf("Correct");
															
																question(14);
																if (takeInput(14)==1){
																	chblankscreenOFF();		

																	printf("\n      YOU WON!   \n");
																	printf("      Thank you   \n");
																	printf("     for playing   ");
																	charfiller(14);
																	chblankscreenON();
																}
																else{
																	printf("Wrong");
																	}
															}		
															else{
																printf("Wrong");
															}
														}
														else{
															printf("Wrong");
															}
													}
													else{
														printf("Wrong");
														}
												}
												else{
													printf("Wrong");
													}
											}
											else{
												printf("Wrong");
												}
										}
										else{
											printf("Wrong");
											}
									}
									else{
										printf("Wrong");
										}
								}
								else{
									printf("Wrong");
									}
							}	
							else{
								printf("Wrong");
								}
						}	
						else{
								printf("Wrong");
							}
					}
					else{
						printf("Wrong");
					}
				}
				else{
						printf("Wrong");
					}
			}
			else{
					printf("Wrong");
				}
		}
		else{
				printf("Wrong");
			}
		
			//printf("A""for true \n""B""for false"" \n");
chblankscreenOFF();		

printf("\n      YOU WON!   \n");
printf("      Thank you   \n");
printf("     for playing   ");
charfiller(14);
chblankscreenON();


/*
	for(i=0;i<6;i=i++){
		question(i);
		
		if(takeInput(i)!=1){
			i=5;
		}
		else{
			i=5;
		} 
		
	}
	*/
	
	//chblankscreen();

	

	
		
	
		checkInput();				  // Check for user input (and act on it)
		updateSwitches();			// Make sure the SHOW_SPRITES and SHOW_BKG switches are on each loop
		wait_vbl_done();			// Wait until VBLANK to avoid corrupting visual memory
		waitpad(J_SELECT);
		reset();
		//splashscreen();
		// Game code here
	}
	
}

int takeInput(int index){
	waitpad(J_A|J_B);
	if(joypad()==J_A) // If A is pressed
		{	
			
			choice=1;
			//print("");
			
		}

	else if(joypad()==J_B) // If B is pressed
		{	
			//print("");
			choice=0;
			
		}
	if(check(index,choice)==1){
		chblankscreenOFF();
		printf("Correct");
		charfiller(17);
		chblankscreenON();
		return 1;
	}
	else{
		chblankscreenOFF();
		printf("Wrong");
		charfiller(17);
		chblankscreenON();
		return 0;
	}
}

int check(int index,int choice){
	if(choice==ans[index]){
		return 1;
	}
	else{
		return 0;
	}

}



void getQ(){
	    	 printf("Press Start to Begin");
	strcpy(triv[0], "Abraham Lincoln had \nno middle name");
	strcpy(triv[1], "Germany drinks the \nmost beer in the\n world per person");
	strcpy(triv[2], "Nemo \nis a puffer fish");
	strcpy(triv[3], "There was no World \nSeries in 1994");
	strcpy(triv[4], "Japan has square \nwatermelons");
	strcpy(triv[5], "Pinocchio was the first animated, full-color Walt Disney feature film");
	strcpy(triv[6], "Porcupines can float");
	strcpy(triv[7], "Before becoming queen, Queen Elizabeth was a mechanic");//1
	strcpy(triv[8], "All the kings in a standard deck of cards have a mustache");//0
	strcpy(triv[9], "In some states, it’s illegal to eat specific foods while walking backwards");//1
	strcpy(triv[10], "Mario of Super Mario Bros. was once a carpenter"); //1
	strcpy(triv[11], "Cows sleep standing up");//1
	strcpy(triv[12], "Polar bears’ skin is black");//1
	strcpy(triv[13], "The name of Batman’s butler is Albert");//0
	strcpy(triv[14], "People in Japan eat Kentucky Fried Chicken for Christmas dinner");//1
}

void question(int index){
	chblankscreenOFF();
	printf("\n%s",triv[index]);
	charfiller(13);
	chblankscreenON();
	printf("");
}

void charfiller(int x){
	for( a = 0; a < x; a = a + 1 ){
      printf("\n");
   }
}



void chblankscreenOFF(){
	 DISPLAY_OFF
	//set_bkg_data(0, 512, alpha);
    set_bkg_tiles(0,0,20,18,blankScreen);
	
}

void chblankscreenON(){
	SHOW_SPRITES;
	SHOW_BKG;
    DISPLAY_ON;
	fadein();
}

void splashscreen(){
    fadeout();
    DISPLAY_OFF
    set_bkg_data(0, 512, cave_splash_data);
    set_bkg_tiles(0,0,20,18,cave_splash_map);
    
	SHOW_SPRITES;
	SHOW_BKG;
    DISPLAY_ON;
    fadein();
	//waitpad(J_START);
    delay(1500);
    fadeout();
}

void restart() {
	
	
	
	chblankscreenOFF();
	printf("    TRIVIA TUNNEL    \n\n");
    	printf("   Try to get out!   \n\n\n");
		printf("  Press A for True   ");
		printf("         \n\n");
		printf("  Press B for False  ");
		printf("         \n\n");
		printf("Press Start to Begin");
		charfiller(1);
	chblankscreenON();
		waitpad(J_START);
	chblankscreenOFF();
	// Turn on the display
	//NR52_REG = 0x8F;	// Turn on the sound
	//NR51_REG = 0x11;	// Enable the sound channels
	//NR50_REG = 0x77;	// Increase the volume to its max
    //set_bkg_data(0, 47, alpha);		// Load 47 tiles into background memory
    // Use the 'helloWorld' array to write background tiles starting at 0,6 (tile positions)
	//  and write for 10 tiles in width and 2 tiles in height
	//set_bkg_tiles(0,6,10,2,helloWorld);
    //SHOW_WIN;
	//SHOW_SPRITES;
	//SHOW_BKG;
    // Load the the 'sprites' tiles into sprite memory
	//set_sprite_data(0, 1, sprites);
	
	// Set the first movable sprite (0) to be the first tile in the sprite memory (0)
	//set_sprite_tile(0,0);
	
	//player[0] = 80;
	//player[1] = 72;
}

void updateSwitches() {
	
	HIDE_WIN;
	SHOW_SPRITES;
	SHOW_BKG;
	
}

void checkInput() {
    
   if (joypad() & J_SELECT) {
		
		// Use the 'blankScreen' array to write background tiles starting at 0,0 (tile positions)
		//  and for 20 tiles in width and 18 tiles in height
		restart();
    }
    


}

void fadeout(){
	wait_vbl_done();
	// looks like magic actually its changing the palette for the background
	// switching each colour in the palette to black step by step	
	for(i=0;i!=4;i++){
		switch(i){
			case 0:
				BGP_REG = 0xE4;
				break;
			case 1:
				BGP_REG = 0xF9;
				break;
			case 2:
				BGP_REG = 0xFE;
				break;
			case 3:
				BGP_REG = 0xFF;
				break;												
		}
		delay(100);
	}	
}

void fadein(){
	wait_vbl_done();
	// looks like magic actually its changing the palette for the background
	// switching each colour in the palette to white step by step
	// dont need to start at all back as will have been set that by 
	// fadeout
	for(i=1;i!=4;i++){
		switch(i){
			case 1:
				BGP_REG = 0xFE;
				break;
			case 2:
				BGP_REG = 0xF9;
				break;
			case 3:
				BGP_REG = 0xE4;
				break;											
		}
		delay(100);
	}	
}
