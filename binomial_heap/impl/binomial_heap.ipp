#ifndef DRAWABLE_BINOMIAL_HEAP_BINOMIAL_HEAP_IPP_
#define DRAWABLE_BINOMIAL_HEAP_BINOMIAL_HEAP_IPP_

#include "binomial_heap/binomial_heap.hpp"

namespace drawable {

namespace binomial_heap {

template <typename T>
void BinomialHeap<T>::render(double x, double y) {
	double total_size = 0;

	for (auto tree : this->nodes_) {
        if (tree != nullptr) {
            tree->render(x + total_size, y);
            total_size += tree->width() + 1;
        }
	}
}

} // binomial_heap

} // drawable

#endif // DRAWABLE_BINOMIAL_HEAP_BINOMIAL_HEAP_IPP_
