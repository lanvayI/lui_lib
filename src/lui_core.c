#include <stdlib.h>
#include <stdio.h>
#include <raylib.h>
#include "../include/lui_core.h"

Color defaultWidgetColor = BLUE; //later make go invisible
Color defaultContainerColor = GRAY;
Color defaultWindownColor = RAYWHITE;
int defaultWidgetsListSize = 5;
int defaultContainerListSize = 5;

void* lc_malloc(size_t size){
    return malloc(size);
}

//##################################


l_widget* lc_widget_init(l_box area){
    l_widget* wd = malloc(sizeof(l_widget));
    if(wd==NULL){DEB("lui_core : lc_widget_init : failed to malloc widget");
    return NULL;}

    wd->box = area;
    wd->background_color = defaultWidgetColor;
    return wd;
}

void lc_free_widget(l_widget** widgetPtr){
    if(*widgetPtr == NULL){return;}
    free(*widgetPtr);
    DEB("lui_core : lc_free_widget : sucess");
}

l_container* lc_container_init(l_box area){
    l_container* co = lc_malloc(sizeof(l_container));
    if(co==NULL){DEB("lui_core : lui_core_container_init : failed to malloc contaier")
    ;return NULL;}

    l_widget** wids = lc_malloc(sizeof(l_widget*)*defaultWidgetsListSize);
    if(wids==NULL){free(co); DEB("lui_core : lui_core_container_init : failed to malloc widget double pointer");
    return NULL;}

    co->box = area;
    co->background_color = defaultContainerColor;
    co->widgets = wids;
    co->n_widgets = 0;
    co->max_widgets = defaultWidgetsListSize;
    DEB("lui_core : lui_core_container_init : sucess");
    return co;
}

int lc_container_insert_widget(l_container* containerPtr, l_widget* widgetPtr){
    if(containerPtr == NULL){DEB("lui_core : lc_container_insert_widget : container ptr null"); return 0;}
    if(widgetPtr == NULL){DEB("lui core : lc_container_insert_widget : widget ptr null"); return 0;}

    containerPtr->widgets[containerPtr->n_widgets++] = widgetPtr;
    DEB("lui core : lc_container_insert_widget : sucess");
    return 1;
}


void lc_free_container(l_container** containerPtr){
    if(containerPtr==NULL){return;}
    free((*containerPtr)->widgets);
    free(*containerPtr);
    *containerPtr = NULL;
    DEB("lui_core : lc_free_container : sucess");
}

l_windown* lc_windown_init(l_box area){
    l_windown* win = lc_malloc(sizeof(l_windown));
    if(win==NULL){DEB("lui_core : lui_core_windown_init : failed to malloc windown")
    ;return NULL;}

    l_container** conts = lc_malloc(sizeof(l_container*)*defaultContainerListSize);
    if(conts==NULL){free(win); DEB("lui_core : lui_core_windown_init : failed to malloc container double pointer");
    return NULL;}

    win->area = area;
    win->background_color = defaultWindownColor;
    win->containers = conts;
    win->n_containers = 0;
    win->max_containers = defaultContainerListSize;
    DEB("lui_core : lui_core_windown_init : sucess");
    return win;
}

int lc_windown_insert_container(l_windown* windownPtr, l_container* l_containerPtr){
    if(windownPtr == NULL){DEB("lui_core : lc_windown_insert_container : windown ptr null"); return 0;}
    if(l_containerPtr == NULL){DEB("lui core : lc_windown_insert_container : container ptr null"); return 0;}

    windownPtr->containers[windownPtr->n_containers++] = l_containerPtr;
    DEB("lui core : lc_windown_insert_container : sucess");
    return 1;
}

void lc_free_windown(l_windown** windownPtr){
    if(windownPtr==NULL){return;}
    free((*windownPtr)->containers);
    free(*windownPtr);
    *windownPtr = NULL;
    DEB("lui_core : lc_free_windown : sucess");
}
