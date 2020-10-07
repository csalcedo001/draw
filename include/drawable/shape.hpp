#ifndef DRAWABLE_SHAPE_HPP_
#define DRAWABLE_SHAPE_HPP_

#include "drawable/drawable.hpp"

namespace drawable {

void init_render();
void cleanup_render();
void render_shape(int, double, double);
void render_square(double, double);
void render_text(int, double, double);
void render_shape(std::vector<int> &, double, double);

} // namespace drawable

#include "drawable/impl/shape.ipp"

#endif // DRAWABLE_SHAPE_HPP_
