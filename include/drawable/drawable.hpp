#ifndef DRAWABLE_DRAWABLE_HPP_
#define DRAWABLE_DRAWABLE_HPP_

namespace drawable {

template <typename T>
void render(T &, double, double);

class Drawable {
public:
	virtual void render(double x, double y) = 0;
};

} // namespace drawable

#include "drawable/impl/drawable.ipp"

#endif // DRAWABLE_DRAWABLE_HPP_
