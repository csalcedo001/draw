#ifndef DRAWABLE_B_TREE_B_TREE_HPP_
#define DRAWABLE_B_TREE_B_TREE_HPP_

#include <array>

#include "base_b_tree.hpp"
#include "drawable/tree.hpp"
#include "b_tree/node.hpp"

namespace drawable {

namespace b_tree {

template <typename T, int m>
class BTree :
    public eda::b_tree::BaseBTree<T, m, Node<T, m> >,
    public drawable::tree::Tree<T, Node<T, m> >
{
public:
	enum State {
		NODE_OVERFLOW,
		NODE_UNDERFLOW,
		NODE_OK
	};

private:
	Node<T, m> *root();
};

} // namespace b_tree

} // namespace drawable

#include "b_tree/impl/b_tree.ipp"

#endif // DRAWABLE_B_TREE_B_TREE_HPP_
