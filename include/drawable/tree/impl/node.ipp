#ifndef DRAWABLE_TREE_NODE_IPP_
#define DRAWABLE_TREE_NODE_IPP_

#include "drawable/tree/node.hpp"

#include "drawable/drawable.hpp"
#include "drawable/shape.hpp"

namespace drawable {

namespace tree {

template <typename T>
void Node<T>::render(double x, double y) {
    for (float i = 0; i < this->values(); i++) {
        render_shape(this->value(i), i + x - this->values() / 2.0f, y);
    }

    double current = x - this->width() / 2.0f;

    for (int i = 0; i < this->children(); i++) {
        if (this->child(i) != nullptr) {
            this->child(i)->render(current + this->child(i)->width() / 2.0f, y - 2.0f);
        }

        current += 1.0f + this->child(i)->width();
    }
}

template <typename T>
int Node<T>::width() {
	return this->leaves() + this->leave_level_values() - 1;
}

} // namespace tree

} // namespace drawable

#endif // DRAWABLE_TREE_NODE_IPP_
