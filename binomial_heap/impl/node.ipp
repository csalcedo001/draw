#ifndef DRAWABLE_BINOMIAL_HEAP_NODE_IPP_
#define DRAWABLE_BINOMIAL_HEAP_NODE_IPP_

#include "binomial_heap/node.hpp"

namespace drawable {

namespace binomial_heap {

template <typename T>
Node<T>::Node(int value) :
	eda::binomial_heap::BaseNode<T, Node<T> >(value)
{

}

template <typename T>
int Node<T>::values() {
	return 1;
}

template <typename T>
int Node<T>::children() {
    return this->children_.size();
}

template <typename T>
T Node<T>::value(int i) {
	return this->value_;
}

template <typename T>
Node<T> *Node<T>::child(int i) {
	return this->children_[i];
}

template <typename T>
bool Node<T>::is_leave() {
	return this->children_.size() == 0;
}

// template <typename T>
// int Node<T>::leaves() {
// 	if (this->is_leave()) return 1;
// 
// 	int total = 0;
// 
// 
// }
// 
// template <typename T>
// int Node<T>::leave_level_values() {
// 
// }

} // binomial_heap

} // drawable

#endif // DRAWABLE_BINOMIAL_HEAP_NODE_IPP_
