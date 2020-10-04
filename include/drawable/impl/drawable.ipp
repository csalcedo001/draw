#ifndef DRAWABLE_DRAWABLE_IPP_
#define DRAWABLE_DRAWABLE_IPP_

namespace drawable {

void Drawable::render(double x, double y) {
	render<Drawable>(x, y);
}

} // namespace drawable

#endif // DRAWABLE_DRAWABLE_IPP_
