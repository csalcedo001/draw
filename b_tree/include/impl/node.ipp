#ifndef DRAWABLE_NODE_IPP_
#define DRAWABLE_NODE_IPP_

#include "node.hpp"

#include "b_tree.hpp"

namespace drawable {

namespace b_tree {

template <typename T, int m>
Node<T, m>::Node() {
	for (int i = 0; i < m; i++) {
		this->children_[i] = nullptr;
	}
}

template <typename T, int m>
void Node<T, m>::search(T key) {
	
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

template <typename T, int m>
int Node<T, m>::leaves() {
	if (this->is_leave()) return 1;

	int total = 0;

	for (int i = 0; i < this->capacity_; i++) {
		if (this->children_[i] != nullptr) {
			total += this->children_[i]->leaves();
		}
	}

	return total;
}

template <typename T, int m>
int Node<T, m>::leave_level_values() {
	if (this->is_leave()) return this->capacity_ - 1;

	int total = 0;

	for (int i = 0; i < this->capacity_; i++) {
		if (this->children_[i] != nullptr) {
			total += this->children_[i]->leave_level_values();
		}
	}

	return total;
}

} // namespace b_tree

} // namespace drawable

#endif // DRAWABLE_NODE_IPP_
