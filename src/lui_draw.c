#include <stdlib.h>
#include <stdio.h>
#include <raylib.h>
#include "../include/lui_core.h"
#include "../include/lui_draw.h"


void l_draw_box(l_box* box,Color color){
    if(box==NULL){return;}
    DrawRectangle(box->x,box->y,box->w,box->h,color);
}

void l_draw_widget(widget* widgetPtr){
    if(widgetPtr==NULL){DEB("lui_draw : l_draw_widget : widget ptr null");
        return;}
    l_draw_box(&widgetPtr->box,widgetPtr->background_color);
}

//CONTAIENER
//Draw only the container area
void l_draw_container(container *containerPtr){
    if(containerPtr==NULL){return;}
    l_draw_box(&containerPtr->box,containerPtr->background_color);
}

void l_draw_widget_with_param(l_box* box, Color color, int startX, int startY){
    if(box==NULL){return;}
    box->x += startX;
    box->y += startY;
    DrawRectangle(box->x,box->y,box->w,box->h,color);
}

void l_draw_container_widgets(container* containerPtr){
    if(containerPtr==NULL){DEB("lui_draw : l_draw_container_widget : container ptr null");
        return;}
    int startX = containerPtr->box.x;
    int startY = containerPtr->box.y;

    widget* widgetptr = NULL;
    l_box box = {0,0,0,0};
    for(int i=0; i < containerPtr->n_widgets;i++){
        widgetptr = containerPtr->widgets[i];
        if(widgetptr==NULL){continue;}

        box = widgetptr->box;
        l_draw_widget_with_param(&box,widgetptr->background_color,startX,startY);
    }
}