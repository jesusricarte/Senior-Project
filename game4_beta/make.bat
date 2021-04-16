echo off

C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -c -o main.o main.c
C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wl-yt0x01 -Wl-yo4 -o main.gb main.o

rem -Wl-yp0x143=0x80