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
    l_box caixa = {0,0,200,200};
    l_windown* win = lc_windown_init((l_box){0,0,500,500});
    l_container* cont = lc_container_init(caixa);
    l_widget* w = lc_widget_init((l_box){0,0,50,50});
    w->background_color = BLUE;

    lc_windown_insert_container(win,cont);
    lc_container_insert_widget(cont,w);
    //lc_container_insert_widget(cont,w2);
    
    lt_align_box(&win->area,&cont->box,TOP);
    lt_align_box(&cont->box,&w->box,TOP);

    l_box box1 = cont->box;
    printf("container x %d y %d w %d h %d\n",box1.x,box1.y,box1.w,box1.h);
    box1 = w->box;
    printf("widget x %d y %d w %d h %d\n",box1.x,box1.y,box1.w,box1.h);
    while (!WindowShouldClose()){
        ///////////
        BeginDrawing();
        ClearBackground(BLACK);

        //l_draw_windown_all_childs(win);
        l_draw_windown(win);
        l_draw_container(cont);
        l_draw_widget(w);

        EndDrawing();
    }
    
    lc_free_container(&cont);
    lc_free_windown(&win);
    CloseWindow();
    return 0;
}