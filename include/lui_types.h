#ifndef LUI_TYPES_H
#define LUI_TYPES_H

#ifdef RAYLIB_RENDER
    #include <raylib.h>
#else
    typedef struct Color{unsigned char r,g,b,a;}Color;
#endif

typedef enum{WIDGET,CONTAINER,WINDOWN}ElementType;
typedef enum{Label}WidgetType;

typedef struct l_box{
    int x,y,w,h;
}l_box;

typedef struct {
    char* text;
    int fontSize;
}l_text;

//ELEMENTS @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//WIDGET @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

typedef struct l_widget l_widget;
typedef struct l_container l_container;
typedef struct l_windown l_windown;

struct l_widget{
    l_box box;
    Color background_color;
    WidgetType type;
    void* data;
    l_container* parent;
};

typedef struct {
    l_text textData;
}w_label;

//CONTAINER @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

struct l_container{
    l_box box;
    Color background_color;
    l_widget** widgets; 
    int n_widgets, max_widgets;
    l_windown* parent;
};

//WINDOWN @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

struct l_windown{
    l_box area;
    Color background_color;
    l_container **containers;
    int n_containers,max_containers;
};

size_t lt_get_Widget_type_size(WidgetType type);

#endif