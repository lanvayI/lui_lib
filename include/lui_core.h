#ifndef LUI_CORE_H
#define LUI_CORE_H

typedef struct Color; //just for raylib implemation

typedef struct l_box{
    int x,y,w,h;
}l_box;

typedef struct{
    l_box box;
    Color background_color;
}widget;

typedef struct{
    l_box box;
    Color background_color;
    widget** widgets;
    int n_widgets, max_widgets;
}container;

typedef struct{
    l_box area;
    container **containers;
    int n_containers,max_containers;
}l_windown;


void* lc_malloc(size_t size);

widget* lc_widget_init(l_box area);
void lc_free_widget(widget** widgetPtr);

container* lc_container_init(l_box area); // widgets and backgroud color added later
void lc_free_container(container** containerPtr);

#endif