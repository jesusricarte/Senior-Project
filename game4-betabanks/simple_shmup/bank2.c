#include <gb/gb.h>
#include <stdio.h> 


extern unsigned char map1[];
extern unsigned char map2[];
extern unsigned char map3[];
extern unsigned char map4[];
UBYTE badguy1_ai[3][4][30] = {
    {
        {136, 136, 136, 136, 136, 136, 128, 120, 120, 120, 120, 120, 120, 128},
        {48,  56,  64,  72,  80,  88,  88,  88,  80,  72,  64,  56,  48,  48 },
        {1,   11,  10,  9,   8,   3,   2,   1,   5,   4,   3,   2,   3,   2  },
        {3,   3,   3,   3,   3,   2,   2,   1,   1,   1,   1,   1,   0,   0  }
    },

    {
        {136, 136, 136, 136, 136, 136, 128, 120, 112, 112, 112, 120, 120, 120, 120, 128},
        {96,  104, 112, 120, 128, 136, 136, 136, 136, 128, 120, 120, 112, 104, 96,  96}
    },

    {
        {152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152},
        {144, 136, 128, 120, 112, 104, 96,  88,  80,  72,  64,  56,  48,  40,  32,  40,  48,  56,  64,  72,  80,  88,  96,  104, 112, 120, 128, 136}
    }


};
UBYTE badguy2_ai[3][2][30] = {

    {
        {56,  64,  72,  80,  88,  96,  96,  96,  88,  80,  72,  64,  56,   56},
        {112, 112, 112, 112, 112, 112, 120, 128, 128, 128, 128, 128, 128,  120}
    },

    {
        {16,  24,  32,  32,  32,  24,  16,  24,  32,  32,  32,  24},
        {128, 128, 128, 120, 112, 112, 112, 112, 112, 120, 128, 128}
    },

    {
        {40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40},
        {48,  56,  64,  72,  80,  88,  96,  104, 112, 104, 96,  88,  80,  72,  64,  56}
    }


};

UBYTE badguy3_ai[3][4][30] = {
    {
        {40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40},
        {24,  32,  40,  48,  56,  64,  72,  80,  88,  96,  104, 96,  88,  80,  72,  64,  56,  48,  40,  32},
        {1,   11,  10,  9,   8,   3,   2,   1,   5,   4,   3,   2,   3,   2  },
        {3,   3,   3,   3,   3,   2,   2,   1,   1,   1,   1,   1,   0,   0  }
    },

    {
        {128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128},
        {24,  32,  40,  48,  56,  64,  72,  80,  72,  64,  56,  48,  40,  32}
    },

    {
        {152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152},
        {24,  32,  40,  48,  56,  64,  72,  80,  88,  96,  104, 96,  88,  80,  72,  64,  56,  48,  40,  32}
    }


};
UBYTE badguy4_ai[3][2][30] = {

    {
        {16, 16, 16, 16, 16, 16, 16,  16,  16,  16,  16,  16,  16, 16, 16, 16, 16, 16,16,16,16,16},
        {56, 64, 72, 80, 88, 96, 104, 112, 120, 128, 136, 144, 136,128,120,112,104,96,88,80,72,64}
    },

    {
        {32,  40,  48,  56,  56,  56,  56,  48,  40, 32, 32,  32}, //map2 bot left ghost x
        {136, 136, 136, 136, 128, 120, 112, 112, 112,112, 120, 128} //map2 left ghost y
    },

    {
        {72,   80,  88,   96,  104,  112,  120,  128,  136,  136, 136,  136,  136,  128,120,  112,  104,96, 88, 80, 72, 72,72,72},
        {112,  112, 112,  112, 112,  112,  112,  112,  112,  120, 128,  136,  144,  144,144,  144,  144,144,144,144,144,136,128,120}
    }


};

UBYTE badguy5_ai[3][4][30] = {
    {
        { 144, 144, 144, 144, 144, 144},
        { 48,  40,  32,  24,  32,  40},
        //{1,   11,  10,  9,   8,   3,   2,   1}, //dog
        //{4,   3,   3,   3,   3,   2,   2,   1}
    },

    {
        {80,   88,   96,   104,  112,  120,  112,  104,  96, 88 , 80},
        {128,  128,  128,  128,  128,  128,  128,  128, 128, 128, 128} //bottom right 
    },

    {
        {136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136 ,136},
        {144,  136, 128, 120, 112,104, 96,  88,  96,  104, 112, 120, 128, 136}  //right 
    }


};

