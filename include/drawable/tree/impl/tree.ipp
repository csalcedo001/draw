#ifndef DRAWABLE_TREE_TREE_IPP_
#define DRAWABLE_TREE_TREE_IPP_

#include "drawable/drawable.hpp"
#include "drawable/tree/tree.hpp"

namespace drawable {

namespace tree {

template <typename T>
void Tree<T>::render(double x, double y) {
    if (this->root() != nullptr) {
        this->root()->render(x, y);
	}
}


} // namespace tree

} // namespace drawable

#endif // DRAWABLE_TREE_TREE_IPP_
