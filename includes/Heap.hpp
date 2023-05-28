#ifndef HEAP_HPP
# define HEAP_HPP

# include	"Sort.hpp"

class Heap : public Sort
{
	public:
		Heap() {};
		Heap(vec_data_ data) : Sort(data) {};
		virtual ~Heap() {};

		void	heapSort(int left, int right)
		{
			Data	root;
			int		child, parent;
			this->copy(&this->_data[left], &root);
			for (parent = left; parent < (right + 1) / 2; parent = child) {
				int l = parent * 2 + 1; int r = l + 1;
				if (r <= right && this->compare(this->_data[r], this->_data[l]) == 1)
					child = r;
				else
					child = l;
				if (this->compare(root, this->_data[child])== 1)
					break ;
				this->copy(&this->_data[child], &this->_data[parent]);
			}
			this->copy(&root, &this->_data[parent]);
		}

		void	sort(void)
		{
			int	size = this->_data.size();
			int	i;

			for (i = size / 2 - 1; i >= 0; i--)
				heapSort(i, size - 1);
			for (i = size - 1; i > 0; i--) {
				this->swap(&this->_data[0], &this->_data[i]);
				heapSort(0, i - 1);
			}
		};
};

#endif
