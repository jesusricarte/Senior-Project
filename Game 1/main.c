#include <gb/gb.h>
#include <stdio.h>
#include "alpha.c"
#include "helloWorld.c"
#include "blankScreen.c"
#include "sprites.c"
#include "cave_splash_data.c"
#include "cave_splash_map.c"

void init();
void checkInput();
void updateSwitches();
void fadeout();
void fadein();
void splashscreen();

UINT8 player[2],i;

void main() {
    
	init();
	splashscreen();
	while(1) {
		
		//checkInput();				  // Check for user input (and act on it)
		updateSwitches();			// Make sure the SHOW_SPRITES and SHOW_BKG switches are on each loop
		wait_vbl_done();			// Wait until VBLANK to avoid corrupting visual memory
	
		
		// Game code here
	}
	
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
    waitpad(J_START);
    fadeout();
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
