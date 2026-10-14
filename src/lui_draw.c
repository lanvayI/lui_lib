#include <stdlib.h>
#include <raylib.h>
#include "../include/lui_core.h"
#include "../include/lui_draw.h"


void l_draw_box(l_box* box,Color color){
    if(box==NULL){return;}
    DrawRectangle(box->x,box->y,box->w,box->h,color);
}

void l_draw_container(container *p){
    if(p==NULL){return;}
    l_draw_box(&p->box,p->background_color);
}

void l_draw_widget(widget* w){
    if(w==NULL){return;}
    l_draw_box(&w->box,w->background_color);
}