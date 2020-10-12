#ifndef DRAWABLE_B_TREE_NODE_IPP_
#define DRAWABLE_B_TREE_NODE_IPP_

#include "node.hpp"

#include "b_tree.hpp"

namespace drawable {

namespace b_tree {

template <typename T, int m>
Node<T, m>::Node() : eda::b_tree::BaseNode<T, m, Node<T, m> >() {
	for (int i = 0; i < m; i++) {
		this->children_[i] = nullptr;
	}
}

template <typename T, int m>
int Node<T, m>::values() {
	return this->capacity_ - 1;
}

template <typename T, int m>
int Node<T, m>::children() {
	return this->is_leave() ? 0 : this->capacity_;
}

template <typename T, int m>
T Node<T, m>::value(int index) {
	return this->values_[index];
}

template <typename T, int m>
Node<T, m> *Node<T, m>::child(int index) {
	return this->children_[index];
}

template <typename T, int m>
bool Node<T, m>::is_leave() {
	return this->capacity_ == 0 || this->children_[0] == nullptr;
}

} // namespace b_tree

} // namespace drawable

#endif // DRAWABLE_B_TREE_NODE_IPP_
