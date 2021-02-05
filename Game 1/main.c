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
#include <rand.h>

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
void shuffle();
unsigned int seed;
int j,temp;
int randomseq[15];
int check(int,int);
int choice;
int score =0;
UINT8 player[2],i,a;


//triv[3]="What's larger? na. 2  b.19";





void main() {
    

	splashscreen();
	getQ();
	
	while(1) {
		restart(); 
		//chblankscreenON();
		while(!joypad()){seed++;if(seed>=100)seed=1;}
		waitpadup(J_START);
		//chblankscreenOFF();
		shuffle();
		//question(str);
   	 	//printf("\n%s",triv[0]);
		//charfiller(16);
		
		question(randomseq[0]);
		if (takeInput(randomseq[0])==1){
			score++;
			question(randomseq[1]);
			if (takeInput(randomseq[1])==1){score++;
				question(randomseq[2]);
				if (takeInput(randomseq[2])==1){score++;
					question(randomseq[3]);
					if (takeInput(randomseq[3])==1){score++;
						question(randomseq[4]);
						if (takeInput(randomseq[4])==1){score++;
							question(randomseq[5]);
							if (takeInput(randomseq[5])==1){score++;
								//printf("Correct");
							
								question(randomseq[6]);
								if (takeInput(randomseq[6])==1){score++;
									//printf("Correct");
								
									question(randomseq[7]);
									if (takeInput(randomseq[7])==1){score++;
										//printf("Correct");
									
										question(randomseq[8]);
										if (takeInput(randomseq[8])==1){score++;
											//printf("Correct");
										
											question(randomseq[9]);
											if (takeInput(randomseq[9])==1){score++;
												//printf("Correct");
											
												question(randomseq[10]);
												if (takeInput(randomseq[10])==1){score++;
													//printf("Correct");
												
													question(randomseq[11]);
													if (takeInput(randomseq[11])==1){score++;
														//printf("Correct");
													
														question(randomseq[12]);
														if (takeInput(randomseq[12])==1){score++;
															//printf("Correct");
														
															question(randomseq[13]);
															if (takeInput(randomseq[13])==1){score++;
																//printf("Correct");
															
																question(randomseq[14]);
																if (takeInput(randomseq[14])==1){score++;
																	chblankscreenOFF();		

																	printf("\n      YOU WON!   \n");
																	printf("      Thank you   \n");
																	printf("     for playing   ");
																	charfiller(14);
																	chblankscreenON();
																	delay(1500);
																}
																
															}		
															
														}
														
													}
													
												}
												
											}
											
										}
										
									}
									
								}
								
							}	
							
						}	
						
					}
					
				}
				
			}
			
		}
		
		
			//printf("A""for true \n""B""for false"" \n");
chblankscreenOFF();		

printf("\n     GAME ENDED   \n");
printf("    Press select   \n");
printf("   to play again   ");
if(score==15){
	
printf("      MAX SCORE     ");
}
else{
	
printf("       SCORE: %d",score);
}
charfiller(13);
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

void shuffle(){
		for(i=0;i<15;i++)
    {

        randomseq[i] =i;
        //printf("    %d",randomseq[i]);
        
    }
    
    for(i = 0; i < 15; i++)
    {
		initrand(DIV_REG);
		delay(seed);
        j = (rand()%13)+1;
        temp = randomseq[i];
        randomseq[i]=randomseq[j];
        randomseq[j] = temp; 
    }
	//printf("\n\n");
    /*for(i =0;i<15;i++){
		
    printf("    %d",randomseq[i]);
    } 
	for(i =0;i<15;i++){
		
    printf("    %s",triv[randomseq[i]]);
	waitpad(J_START);
    } */
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
		printf("\nCorrect");
		charfiller(17);
		chblankscreenON();
		
		return 1;
	}
	else{
		chblankscreenOFF();
		printf("\nWrong");
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
	    	 //printf("Press Start to Begin,Press Start to Begin,Press Start to Begin,Press Start to Begin");
	strcpy(triv[0], "Abraham Lincoln had\nno middle name");
	strcpy(triv[1], "Germany drinks the\nmost beer in the\n world per person");
	strcpy(triv[2], "Nemo\nis a puffer fish");
	strcpy(triv[3], "There was no World\nSeries in 1994");
	strcpy(triv[4], "Japan has square\nwatermelons");
	strcpy(triv[5], "Pinocchio was the\nfirst animated, full\ncolor Walt Disney\nfeature film");
	strcpy(triv[6], "Porcupines\ncan float");
	strcpy(triv[7], "Before becoming\nQueen Elizabeth, she\nwas a mechanic");//1
	strcpy(triv[8], "All the kings in a\nstandard deck of\ncards have a\nmustache");//0
	strcpy(triv[9], "In some states, it\nis illegal to eat\nspecific foods\nwhile walking\nbackwards");//1
	strcpy(triv[10], "Mario of\nSuper Mario Bros.\nwas once a\ncarpenter"); //1
	strcpy(triv[11], "Cows sleep standing\nup");//1
	strcpy(triv[12], "Polar bears skin\nis black");//1
	strcpy(triv[13], "The name of Batmans\nbutler is Albert");//0
	strcpy(triv[14], "People in Japan eat\nKFC for Christmas \ndinner");//1
}

void question(int index){
	chblankscreenOFF();
	printf("\n%s",triv[index]);
	charfiller(12);
	//printf("                    ");
	printf("           Score: %d",score);
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
		//waitpad(J_START);
	//chblankscreenOFF();
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
