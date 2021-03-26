#include<gb/gb.h>
#include<stdio.h>
#include <rand.h>
#include "sprites.c"
#include "windowtest_data.c"
#include "windowtest_map.c"
#include "windowmap.c"
#include "spook0_data.c"
#include "spook0_map.c"
#include "spook1_data.c"
#include "spook1_map.c"







UINT8 i,b,c;
UINT8 firstghostspeed, secondghostspeed,thirdghostspeed;
UBYTE BoyLoc[2];
UBYTE GhostLoc[2];
UBYTE Ghost2Loc[2];
UBYTE Ghost3Loc[2];
int CoinLoc[2];
//Write the sprite data array
int score=0;
int level =1;
int j,k;
UINT8 digitmap[1];
unsigned int seed;
void startscreen();
void fadein();
void spritesettings();
void fadeout();



UBYTE CollisionCheck(UINT8 BoyX,UINT8 BoyY, UINT8 GhostX, UINT8 GhostY){
	return ((BoyX < GhostX + 8 && GhostX < BoyX + 8) && (BoyY < GhostY + 8 && GhostY < BoyY + 8));
} 

void addEnemy(int xtilenum,unsigned char enemy){
	set_sprite_data(xtilenum,1,enemy);
	set_sprite_tile(xtilenum,xtilenum);
	//Ghost2Loc[0] = 120; //add enemy's x
	//Ghost2Loc[1] = 20; //add enemy's  y
	
	//move_sprite(3,Ghost2Loc[0],Ghost2Loc[1]);


	
}

