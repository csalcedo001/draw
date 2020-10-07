#ifndef DRAWABLE_DRAWABLE_IPP_
#define DRAWABLE_DRAWABLE_IPP_

#include "drawable/drawable.hpp"

#include <iostream>

namespace drawable {

void render(Drawable &, double, double) {
    std::cout << "Called parent" << std::endl;
}

void Drawable::render(double x, double y) {
	::drawable::render(*this, x, y);
}

} // namespace drawable

#endif // DRAWABLE_DRAWABLE_IPP_
