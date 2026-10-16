#ifndef LUI_CORE_H
#define LUI_CORE_H

int puts(const char *_Str);
#define LUI_DEBUG 1 // 1 to debug text
#define DEB(x) (LUI_DEBUG ? puts(x) : 0)

#include "lui_types.h"

void* lc_malloc(size_t size);

l_widget* lc_widget_init(l_box area);
void lc_free_widget(l_widget** widgetPtr);

l_container* lc_container_init(l_box area); // widgets and backgroud color added later
int lc_container_insert_widget(l_container* containerPtr, l_widget* widgetPtr);
void lc_free_container(l_container** containerPtr);

l_windown* lc_windown_init(l_box area);
int lc_windown_insert_container(l_windown* windownPtr, l_container* l_containerPtr);
void lc_free_windown(l_windown** windownPtr);

#endif