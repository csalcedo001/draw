#ifndef DRAWABLE_DRAWABLE_IPP_
#define DRAWABLE_DRAWABLE_IPP_

#include "drawable/drawable.hpp"

#include <iostream>

namespace drawable {

void render(Drawable &obj, double x, double y) {
    obj.render(x, y);
}

} // namespace drawable

#endif // DRAWABLE_DRAWABLE_IPP_
