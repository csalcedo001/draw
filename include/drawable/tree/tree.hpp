#ifndef DRAWABLE_TREE_TREE_HPP_
#define DRAWABLE_TREE_TREE_HPP_

#include "drawable/drawable.hpp"

namespace drawable {

namespace tree {

template <typename T>
class Tree : Drawable {
public:
	void render(double x, double y);

protected:
	virtual Node *root() = 0;
};

} // namespace tree

} // namespace drawable

#include "drawable/tree/impl/tree.ipp"

#endif // DRAWABLE_TREE_TREE_HPP_
