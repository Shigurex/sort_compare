#ifndef BUBBLE_HPP
# define BUBBLE_HPP

# include	"Sort.hpp"

class Bubble : public Sort
{
	public:
		Bubble() {};
		Bubble(vec_data_ data) : Sort(data) {};
		virtual ~Bubble() {};

		void	sort(void)
		{
			int	size = this->_data.size();
			int	i, j;

			for (i = 0; i < size - 1; i++)
				for (j = size - 1; j > i; j--)
					if (this->compare(this->_data[j - 1], this->_data[j]) == 1)
						this->swap(&this->_data[j - 1], &this->_data[j]);
		};
};

#endif
