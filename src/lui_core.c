#include <stdlib.h>
#include <stdio.h>
#include <raylib.h>
#include "../include/lui_core.h"

#define LUI_DEBUG 1 // 1 to debug text
#define DEB(x) (LUI_DEBUG ? puts(x) : 0)

Color defaultColor = GRAY; //later make go invisible
int defaultWidgetsListSize = 5;

void* lc_malloc(size_t size){
    return malloc(size);
}

//##################################


widget* lc_widget_init(l_box area){
    widget* wd = malloc(sizeof(widget));
    if(wd==NULL){DEB("lui_core : lc_widget_init : failed to malloc widget");
    return NULL;}

    wd->box = area;
    wd->background_color = defaultColor;
    return wd;
}

void lc_free_widget(widget** widgetPtr){
    if(*widgetPtr == NULL){return;}
    free(*widgetPtr);
    DEB("lui_core : lc_free_widget : sucess");
}

container* lc_container_init(l_box area){
    container* co = lc_malloc(sizeof(container));
    if(co==NULL){DEB("lui_core : lui_core_container_init : failed to malloc contaier")
    ;return NULL;}

    widget** wids = lc_malloc(sizeof(widget*)*defaultWidgetsListSize);
    if(wids==NULL){free(co); DEB("lui_core : lui_core_container_init : failed to malloc widget double pointer");
    return NULL;}

    co->box = area;
    co->background_color = defaultColor;
    co->widgets = wids;
    co->n_widgets = 0;
    co->max_widgets = 5;
    DEB("lui_core : lui_core_container_init : sucess");
    return co;
}

void lc_free_container(container** containerPtr){
    if(containerPtr==NULL){return;}
    free((*containerPtr)->widgets);
    free(*containerPtr);
    *containerPtr = NULL;
    DEB("lui_core : lc_free_container : sucess");
}