UBYTE badguy6_ai[3][2][30] = { //map3

    {
        {24, 24, 24, 24, 24,  24,  24,  24,  24,  24,  24, 24, 24, 24, 24, 24,24,24},
        {72, 80, 88, 96, 104, 112, 120, 128, 136, 144, 136,128,120,112,104,96,88,80}
    },

    {
        {  56,56,  56,  56,  56,  56,  56,  56,  56,56, 56, 56,  56,  56,  56,  56,  56,56},
        {  24,32,  40,  48,  56,  64,  72,  80,  88,96, 88, 80,  72,  64,  56,  48,  40,32} 
    },

    {
        {72,80,88,96,104,112,112,112,112,104,96,88,80,72,72,72},
        {72,72,72,72,72, 72, 80, 88, 96, 96, 96,96,96,96,88,80}
    }


};

UBYTE badguy7_ai[3][4][30] = { // map4
    {
        { 136, 136, 136, 136, 136, 136,136,136,136,136,136,136,136,128,128,136,136,136,136,136,136,136,136,136,136,136},
        { 24,  32,  40,  48,  56 , 62, 70, 78, 86, 92, 100,108,116,116,108,108,100,92, 86 ,78, 70 ,62, 56, 48, 40, 32},
        //{1,   11,  10,  9,   8,   3,   2,   1}, //dog
        //{4,   3,   3,   3,   3,   2,   2,   1}
    },

    {
        {120,  128,  136,  136,  136,  136,136,  128, 120, 120,120,120},
        {24 ,  24 ,  24 ,  32 ,  40 ,  48 ,56,  56,  56,  48, 40,32} //top right
    },

    {
        {24, 24,    24,  24,  24, 24, 24,   24,  24,  24},
        {64, 56,    48,  40,  32, 24, 32,   40,  48,  56}  //top left
    }


};

UBYTE badguy8_ai[3][2][30] = { //map4

    {
        {24, 24, 24, 24,  24,  24,  24,  24,  24,  24, 24, 24, 24, 24, 24,24},
        {80, 88, 96, 104, 112, 120, 128, 136, 144, 136,128,120,112,104,96,88}
    }, // first ghost

    {
        {  48,  48,  48,  48,  48,  48,  48,48, 48, 48,  48,  48,  48,  48},
        {  40,  48,  56,  64,  72,  80,  88,96, 88, 80,  72,  64,  56,  48} 
    }, // second ghost

    {
        {48,56,  64, 72, 80 ,80 , 88 ,96, 104,112,112,112,112,104,96,88,80,   80, 72, 64, 56,48  ,48 ,48},
        {112,112,112,112,120,128, 136,136,136,136,128,120,112,112,112,112,120,128,136,136,136,136,128,120},
    } // 8figure ghost


};
 

const char blankmap[3] = {0x00, 0x0C, 0x0F};
UINT8 count=0;
UBYTE playing, joypad_state, debug, level = 1;
UINT16 player_x, player_y, player_z, player_o;
UBYTE badguy_x, badguy_y, badguy_z, badguy_b=0, badguy_i[6];
UBYTE doggo_x=0, doggo_y=0;
UINT8 q,u;
const int selectedsprite = 0;

void performantdelay(UINT8 numloops){
    UINT8 i;
    for(i=0; i < numloops; i++){
        wait_vbl_done();
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

void update_graphics(void) {
    //disable_interrupts();
  
    move_sprite(0, player_x, player_y);

    //move_sprite(1, badguy_x, badguy_y);
    //move_sprite(2, doggo_x, doggo_y);
    //enable_interrupts();
    
}
void update_joypad(void){
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
         if(level==4){
            if(playermove(player_x - 8, player_y)==2){
                doggo_x=player_x - 8;
                doggo_y=player_y;
                player_y=player_y;
                move_sprite(selectedsprite, player_x, player_y);
                set_bkg_tiles(0, 0, 20, 18, map4); //change map4 
                level=5;
                move_sprite(7, 152, 32);
                player_x=16;
                player_y=32;
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

    //ye
}

/* void collision_detection(){

    
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
                        //delay(1000);
                    }
                }
            }
        }
    }
    
}
count ++;
}
 */

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
    badguy_i[5]=(count/2)%17;

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
    
        if(player_y > 24 - 8) {
            if(player_y < 24 + 8) {
                if(player_x > 144 - 8) {
                    if(player_x < 144 + 8) {
                        map4[(1*20)+5]=blankmap[0];
                        set_bkg_tiles(0, 0, 20, 18, map4);
                        move_sprite(7, 0, 0);
                        
                    }
                }
            }
        }
    
    for(q=0; q < 3; q++){
        
        if(player_y > badguy7_ai[q][1][badguy_i[q]] - 8) {
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
        
        //delay(10);
        
    }
    delay(1000);
    reset();
    

}