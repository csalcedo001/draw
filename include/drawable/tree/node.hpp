#ifndef DRAWABLE_TREE_NODE_HPP_
#define DRAWABLE_TREE_NODE_HPP_

#include "drawable/drawable.hpp"

namespace drawable {

namespace tree {

template <typename T, typename DerivedNode>
class Node : public Drawable {
public:
	int width();
	void render(double x, double y);

protected:
    virtual int leaves();
    virtual int leave_level_values();

public:
	virtual int values() = 0;
	virtual int children() = 0;
	
	virtual T value(int) = 0;
	virtual DerivedNode *child(int) = 0;
	virtual bool is_leave() = 0;
};

} // namespace tree

} // namespace drawable

#include "drawable/tree/impl/node.ipp"

#endif // DRAWABLE_TREE_NODE_HPP_
