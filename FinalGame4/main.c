#include <gb/gb.h>
#include <stdio.h>
#include "sprites.c"
#include "tiles.c"
#include "backgrounds.c"
#include "ai.c"
#include "menupic_data.c"
#include "menupic_map.c"
#include "lvlselect_data.c"
#include "lvlselect_map.c"

UINT8 count=0;
UBYTE playing, joypad_state, debug, level = 1;
UINT16 player_x, player_y, player_z, player_o;
UBYTE badguy_x, badguy_y, badguy_z, badguy_b=0, badguy_i[6];
UBYTE doggo_x=0, doggo_y=0;
UINT8 q,u;
const char blankmap[3] = {0x00, 0x0C, 0x0F};
const unsigned char menughost [] = { 0x00, 0x00, 0x38, 0x04, 0x7C, 0x02, 0xC8, 0x01, 0xDC, 0x15, 0xFC, 0x03, 0xFC, 0x03, 0xB4, 0x03 };
UINT8 menusprite[2];
UINT8 menusprite2[2];



int levelselected= 0;
int selectedsprite;

UINT8 n;
UINT8 deathby;

void update_graphics(void);
void do_gameplay(void);
void update_joypad(void);
void update_badguy(void);
void collision_detection(void);
void draw_title_screen(void);
void load_game_tiles(void);
void vblint(void);
void flipping(UBYTE);
void copymap2(void);
void selectlvl(void);
void menustart(void);
void storytime(void);
UBYTE playermove(UINT8, UINT8);
fixed seed;



void performantdelay(UINT8 numloops){
    UINT8 i;
    for(i=0; i < numloops; i++){
        wait_vbl_done();
    }
}
void selectlvl(void){
HIDE_BKG;
set_bkg_data(0,48, lvlselect_data);
set_bkg_tiles(0,0,20,18, lvlselect_map);
SHOW_BKG;
SHOW_SPRITES;


menusprite[0] = 55;
menusprite[1] = 40;
menusprite2[0] = 105; // second ghost in lvl select
menusprite2[1] = 40;
n = 0;
while(n < 2)
{

  move_sprite(0,menusprite[0],menusprite[1]);
 move_sprite(1,menusprite2[0],menusprite2[1]); //second ghost in lvl select
    if((menusprite[1] == 40) && (joypad() & J_START))
        {
           //printf("LEVEL 1\n");
            n = 2;
            levelselected = 1;
        }
        else  if((menusprite[1] == 64) && (joypad() & J_START))
        {
           //printf("LEVEL 2\n");
            n = 2;
            levelselected = 2;
            move_sprite(0,0,0);
 move_sprite(1,0,0); 
        }
          else  if((menusprite[1] == 88) && (joypad() & J_START))
        {
         
           //printf("LEVEL 3\n");
            n = 2;
            levelselected = 3;
               move_sprite(0,0,0);
               move_sprite(1,0,0); 
        }
    

        if(joypad() & J_UP){
            if(menusprite[1] > 40)

            {

               menusprite[1] -= 24;
               menusprite2[1] -=24; // right ghost
             //printf("%d ",menusprite[1]);
              
            }
        }

        if(joypad() & J_DOWN){
            if(menusprite[1] < 88) {
                menusprite[1] += 24;
                menusprite2[1] +=24; //right ghost
                //printf("%d ",menusprite[1]);
            }
            
        }
        


performantdelay(5);
}


}
void storytime(void){
printf("You Are Trapped\n in this Maze\n filled with ghosts\n and wolves.\nYou Must avoid\nthem and collect\nall the keys!");
}

