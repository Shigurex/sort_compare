#ifndef INSERTION_HPP
# define INSERTION_HPP

# include	"Sort.hpp"

class Insertion : public Sort
{
	public:
		Insertion() {};
		Insertion(vec_data_ data) : Sort(data) {};
		virtual ~Insertion() {};

		void	sort(void)
		{
			int	size = this->_data.size();
			int	i, j;

			for (i = 1; i < size; i++) {
				j = i;
				while (j >= 1 && this->compare(this->_data[j - 1], this->_data[j]) == 1) {
					this->swap(&this->_data[j], &this->_data[j - 1]);
					j--;
				}
			}
		};
};

#endif
