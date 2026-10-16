#include <stdlib.h>
#include "../include/lui_types.h"

size_t sizeList[Label] = {sizeof(w_label)};

size_t lt_get_Widget_type_size(WidgetType type){
    return sizeList[type];
}