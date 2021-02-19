#include<gb/gb.h>
#include<stdio.h>
#include<rand.h>
#include "ghostSprite.c"
#include "boySprite.c"
#include "coin.c"
#include "windowtest_data.c"
#include "windowtest_map.c"
#include "windowmap.c"

UBYTE BoyLoc[2];
UBYTE GhostLoc[2];
int CoinLoc[2];
//Write the sprite data array
UINT8 score=0;
UINT8 digitmap[1];
unsigned int seed;


UBYTE CollisionCheck(UINT8 BoyX,UINT8 BoyY, UINT8 GhostX, UINT8 GhostY){
	return ((BoyX < GhostX + 8 && GhostX < BoyX + 8) && (BoyY < GhostY + 8 && GhostY < BoyY + 8));
} 

void main(){
	//int r1;
	
	seed=0;
	while(!joypad()){seed++;if(seed>=100)seed=1;}
    waitpadup(J_START);
	initrand(DIV_REG);
	delay(seed);
	

	/*if (r2<0){
		r2=r2*-1;}*/
	//int r1 = rand() % 5;
	//UINT8 r2 = ((UINT8)rand()) % (UINT8)5;
	set_bkg_data(0,47,text);
	set_bkg_tiles(0,0,20,18,scoremap);
	//set_win_tiles(0,0,20,2,windowmap);
	set_sprite_data(0, 1, Ghost);
	set_sprite_data(1, 1, Boy);
	set_sprite_data(2, 1, coin);

	set_sprite_tile(0, 0);
	set_sprite_tile(1, 1);
	set_sprite_tile(2, 2);
	// X location of Boy
	BoyLoc[0] = 80;
	// Y location of Boy
	BoyLoc[1] = 130;
	// X location of Ghost
	GhostLoc[0] = 50;
	// Y location of Ghost
	GhostLoc[1] = 50;

	CoinLoc[0]=120;
	CoinLoc[1]=20;


	move_sprite(0, GhostLoc[0], GhostLoc[1]);
	move_sprite(1, BoyLoc[0], BoyLoc[1]);
	move_sprite(2,CoinLoc[0],CoinLoc[1]);
	
	
SHOW_SPRITES;
	SHOW_BKG;
	SHOW_WIN;
    DISPLAY_ON;
move_win(8,128);


	

while(!CollisionCheck(BoyLoc[0],BoyLoc[1],GhostLoc[0],GhostLoc[1])){
	windowmap[39]=score%10;
	windowmap[38]=score/10;
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
	GhostLoc[1] = GhostLoc[1] + 4;
	if(GhostLoc[1] >= 144){
		GhostLoc[1] = 0;
		GhostLoc[0] = BoyLoc[0];
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
	move_sprite(2,CoinLoc[0],CoinLoc[1]);

	if(CollisionCheck(BoyLoc[0],BoyLoc[1],CoinLoc[0],CoinLoc[1])){
		
		score=score+1;
		CoinLoc[1]=0;
		CoinLoc[0] = (rand()%152)+8;
		//CoinLoc[0] = CoinLoc[0]+8;
		if (CoinLoc[0]<0){
			CoinLoc[0]=CoinLoc[0]*(-1);
		}
	}
}

	//HIDE_SPRITES;
	
	//printf("\n \n \n \n \n GAME OVER");

}	

