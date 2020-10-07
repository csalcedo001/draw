#ifndef DRAWABLE_DRAWABLE_IPP_
#define DRAWABLE_DRAWABLE_IPP_

#include "drawable/drawable.hpp"

namespace drawable {

void Drawable::render(double x, double y) {
	::drawable::render<Drawable>(x, y);
}

} // namespace drawable

#endif // DRAWABLE_DRAWABLE_IPP_
