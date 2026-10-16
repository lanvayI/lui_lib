#include <stdlib.h>
#include <stdio.h>
#include <raylib.h>
#define RAYLIB_RENDER
#include "../include/lui_core.h"
#include "../include/lui_draw.h"


void l_draw_box(l_box* box,Color color){
    if(box==NULL){return;}
    DrawRectangle(box->x,box->y,box->w,box->h,color);
}

//widget

void l_draw_widget(l_widget* widgetPtr){
    if(widgetPtr==NULL){DEB("lui_draw : l_draw_widget : widget ptr null");
        return;}
    l_draw_box(&widgetPtr->box,widgetPtr->background_color);
}

//CONTAIENER
//Draw only the container area

void l_draw_container(l_container *containerPtr){
    if(containerPtr==NULL){return;}
    l_draw_box(&containerPtr->box,containerPtr->background_color);
}

void l_draw_container_widgets(l_container* containerPtr){
    if(containerPtr==NULL){DEB("lui_draw : l_draw_container_widget : container ptr null");
        return;}
    if(containerPtr->n_widgets == 0){return;}
    l_widget* widgetptr = NULL;
    for(int i=0; i < containerPtr->n_widgets;i++){
        widgetptr = containerPtr->widgets[i];
        if(widgetptr==NULL){continue;}
        l_draw_widget(widgetptr);
    }
}

//windown

void l_draw_windown(l_windown* windownPtr){
    if(windownPtr==NULL){DEB("lui_draw : l_draw_windown : windown pointer null");return;}
    l_draw_box(&windownPtr->area,windownPtr->background_color);
}


void l_draw_windown_containers(l_windown* windownPtr){
    if(windownPtr==NULL){DEB("lui_draw : l_draw_windown_containers : windown ptr null");
        return;}

    l_container* containerPtr = NULL;
    for(int i=0; i < windownPtr->n_containers;i++){
        containerPtr = windownPtr->containers[i];
        if(containerPtr==NULL){continue;}
        l_draw_container(containerPtr);
        l_draw_container_widgets(containerPtr);
    }
}

void l_draw_windown_all_childs(l_windown* windownPtr){
    if(windownPtr==NULL){DEB("lui_draw : l_draw_windown_all_childs : windown ptr null"); return;}
    l_draw_windown(windownPtr);
    l_draw_windown_containers(windownPtr);
}