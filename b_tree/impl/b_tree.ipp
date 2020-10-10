#ifndef DRAWABLE_B_TREE_B_TREE_IPP_
#define DRAWABLE_B_TREE_B_TREE_IPP_

#include "b_tree/b_tree.hpp"

#include "b_tree/node.hpp"

namespace drawable {

namespace b_tree {

template <typename T, int m>
Node<T, m> *BTree<T, m>::root() {
	return this->head_;
}

} // namespace b_tree

} // namespace drawable

#endif // DRAWABLE_B_TREE_B_TREE_IPP_
