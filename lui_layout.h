#ifndef LUI_LAYOUT_H
#define LUI_LAYOUT_H

#include "lui_types.h"

typedef enum{TOP,BOTTOM,LEFT,RIGHT,CENTER}AlignmentType;

void lt_align_box(l_box* source, l_box* toBeAligned,AlignmentType AlignmentType);
void lt_align_center(l_windown* windownPtr);

int lt_is_widget_inside_container(l_container* containerPtr, l_widget* widgetPtr);
int lt_is_container_inside_windown(l_windown* windownPtr, l_container* containerPtr);


#endif