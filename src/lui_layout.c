#include <stdlib.h>
#include <raylib.h>
#include "../include/lui_core.h"
#include "../include/lui_layout.h"

int lt_is_widget_inside_container(l_container* containerPtr, l_widget* widgetPtr){
    if(containerPtr==NULL){DEB("lui_layout : lt_is_widgets_inside_container : container ptr null");return 0;}
    if(widgetPtr==NULL){DEB("lui_layout : lt_is_widgets_inside_container : widget ptr null");return 0;}
    if(containerPtr->n_widgets==0){DEB("lui_layout : lt_is_widgets_inside_container : nothing to search"); return 0;}

    l_box contBox = containerPtr->box;
    l_box widBox = widgetPtr->box;

    if(widBox.x > contBox.x || widBox.x + widBox.w < contBox.x + contBox.w ||
    widBox.y > contBox.y || widBox.y + widBox.h < contBox.y + contBox.h){
        return 1;
    }

    return 0;
}

int lt_is_container_inside_windown(l_windown* windownPtr, l_container* containerPtr){
    if(windownPtr==NULL){DEB("lui_layout : lt_is_container_inside_windown : windown ptr null");return 0;}
    if(containerPtr==NULL){DEB("lui_layout : lt_is_container_inside_windown : container ptr null");return 0;}
    if(windownPtr->containers==0){DEB("lui_layout : lt_is_container_inside_windown : nothing to search"); return 0;}

    // yea too lazy to change
    l_box contBox = windownPtr->area;
    l_box widBox = containerPtr->box;

    if(widBox.x > contBox.x || widBox.x + widBox.w < contBox.x + contBox.w ||
    widBox.y > contBox.y || widBox.y + widBox.h < contBox.y + contBox.h){
        return 1;
    }

    return 0;
}

void lt_align_center_boxs(l_box* source, l_box* toBeAligned){
    if(source==NULL){DEB("lui_layout : lt_align_center_boxs : source ptr null"); return;}
    if(toBeAligned==NULL){DEB("lui_layout : lt_align_center_boxs : toBeAligned ptr null"); return;}
    
    int xCenter = (source->x + source->w)/2;
    int yCenter = (source->y + source->h)/2;

    toBeAligned->x = xCenter - (toBeAligned->w /2);
    toBeAligned->y = yCenter - (toBeAligned->h /2);
}

void lt_align_center(l_windown* windownPtr){
    if(windownPtr==NULL){DEB("lui_layout : lt_align_center : windown ptr null"); return;}
    if(windownPtr->containers == 0){DEB("lui_layout : lt_align_center : nothing to center"); return;}

    l_container* contPtr = NULL;
    for(int i=0; i < windownPtr->n_containers; i++){
        contPtr = windownPtr->containers[i];
        if(contPtr==NULL){continue;}
        lt_align_center_boxs(&windownPtr->area,&contPtr->box);
    }
}