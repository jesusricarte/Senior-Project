#include <time.h>
#include <gb/gb.h>
#include <stdio.h>
#include <stdlib.h>
#include "alpha.c"
#include "helloWorld.c"
#include "blankScreen.c"
#include "sprites.c"
#include "cave_splash_data.c"
#include "cave_splash_map.c"
#include <string.h>
#include <rand.h>
#include <types.h>




#define MAX_STRING_SIZE 100
unsigned int r,seed,key;
void init();
void checkInput();
void updateSwitches();
void fadeout();
void fadein();
void pleasework();
void splashscreen();

UINT8 player[2],i;




void main()
 {
	 
	
	
	int one = 1;
	int zero = 0;
	int i,j,temp;
	char triv[6][50];
    int randomseq[6];
    int q1,q2,q3,q4,q5,q6;
	seed =0;
	key = 0;
	r = 0;
	//rand(time(seed));
   	//r = rand() % 4;

    
    
	
	
	//int randomnum = rand() % 6;


    init();
    splashscreen();
	while(!joypad()){seed++;if(seed>=100)seed=1;}
    waitpadup(J_START);
	
	
	
   	fadeout();
    HIDE_SPRITES;
    updateSwitches();            // Make sure the SHOW_SPRITES and SHOW_BKG switches are on each loop
    wait_vbl_done();            // Wait until VBLANK to avoid corrupting visual memory

         set_bkg_data(0,512,blankScreen);
         set_bkg_tiles(0,0,20,18,blankScreen);
         fadein();
         SHOW_BKG;
         HIDE_BKG;
         HIDE_SPRITES;
		 //printf("%d", r);
         printf("   TRIVIA TUNNEL     \n\n");
         printf("   try to get out!     \n");
        

	//rand(time(seed));
    strcpy(triv[0],"  index0");
    strcpy(triv[1],"  index1");
    strcpy(triv[2],"  index2");
    strcpy(triv[3],"  index3");
    strcpy(triv[4],"  index4");
    strcpy(triv[5],"  index5");
    //strcpy(triv[6],"\n  index6");
    
    for(i=0;i<6;i++)
    {

        randomseq[i] =i;
        printf("    %d",randomseq[i]);
        
    }
    
    for(i = 0; i < 6; i++)
    {
		initrand(DIV_REG);
		delay(seed);
        j = (rand()%4)+1;
        temp = randomseq[i];
        randomseq[i]=randomseq[j];
        randomseq[j] = temp; 
        //printf(" %d ", rand() % 6);
    }
	printf("\n\n");
    for(i =0;i<6;i++){
		
    printf("    %d",randomseq[i]);
    }    
    
    q1 =randomseq[0];
    q2 =randomseq[1];
    q3 =randomseq[2];   //randomly nonrepeting generated order 
    q4 =randomseq[3];
    q5 =randomseq[4];
    q6 =randomseq[5];
	//q = randomseq[6];
	
    
printf("\nQ1: %s", triv[randomseq[0]]);
printf("\nQ2: %s", triv[randomseq[1]]);
printf("\nQ3: %s", triv[randomseq[2]]);
printf("\nQ4: %s", triv[randomseq[3]]);
printf("\nQ5: %s", triv[randomseq[4]]);
printf("\nQ6: %s", triv[randomseq[5]]);

		waitpad(J_START);
 }
            
		

	

void splashscreen(){
	
    fadeout();
    DISPLAY_OFF
    set_bkg_data(0, 512, cave_splash_data);
    set_bkg_tiles(0,0,20,18,cave_splash_map);
    
	//SHOW_SPRITES;
	
	SHOW_BKG;
	
    DISPLAY_ON;
    
	fadein();
}

void init() {
	
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
	
	player[0] = 80;
	player[1] = 72;
}

void updateSwitches() {
	
	HIDE_WIN;
	SHOW_SPRITES;
	SHOW_BKG;
	
}

void checkInput() {
    
   if (joypad() & J_B) {
		
		// Use the 'blankScreen' array to write background tiles starting at 0,0 (tile positions)
		//  and for 20 tiles in width and 18 tiles in height
		set_bkg_tiles(0,0,20,18,blankScreen);
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
