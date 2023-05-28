#ifndef QUICK_HPP
# define QUICK_HPP

# include	"Sort.hpp"

class Quick : public Sort
{
	public:
		Quick() {};
		Quick(vec_data_ data) : Sort(data) {};
		virtual ~Quick() {};

		void	quickSort(int left, int right)
		{
			int		i, j;
			Data	pivot;

			if (left >= right)
				return;
			i = left;
			j = right;
			this->copy(&this->_data[(i + j) / 2], &pivot);
			do {
				while (this->compare(this->_data[i], pivot)== -1)
					i++;
				while (this->compare(this->_data[j], pivot)==  1)
					j--;
				if (i <= j) {
					this->swap(&this->_data[i], &this->_data[j]);
					i++;
					j--;
				}
			} while (i <= j);
			quickSort(left, j);
			quickSort(i, right);
		}

		void	sort(void)
		{
			quickSort(0, this->_data.size() - 1);
		};
};

#endif
