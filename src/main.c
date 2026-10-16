#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#define RAYLIB_RENDER
#include "../include/lui_core.h"
#include "../include/lui_draw.h"
#include "../include/lui_layout.h"
#define OFFWHITE CLITERAL(Color){215,215,215,255}

int main(){
    int winXs = 640;
    int winYs = 480;

    InitWindow(winXs,winYs,"LUI_LIB");
    l_box caixa = {100,100,200,150};
    l_windown* win = lc_windown_init((l_box){20,20,600,440});
    l_container* cont = lc_container_init(caixa);
    l_widget* w = lc_widget_init((l_box){0,0,50,50});
    l_widget* w2 = lc_widget_init((l_box){80,95,50,50});
    w->background_color = BLUE;

    lc_windown_insert_container(win,cont);
    lc_container_insert_widget(cont,w);
    //lc_container_insert_widget(cont,w2);
    
    while (!WindowShouldClose()){
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            cont->box.x = GetMouseX();
            cont->box.y = GetMouseY();
        }

        if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT)){
            w->box.x = GetMouseX();
            w->box.y = GetMouseY();
        }
        if(lt_is_widget_inside_container(cont,w)){
            puts("sim");
        }else{puts("nao");}
        ///////////
        BeginDrawing();
        ClearBackground(BLACK);

        l_draw_windown_all_childs(win);
        lt_align_center(win);

        EndDrawing();
    }
    
    lc_free_container(&cont);
    lc_free_windown(&win);
    CloseWindow();
    return 0;
}