void menustart(void){
    UINT16 indexTLx, indexTLy, tileindexTL;
    

    indexTLx = (menusprite[0] - 8) / 8;
    indexTLy = (menusprite[1] - 16) / 8;
    tileindexTL = 20 * indexTLy + indexTLx;
    set_bkg_data(0,66, menupic_data);
    set_bkg_tiles(0,0,20,18, menupic_map);
    set_sprite_data(0,0, menughost);
    set_sprite_tile(0,0);  

    menusprite[0] = 55;
    menusprite[1] = 90;
    SHOW_SPRITES;
    SHOW_BKG;
    DISPLAY_ON;

    while(n < 2){
        move_sprite(0,menusprite[0],menusprite[1]);
    
    
    
    
        if(joypad() & J_UP){
            if(menusprite[1] > 90)
            {

               menusprite[1] -= 20;
             //printf("%d ",menusprite[1]);
              n =1;
            }
      
            

        }
         else if((menusprite[1] == 90) && (joypad() & J_START))
        {    HIDE_BKG;
    HIDE_SPRITES;
    //printf("GAME STARTS\n");
            n = 2;
        }
       
        if(joypad() & J_DOWN){
            if(menusprite[1] < 110)
                menusprite[1] += 20;
                //printf("%d ",menusprite[1]);
             n = 1;
            
        }
    else if((menusprite[1] == 110) && (joypad() & J_START))
    {
               HIDE_BKG;
    HIDE_SPRITES;
    
             storytime();
             waitpad(J_START);
            n= 2;
            
    }  

   

  
           performantdelay(6);
          
}
   
}

UBYTE playermove(UINT8 x, UINT8 y){
    UINT16 indexTx,indexTy,indexT;
    UBYTE result;

    indexTx = (x - 8) / 8;
    indexTy = (y - 16) / 8;
    indexT = (20 * indexTy) + indexTx;

    if(debug){
        printf("%u \n",(UINT16)(badguy_z));
        printf("%u %u\n",(UINT16)(x),(UINT16)(y));
        printf("%u %u %u\n",(UINT16)indexTx,(UINT16)indexTy,(UINT16)count);   
    }    
    if(level==1){
        result = map1[indexT] == blankmap[0];

        if(map1[indexT] == 0x0F){
            
            return 2;
        }
    }
    else if(level==2){
        result = map2[indexT] == blankmap[0];

        if(map2[indexT] == 0x0F){
            return 2;
        }
    }
    else if(level==3){
        result = map3[indexT] == blankmap[0];

        if(map3[indexT] == 0x0F){
            return 2;  //32, 24
        }
    }
    else if(level ==4){
        result = map4[indexT] == blankmap[0];

        if(map4[indexT] == 0x0F){
            return 2;
        }
    }
    return result;
}



void main() {
   
    menustart();
    
    selectlvl();
    





    load_game_tiles();
     
    add_VBL(vblint);
    
   //SWITCH_ROM_MBC1((UWORD)0);
   
    //seed.b.l = DIV_REG;
    //SWITCH_ROM_MBC1(3);
    //seed.b.h = DIV_REG;
    //initrand(seed.w);
    //draw_title_screen();
    

    
    
    
   
   
  
	 do_gameplay();

      //reset();
      
   
}

void vblint(void) {
    

    update_graphics();
    
  /*   if(player_z==0){
        if(player_o==0){
            set_sprite_data(0, 1, boy2);
        }
        if(player_o==1){
            set_sprite_data(0, 1, boy1);
        }
    }
    if(player_z==1){
        if(player_o==0){
            set_sprite_data(0, 1, boy3);
        }
        if(player_o==1){
            set_sprite_data(0, 1, boy4);
        }
    } */ //boy flip 
   
}

void update_graphics(void) {
    //disable_interrupts();
    if(levelselected == 1){
    move_sprite(0, player_x, player_y);
    selectedsprite = 0;
    }
    else if(levelselected == 2){
    move_sprite(8, player_x, player_y);
    selectedsprite = 8;
    }
    else if(levelselected ==3){
    move_sprite(9,player_x,player_y);
    selectedsprite = 9;
    }
    else
    {   move_sprite(0, player_x, player_y);
        selectedsprite = 0;
    }
    //move_sprite(1, badguy_x, badguy_y);
    //move_sprite(2, doggo_x, doggo_y);
    //enable_interrupts();
    
}

