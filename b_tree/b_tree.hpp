#ifndef DRAWABLE_B_TREE_B_TREE_HPP_
#define DRAWABLE_B_TREE_B_TREE_HPP_

#include <array>

#include "b_tree/eda_b_tree/include/b_tree.hpp"
#include "b_tree/node.hpp"
#include "drawable/tree.hpp"

namespace drawable {

namespace b_tree {

template <typename T, int m>
class BTree :
    public drawable::tree::Tree<T>,
    public eda::b_tree::BTree<T, m>
{
public:
	enum State {
		NODE_OVERFLOW,
		NODE_UNDERFLOW,
		NODE_OK
	};

private:
	// Node<T, m> *head_;

public:
	BTree();
	~BTree();

// 	void insert(T);
// 	bool exists(T);
// 	void remove(T);
// 	int size();
// 	void print();

private:
// 	State insert(Node<T, m> *, T);
// 	Node<T, m> *divide(Node<T, m> *&);
// 	void insert_within(Node<T, m> *, int, T, Node<T, m> *);
// 	int child_key(Node<T, m> *, T);
// 	void print(Node<T, m> *, int level);
// 	void kill(Node<T, m> *);

	Node<T, m> *root();
};

} // namespace b_tree

} // namespace drawable

#include "b_tree/impl/b_tree.ipp"

#endif // DRAWABLE_B_TREE_B_TREE_HPP_
