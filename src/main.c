#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include "../include/lui_core.h"
#include "../include/lui_draw.h"
#define OFFWHITE CLITERAL(Color){215,215,215,255}

int main(){
    int winXs = 640;
    int winYs = 480;


    InitWindow(winXs,winYs,"LUI_LIB");
    l_box caixa = {50,50,200,150};
    container* cont = lc_container_init(caixa);
    widget* w = lc_widget_init((l_box){60,60,120,90});
    w->background_color = BLUE;

    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);

        l_draw_container(cont);
        l_draw_widget(w);

        EndDrawing();
    }
    
    lc_free_container(&cont);

    CloseWindow();
    return 0;
}