void update_joypad(void) {    
    joypad_state = joypad();
    if(playing==1){
    if(joypad_state & J_A) {
        player_z = 1;
        debug=1;
    }

    if(joypad_state & J_LEFT) {
        set_sprite_prop(selectedsprite,S_FLIPX);
        player_z = 1;
        if(playermove(player_x - 8, player_y)){
            doggo_x=player_x;
            doggo_y=player_y;
            player_x=player_x - 8;
            move_sprite(selectedsprite, player_x, player_y);
            
            
        }
        if(level==2){
            if(playermove(player_x - 8, player_y)==2){
                doggo_x=player_x;
                doggo_y=player_y;
                player_y=player_y;
                move_sprite(selectedsprite, player_x, player_y);
                set_bkg_tiles(0, 0, 20, 18, map3);
                level=3;
                move_sprite(7, 152, 32);
                player_x=16;
                player_y=32;
                //HIDE_SPRITES;
            }
        }
        if(level==3){
            if(playermove(player_x - 8, player_y)==2){
                doggo_x=player_x - 8;
                doggo_y=player_y;
                player_y=player_y;
                move_sprite(selectedsprite, player_x, player_y);
                set_bkg_tiles(0, 0, 20, 18, map4);
                level=4;
                move_sprite(7, 144, 144);
                player_x=32;
                player_y=144; // x,y for player for the start of map4
                //HIDE_SPRITES;
            }
        }
         
        
    }
    if(joypad_state & J_RIGHT) {
        set_sprite_prop(selectedsprite,0);
        //set_sprite_prop(selectedsprite,~S_FLIPX);
        player_z = 0;
        if(playermove(player_x + 8, player_y)){
            doggo_x=player_x;
            doggo_y=player_y;
            player_x=player_x + 8;
            move_sprite(selectedsprite, player_x, player_y);
        }
       
    }
    if(joypad_state & J_UP) {
        //set_sprite_prop(selectedsprite,0);
        //set_sprite_prop(selectedsprite,S_FLIPY | S_FLIPX);
        player_o = 0;
        if(playermove(player_x, player_y - 8)){
            doggo_x=player_x;
            doggo_y=player_y;
            player_y=player_y - 8;
            move_sprite(selectedsprite, player_x, player_y);
        }
        if(level==1){
            if(playermove(player_x, player_y - 8)==2){
                doggo_x=player_x;
                doggo_y=player_y;
                player_y=player_y - 8;
                move_sprite(selectedsprite, player_x, player_y);
                set_bkg_tiles(0, 0, 20, 18, map2);
                level=2;
                move_sprite(7, 144, 24);
                player_x=8;
                player_y=32;
                //HIDE_SPRITES;
            }
        }
        if(level==4){
            if(playermove(player_x, player_y-8)==2){
                doggo_x=player_x - 8;
                doggo_y=player_y;
                player_y=player_y-8;
                move_sprite(selectedsprite, player_x, player_y);
                set_bkg_tiles(0, 0, 20, 18, NULL); //change map4 
                HIDE_SPRITES;
                //printf("     You Escape\n     The Maze\n     Successfully!");
                printf("You Escape\nThe Maze\nSuccessfully!");
                move_sprite(7, 152, 32);
                player_x=16;
                player_y=32;
                //HIDE_SPRITES;
            }
        }
      
    }
    if(joypad_state & J_DOWN) {
        //set_sprite_prop(selectedsprite,0);
        //set_sprite_prop(selectedsprite,S_FLIPY);
        player_o = 1;
        if(playermove(player_x, player_y + 8)){
            doggo_x=player_x;
            doggo_y=player_y;
            player_y=player_y + 8;
            move_sprite(selectedsprite, player_x, player_y);
        }

     
        
    }
    
    performantdelay(6);
    }
}

void update_badguy(){

    

    /*
    if(badguy_z==1){
        badguy_y=badguy_y+4;
    }
    else{
        badguy_y=badguy_y-4;
    }
    if(badguy_y>145){
        badguy_z=0;
        set_sprite_prop(1,S_FLIPY);
    }
    if(badguy_y<35){
        badguy_z=1;
        set_sprite_prop(1,~S_FLIPY & S_FLIPX);//
    }
    */

        
}

