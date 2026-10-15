#ifndef LUI_DRAW_H
#define LUI_DRAW_H

void l_draw_box(l_box* box,Color color);
void l_draw_widget(widget* widgetPtr);
void l_draw_widget_with_param(l_box* box, Color color, int startX, int startY); //draw widget but, add startx and starty to lbox x and y variables
void l_draw_container(container *containerPtr);
void l_draw_container_widgets(container* containerPtr);

#endif