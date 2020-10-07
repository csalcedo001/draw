#ifndef DRAWABLE_TREE_NODE_IPP_
#define DRAWABLE_TREE_NODE_IPP_

#include "drawable/tree/node.hpp"

#include "drawable/drawable.hpp"
#include "drawable/shape.hpp"

namespace drawable {

template <typename T>
void render(tree::Node<T> &node, double x, double y) {
	for (float i = 0; i < node.values(); i++) {
		render_shape(node.value(i), i + x - node.values() / 2.0f, y);
	}

	double current = x - node.width() / 2.0f;

	for (int i = 0; i < node.children(); i++) {
		if (node.child(i) != nullptr) {
			node.child(i)->render(current + node.child(i)->width() / 2.0f, y - 2.0f);
		}

		current += 1.0f + node.child(i)->width();
	}
}

namespace tree {

template <typename T>
int Node<T>::width() {
	return this->leaves() + this->leave_level_values() - 1;
}

} // namespace tree

} // namespace drawable

#endif // DRAWABLE_TREE_NODE_IPP_