void collision_detection(){

    
    if(level==1){
    badguy_i[0]=(count/2)%14;
    badguy_i[1]=(count/2)%16;
    badguy_i[2]=(count/2)%28;
    badguy_i[3]=(count/2)%14;
    badguy_i[4]=(count/2)%12;
    badguy_i[5]=(count/2)%16;

    //door changer
        if(player_y > 104 - 8) {
            if(player_y < 104 + 8) {
                if(player_x > 16 - 8) {
                    if(player_x < 16 + 8) {
                        

                    //enter here you found a key
                        map1[20+8]=blankmap[0];
                        set_bkg_tiles(0, 0, 20, 18, map1);
                        move_sprite(7, 0, 0);
                        //playing=0;
                        
                    }
                }
            }
        }
    
    for(q=0; q < 3; q++){
        
        if(player_y > badguy1_ai[q][1][badguy_i[q]] - 8) {
            if(player_y < badguy1_ai[q][1][badguy_i[q]] + 8) {
                if(player_x > badguy1_ai[q][0][badguy_i[q]] - 8) {
                    if(player_x < badguy1_ai[q][0][badguy_i[q]] + 8) {
                        playing = 0;
                        //delay(10000);
                    }
                }
            }
        }

        if(player_y > badguy2_ai[q][1][badguy_i[q+3]] - 8) {
            if(player_y < badguy2_ai[q][1][badguy_i[q+3]] + 8) {
                if(player_x > badguy2_ai[q][0][badguy_i[q+3]] - 8) {
                    if(player_x < badguy2_ai[q][0][badguy_i[q+3]] + 8) {
                        playing = 0;
                        //delay(10000);
                    }
                }
            }
        }
            move_sprite(q+1, badguy1_ai[q][0][badguy_i[q]], badguy1_ai[q][1][badguy_i[q]]);

        
            move_sprite(q+4, badguy2_ai[q][0][badguy_i[q+3]], badguy2_ai[q][1][badguy_i[q+3]]);
        
    }




    badguy_z=badguy1_ai[0][3][badguy_i[0]];

    if(badguy_z==0){
        if(player_y > badguy1_ai[0][1][badguy_i[0]] - 8) {
            if(player_y < badguy1_ai[0][1][badguy_i[0]] + 8) {
                if(player_x > badguy1_ai[0][0][badguy_i[0]] - 8) {
                    if(player_x < badguy1_ai[0][0][badguy_i[0]] + (badguy1_ai[0][2][badguy_i[0]]*8)) {
                        playing = 0;
                        deathby = 1;
                        //delay(1000);
                    }
                }
            }
        }
    }

    if(badguy_z==2){
        if(player_y > badguy1_ai[0][1][badguy_i[0]] - 8) {
            if(player_y < badguy1_ai[0][1][badguy_i[0]] + 8) {
                if(player_x > badguy1_ai[0][0][badguy_i[0]] - (badguy1_ai[0][2][badguy_i[0]]*8)) {
                    if(player_x < badguy1_ai[0][0][badguy_i[0]] + 8) {
                        playing = 0;
                        deathby = 1;
                        //delay(1000);
                    }
                }
            }
        }
    }

    if(badguy_z==3){
        if(player_y > badguy1_ai[0][1][badguy_i[0]] - 8) {
            if(player_y < badguy1_ai[0][1][badguy_i[0]] + (badguy1_ai[0][2][badguy_i[0]]*8)) {
                if(player_x > badguy1_ai[0][0][badguy_i[0]] - 8) {
                    if(player_x < badguy1_ai[0][0][badguy_i[0]] + 8) {
                        playing = 0;
                        deathby = 1;
                        //delay(1000);
                    }
                }
            }
        }
    }
    

    if(badguy_z==1){
        if(player_y > badguy1_ai[0][1][badguy_i[0]] - (badguy1_ai[0][2][badguy_i[0]]*8)) {
            if(player_y < badguy1_ai[0][1][badguy_i[0]] + 8) {
                if(player_x > badguy1_ai[0][0][badguy_i[0]] - 8) {
                    if(player_x < badguy1_ai[0][0][badguy_i[0]] + 8) {
                        playing = 0;
                        deathby = 1;
                        //delay(1000);
                    }
                }
            }
        }
    }
    
}

else if(level==2){
    badguy_i[0]=(count/2)%20;
    badguy_i[1]=(count/2)%14;
    badguy_i[2]=((count/2)+10)%20;
    badguy_i[3]=(count/2)%22;
    badguy_i[4]=(count/2)%12;
    badguy_i[5]=(count/2)%24;

    //door changer
    
        if(player_y > 24 - 8) {
            if(player_y < 24 + 8) {
                if(player_x > 144 - 8) {
                    if(player_x < 144 + 8) {
                        map2[(10*20)+15]=blankmap[0];
                        set_bkg_tiles(0, 0, 20, 18, map2);
                        move_sprite(7, 0, 0);
                        
                    }
                }
            }
        }
    
    for(q=0; q < 3; q++){
        
        if(player_y > badguy3_ai[q][1][badguy_i[q]] - 8) {
            //deathby = 1;
            if(player_y < badguy3_ai[q][1][badguy_i[q]] + 8) {
                if(player_x > badguy3_ai[q][0][badguy_i[q]] - 8) {
                    if(player_x < badguy3_ai[q][0][badguy_i[q]] + 8) {
                        playing = 0;
                        //delay(1000);
                    }
                }
            }
        }

        if(player_y > badguy4_ai[q][1][badguy_i[q+3]] - 8) {
            if(player_y < badguy4_ai[q][1][badguy_i[q+3]] + 8) {
                if(player_x > badguy4_ai[q][0][badguy_i[q+3]] - 8) {
                    if(player_x < badguy4_ai[q][0][badguy_i[q+3]] + 8) {
                        playing = 0;
                        //delay(1000);
                    }
                }
            }
        }
            move_sprite(q+1, badguy3_ai[q][0][badguy_i[q]], badguy3_ai[q][1][badguy_i[q]]);

        
            move_sprite(q+4, badguy4_ai[q][0][badguy_i[q+3]], badguy4_ai[q][1][badguy_i[q+3]]);
        
    }





    
}

else if(level==3){
    badguy_i[0]=(count/2)%6;
    badguy_i[1]=(count/2)%10;
    badguy_i[2]=(count/2)%14;
    badguy_i[3]=(count/2)%18;
    badguy_i[4]=(count/2)%18;
    badguy_i[5]=(count/2)%16;

    //door changer
    
        if(player_y > 32 - 8) {
            if(player_y < 32 + 8) {  //144,24
                if(player_x > 152 - 8) {
                    if(player_x < 152 + 8) {
                        map3[(1*20)+5]=blankmap[0];  //(1*20)+5
                        set_bkg_tiles(0, 0, 20, 18, map3);
                        move_sprite(7, 0, 0);
                        
                    }
                }
            }
        }
    
    for(q=0; q < 3; q++){
        
        if(player_y > badguy5_ai[q][1][badguy_i[q]] - 8) {
            //deathby = 1;
            if(player_y < badguy5_ai[q][1][badguy_i[q]] + 8) {
                if(player_x > badguy5_ai[q][0][badguy_i[q]] - 8) {
                    if(player_x < badguy5_ai[q][0][badguy_i[q]] + 8) {
                        playing = 0;
                        //delay(1000);
                    }
                }
            }
        }  

        if(player_y > badguy6_ai[q][1][badguy_i[q+3]] - 8) {
            if(player_y < badguy6_ai[q][1][badguy_i[q+3]] + 8) {
                if(player_x > badguy6_ai[q][0][badguy_i[q+3]] - 8) {
                    if(player_x < badguy6_ai[q][0][badguy_i[q+3]] + 8) {
                        playing = 0;
                        //delay(1000);
                    }
                }
            }
        }
            move_sprite(q+1, badguy5_ai[q][0][badguy_i[q]], badguy5_ai[q][1][badguy_i[q]]);

        
            move_sprite(q+4, badguy6_ai[q][0][badguy_i[q+3]], badguy6_ai[q][1][badguy_i[q+3]]);
        
    }


    


    
}
else if(level==4){
    badguy_i[0]=(count/2)%26;
    badguy_i[1]=(count/2)%12;
    badguy_i[2]=(count/2)%10;
    badguy_i[3]=(count/2)%16;
    badguy_i[4]=(count/2)%14;
    badguy_i[5]=(count/2)%24;

    //door changer
    
        if(player_y > 144 - 8) {
            if(player_y < 144 + 8) {
                if(player_x > 144 - 8) {
                    if(player_x < 144 + 8) {
                        map4[28]=blankmap[0];
                        set_bkg_tiles(0, 0, 20, 18, map4);
                        move_sprite(7, 0, 0);
                        
                    }
                }
            }
        }
    
    for(q=0; q < 3; q++){
        
        if(player_y > badguy7_ai[q][1][badguy_i[q]] - 8) {
            //deathby = 1;
            if(player_y < badguy7_ai[q][1][badguy_i[q]] + 8) {
                if(player_x > badguy7_ai[q][0][badguy_i[q]] - 8) {
                    if(player_x < badguy7_ai[q][0][badguy_i[q]] + 8) {
                        playing = 0;
                        //delay(1000);
                    }
                }
            }
        }  

        if(player_y > badguy8_ai[q][1][badguy_i[q+3]] - 8) {
            
            if(player_y < badguy8_ai[q][1][badguy_i[q+3]] + 8) {
                if(player_x > badguy8_ai[q][0][badguy_i[q+3]] - 8) {
                    if(player_x < badguy8_ai[q][0][badguy_i[q+3]] + 8) {
                        playing = 0;
                        //delay(1000);
                    }
                }
            }
        }
            move_sprite(q+1, badguy7_ai[q][0][badguy_i[q]], badguy7_ai[q][1][badguy_i[q]]);

        
            move_sprite(q+4, badguy8_ai[q][0][badguy_i[q+3]], badguy8_ai[q][1][badguy_i[q+3]]);
        
    }


    


    
}

count++;

}

