#ifndef LUI_DRAW_H
#define LUI_DRAW_H

void l_draw_box(l_box* box,Color color);
void l_draw_brow_padding(l_box* box, Color color, int paddingX, int paddingY);

void l_draw_widget(l_widget* widgetPtr); //brute draw
void l_draw_widget_with_param(l_widget* widgetPtr, int paddingX, int paddingY); 

void l_draw_container(l_container *containerPtr); //brute draw
void l_draw_container_with_param(l_container *containerPtr,int paddingX, int paddingY);
void l_draw_container_widgets(l_container* containerPtr);

void l_draw_windown(l_windown* windownPtr);
void l_draw_windown_containers(l_windown* windownPtr);
void l_draw_windown_all_childs(l_windown* windownPtr); //draw windown, draw containers and containers widgets

#endif