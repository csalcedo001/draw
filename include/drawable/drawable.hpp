#ifndef DRAWABLE_DRAWABLE_HPP_
#define DRAWABLE_DRAWABLE_HPP_

namespace drawable {

template <typename... Types>
void render(double x, double y);

class Drawable {
public:
	void render(double x, double y);
};

} // namespace drawable

#include "drawable/impl/drawable.ipp"

#endif // DRAWABLE_DRAWABLE_HPP_
