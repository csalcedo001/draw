#ifndef DRAWABLE_BINOMIAL_HEAP_NODE_HPP_
#define DRAWABLE_BINOMIAL_HEAP_NODE_HPP_

#include "base_node.hpp"
#include "drawable/tree.hpp"

namespace drawable {

namespace binomial_heap {

template <typename T>
class Node :
	public eda::binomial_heap::BaseNode<T, Node<T> >,
	public drawable::tree::Node<T, Node<T> >
{
public:
	Node(int);

	int values();
	int children();

	T value(int);
	Node *child(int);
	bool is_leave();
	// int leaves();
	// int leave_level_values();
};

} // binomial_heap

} // drawable

#include "binomial_heap/impl/node.ipp"

#endif // DRAWABLE_BINOMIAL_HEAP_NODE_HPP_