void main(){

	
	

    startscreen();
		

	

	
	seed=0;
	while(!joypad()){seed++;if(seed>=100)seed=1;}
    
    waitpadup(J_START);
	HIDE_BKG;
	DISPLAY_OFF
	initrand(DIV_REG);
	delay(seed);
	
	


	set_bkg_data(0,200,text);
	set_bkg_tiles(0,0,20,18,scoremap);
    SHOW_BKG;

	spritesettings();
	

while(!CollisionCheck(BoyLoc[0],BoyLoc[1],GhostLoc[0],GhostLoc[1]) &&
 (!CollisionCheck(BoyLoc[0],BoyLoc[1],Ghost2Loc[0],Ghost2Loc[1])) && 
 (!CollisionCheck(BoyLoc[0],BoyLoc[1],Ghost3Loc[0],Ghost3Loc[1]))){
	windowmap[39]=score%10;
	windowmap[38]=score/10;
	windowmap[27] = level%10;
	set_win_tiles(0,0,20,2,windowmap);

 if(joypad() & J_LEFT){
	 if (BoyLoc[0]>11)
	 BoyLoc[0] = BoyLoc[0] - 4;
	 move_sprite(1, BoyLoc[0], BoyLoc[1]);
 }
  if(joypad() & J_RIGHT){
	  if (BoyLoc[0]<160)
	 BoyLoc[0] = BoyLoc[0] + 4;
	 move_sprite(1, BoyLoc[0], BoyLoc[1]);
 }

	delay(60);
	// Ghost Movement
	CoinLoc[1]= CoinLoc[1]+4;
	GhostLoc[1] = GhostLoc[1] + firstghostspeed;
	Ghost2Loc[1] = Ghost2Loc[1] + secondghostspeed; 
	Ghost3Loc[1] = Ghost3Loc[1] + thirdghostspeed;
	

	if(GhostLoc[1] >= 144){
		GhostLoc[1] = 0;
		GhostLoc[0] = BoyLoc[0];
	}
	if(Ghost2Loc[1] >= 144)
	{
		Ghost2Loc[1] = 0;
		Ghost2Loc[0] = (rand()%152)+8;
		if(Ghost2Loc[0] <11)
		{
			Ghost2Loc[0]=Ghost2Loc[0]*(-1);
		}
	}
	if(Ghost3Loc[1] >= 144)
	{
		Ghost3Loc[1] = 0;
		Ghost3Loc[0] = (rand()%152)+8;
		if(Ghost3Loc[0] <11)
		{
			Ghost3Loc[0]=Ghost3Loc[0]*(-1);
		}
	}
	if(CoinLoc[1] >= 144){
		CoinLoc[1] = 0;
		CoinLoc[0] = (rand()%152)+8;
		//CoinLoc[0] = CoinLoc[0]+8;
		if (CoinLoc[0]<0){
			CoinLoc[0]=CoinLoc[0]*(-1);
		}
		
	}
	move_sprite(0, GhostLoc[0], GhostLoc[1]);
	move_sprite(3, Ghost2Loc[0], Ghost2Loc[1]);
	move_sprite(4, Ghost3Loc[0], Ghost3Loc[1]);
	move_sprite(2,CoinLoc[0],CoinLoc[1]);
	
NR52_REG = 0x80; //..
NR50_REG = 0x77; // music enablers 
NR51_REG = 0xFF; //..
	if(CollisionCheck(BoyLoc[0],BoyLoc[1],CoinLoc[0],CoinLoc[1])){
		
		score=score+1;
		switch(score)
		{
		
			case 4:
				level = 1;
				break;
			case 5:
				level = 2;
				secondghostspeed = 10;
				NR10_REG = 0x00; 
				NR11_REG = 0x82; 
				NR12_REG = 0x55; 
				NR13_REG = 0x59;
				NR14_REG = 0x86;

				
				break;
		
			case 9:
			level = 2;
			secondghostspeed = 10;
			break;

			case 10:
			

				level = 3;
				thirdghostspeed = 10;
				NR10_REG = 0x00; 
				NR11_REG = 0x82; 
				NR12_REG = 0x55; 
				NR13_REG = 0x59;
				NR14_REG = 0x86;

		
				break;
			case 11:
			case 12:
			case 13:
			case 14:
			level = 3;
			thirdghostspeed = 10;
			break;
			case 15:
				level = 4;
				thirdghostspeed = 15;
				secondghostspeed = 15;
				firstghostspeed = 8;
				NR10_REG = 0x00; 
				NR11_REG = 0x82; 
				NR12_REG = 0x55; 
				NR13_REG = 0x59;
				NR14_REG = 0x86;
				break;
			case 16:
			case 17:
			case 18:
			case 19:
			level = 4;
				thirdghostspeed = 15;
				secondghostspeed = 15;
				firstghostspeed = 8;
				break;

			case 20:
				level = 5;
				thirdghostspeed = 15;
				secondghostspeed = 15;
				firstghostspeed = 15;
				NR10_REG = 0x00; 
				NR11_REG = 0x82; 
				NR12_REG = 0x55; 
				NR13_REG = 0x59;
				NR14_REG = 0x86;
				break;
			case 21:
				level = 5;
				thirdghostspeed = 15;
				secondghostspeed = 15;
				firstghostspeed = 15;

		}

	
	 NR21_REG = 0x82;   // ''
	 NR22_REG = 0x54;  //  coin
	 NR23_REG = 0x96; //   sound
	 NR24_REG = 0x87; //   ''
	
	 
	 
	
	
		CoinLoc[1]=0;
		CoinLoc[0] = (rand()%152)+8;
		//CoinLoc[0] = CoinLoc[0]+8;
		if (CoinLoc[0]<0){
			CoinLoc[0]=CoinLoc[0]*(-1);
		}
	}
    //HIDE_SPRITES;
	
	
}
delay(100);
	NR41_REG = 0x3F; // ''
	 NR42_REG = 0x4B; // death 
	 NR43_REG = 0x6F; // sound
	 NR44_REG = 0xC0; // '' 
	 
	 delay(200);
	DISPLAY_OFF;
	 HIDE_SPRITES;
	HIDE_WIN;
	 printf("-----Gameover-----"); 
	printf("\n   Final Score: %d", score);
	printf("\n   Level: %d", level); 
	 printf("\n\n\n   Press Select \n   To Play Again"); 
	  
	  waitpad(J_SELECT);
	  DISPLAY_OFF;
	  HIDE_BKG;
    set_bkg_data(0, 200, spook0_data);
    set_bkg_tiles(0,0,20,18,spook0_map);
	  reset();
	 



	/*printf("\n \n \n \n \n GAME OVER");
    printf("\n\n\n\n\n\n");
    printf("Play Again?.... Press Select");
    waitpad(J_SELECT);
    reset();
*/
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

void startscreen()
{
	

//SHOW_BKG;

	j = 500; 

 
    DISPLAY_OFF
    set_bkg_data(0, 200, spook0_data);
    set_bkg_tiles(0,0,20,18,spook0_map);
    
	SHOW_SPRITES;
	SHOW_BKG;
    DISPLAY_ON;
    //fadein();
	//waitpad(J_START);
    delay(j);
    //fadeout();
	fadein();
	

	//------------

	DISPLAY_OFF
    set_bkg_data(0, 198, spook1_data);
    set_bkg_tiles(0,0,20,18,spook1_map);
    
	SHOW_SPRITES;
	SHOW_BKG;
    DISPLAY_ON;
    //fadein();
	//waitpad(J_START);
    delay(j);
    //fadeout();
	fadein();


DISPLAY_OFF
    set_bkg_data(0, 200, spook0_data);
    set_bkg_tiles(0,0,20,18,spook0_map);
    
	SHOW_SPRITES;
	SHOW_BKG;
    DISPLAY_ON;
    //fadein();
	//waitpad(J_START);
    delay(j);
    //fadeout();
	fadein();
	
	//----
	DISPLAY_OFF
    set_bkg_data(0, 198, spook1_data);
    set_bkg_tiles(0,0,20,18,spook1_map);
    
	SHOW_SPRITES;
	SHOW_BKG;
    DISPLAY_ON;
    //fadein();
	//waitpad(J_START);
    delay(j);
    //fadeout();
	fadein();




}

void spritesettings()
{
	set_sprite_data(0, 1, Ghost);
	set_sprite_data(1, 1, Boy);
	set_sprite_data(2, 1, coin);
	set_sprite_data(3,1,Ghost2);
	set_sprite_data(4,1,Ghost3);

	set_sprite_tile(0, 0);
	set_sprite_tile(1, 1);
	set_sprite_tile(2, 2);
	set_sprite_tile(3,3);
	set_sprite_tile(4,4);
	// X location of Boy
	BoyLoc[0] = 80;
	// Y location of Boy
	BoyLoc[1] = 130;
	// X location of Ghost
	GhostLoc[0] = 50;
	// Y location of Ghost
	GhostLoc[1] = 50;

	Ghost2Loc[0] = 10; //Ghost2 x
	Ghost2Loc[1] = 50; //Ghost2 y

	Ghost3Loc[0] = 15;
	Ghost3Loc[1] = 50;

	CoinLoc[0]=120;
	CoinLoc[1]=20;





	move_sprite(0, GhostLoc[0], GhostLoc[1]);
	move_sprite(1, BoyLoc[0], BoyLoc[1]);
	move_sprite(2,CoinLoc[0],CoinLoc[1]);
	move_sprite(3,Ghost2Loc[0],Ghost2Loc[1]);
	move_sprite(4,Ghost3Loc[0],Ghost3Loc[1]);
	
	
SHOW_SPRITES;
	SHOW_BKG;
	SHOW_WIN;
    DISPLAY_ON;
move_win(8,128);
firstghostspeed = 4;
secondghostspeed = 4;
thirdghostspeed = 2;
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