void do_gameplay(void) {
  
    playing = 1;
    player_x = 32;
    player_y = 144;
    player_z = 0;
    player_o = 0;
    
    //badguy_x= (GRAPHICS_WIDTH / 5)*3;
    //badguy_y= 32;//145
    //badguy_z= 1;

    while(playing == 1) {
             
          update_joypad();
        update_badguy();
    
        collision_detection();  
      
        
    }
    delay(1000);
    HIDE_SPRITES;
    set_bkg_tiles(0, 0, 20, 18, NULL);

    if(deathby == 1)
    {
    printf("  The Wolf has seen\n  you,and has ripped   you apart.\n    Press Start.\n");
    }
    else
    {
    printf(" A GHOST KILLED YOU!\n\n\n\n     Press Start.\n");
    }
    waitpad(J_START);

    reset();
}

void load_game_tiles(void) {
    wait_vbl_done();

    DISPLAY_OFF;

 
    
    set_bkg_data(0,18,bubbles);
    if(level == 1 )
    {
 set_bkg_tiles(0, 0, 20, 18, map1);
    }
    else if(level == 2)
    {
        set_bkg_tiles(0, 0, 20, 18, map2);
    }
     else if(level == 3)
    {
        set_bkg_tiles(0, 0, 20, 18, map3);
    }
    else if(level == 4)
    {
    
    set_bkg_tiles(0, 0, 20, 18, map4);
    }
   
    set_sprite_data(0, 1, boy1);
    set_sprite_data(1, 1, doggo);
    set_sprite_data(2, 1, Ghost);
    set_sprite_data(3, 1, key);
    set_sprite_data(4,1, bloke);
    set_sprite_data(5,1, amongus);
    //set_sprite_data(2,1, doggo );
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 1);
    set_sprite_tile(2, 2);
    set_sprite_tile(3, 2);
    set_sprite_tile(4, 2);
    set_sprite_tile(5, 2);
    set_sprite_tile(6, 2);
    set_sprite_tile(7, 3);
    set_sprite_tile(8, 4); //bloke
    set_sprite_tile(9,5); // among us
    move_sprite(7, 16, 104); //key map1
    //set_sprite_tile(2,2);
    //SPRITES_8x8;
    SHOW_SPRITES;
    SHOW_BKG;
    DISPLAY_ON;
}
