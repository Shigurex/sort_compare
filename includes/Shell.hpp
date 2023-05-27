#ifndef SHELL_HPP
# define SHELL_HPP

# include	"Sort.hpp"

class Shell : public Sort
{
	public:
		Shell() {};
		Shell(vec_data_ data) : Sort(data) {};
		virtual ~Shell() {};

		void	sort(void)
		{
			int	size = this->_data.size();
			int	i, j;
			int	gap = size / 2;

			while (gap > 0) {
				for (i = gap; i < size; i++) {
					j = i;
					while (j >= gap && this->compare(this->_data[j - gap], this->_data[j]) == 1) {
						this->swap(&this->_data[j], &this->_data[j-gap]);
						j -= gap;
					}
				}
				gap = gap / 2;
			}
		};
};

#endif
