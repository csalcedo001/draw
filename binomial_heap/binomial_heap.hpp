#ifndef DRAWABLE_BINOMIAL_HEAP_BINOMIAL_HEAP_HPP_
#define DRAWABLE_BINOMIAL_HEAP_BINOMIAL_HEAP_HPP_

#include "base_binomial_heap.hpp"
#include "drawable/drawable.hpp"
#include "binomial_heap/node.hpp"

namespace drawable {

namespace binomial_heap {

template <typename T>
class BinomialHeap :
	public eda::binomial_heap::BaseBinomialHeap<T, Node<T> >,
	public drawable::Drawable
{
public:
	void render(double x, double y);
};

} // binomial_heap

} // drawable

#include "binomial_heap/impl/binomial_heap.ipp"

#endif // DRAWABLE_BINOMIAL_HEAP_BINOMIAL_HEAP_HPP_
