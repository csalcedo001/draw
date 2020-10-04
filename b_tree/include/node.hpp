#ifndef DRAWABLE_NODE_HPP_
#define DRAWABLE_NODE_HPP_

#include "drawable/tree.hpp"

namespace drawable {

namespace b_tree {

template <typename T, int m>
class Node : public drawable::Tree<T>::Node {
public:
	std::array<T, m> values_;
	std::array<Node<T, m> *, m + 1> children_;
	int capacity_;

public:
	Node(void);
	
	void search(T key);

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

#include "impl/node.ipp"

#endif // DRAWABLE_NODE_HPP_
