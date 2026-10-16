#ifndef LUI_LAYOUT_H
#define LUI_LAYOUT_H

#include "lui_types.h"

void lt_align_center_boxs(l_box* source, l_box* toBeAligned);
void lt_align_center(l_windown* windownPtr);

int lt_is_widget_inside_container(l_container* containerPtr, l_widget* widgetPtr);
int lt_is_container_inside_windown(l_windown* windownPtr, l_container* containerPtr);


#endif