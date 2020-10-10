#ifndef DRAWABLE_B_TREE_NODE_HPP_
#define DRAWABLE_B_TREE_NODE_HPP_

#include "b_tree/eda_b_tree/include/node.hpp"
#include "drawable/tree/node.hpp"

namespace drawable {

namespace b_tree {

template <typename T, int m>
class Node :
public drawable::tree::Node<T, Node<T, m> >,
    public eda::b_tree::BaseNode<T, m, Node<T, m> >
{
public:
	Node(void);

	int children();
	int values();

	T value(int);
	Node<T, m> *child(int);
	bool is_leave();

protected:
	int leaves();
	int leave_level_values();
};

} // namespace b_tree

} // namespace drawable

#include "b_tree/impl/node.ipp"

#endif // DRAWABLE_B_TREE_NODE_HPP_
