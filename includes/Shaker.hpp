#ifndef SHAKER_HPP
# define SHAKER_HPP

# include	"Sort.hpp"

class Shaker : public Sort
{
	public:
		Shaker() {};
		Shaker(vec_data_ data) : Sort(data) {};
		virtual ~Shaker() {};

		void	sort(void)
		{
			int	left = 0;
			int	right = this->_data.size() - 1;
			int	last_swap;

			while (left != right) {
				last_swap = left;
				for (int i = left; i < right; i++) {
					if (this->compare(this->_data[i], this->_data[i + 1]) == 1) {
						this->swap(&this->_data[i], &this->_data[i + 1]);
						last_swap = i;
					}
				}
				right = last_swap;
				last_swap = right;
				for (int i = right; i > left; i--) {
					if (this->compare(this->_data[i], this->_data[i - 1]) == -1) {
						this->swap(&this->_data[i], &this->_data[i - 1]);
						last_swap = i;
					}
				}
				left = last_swap;
			}
		};
};

#endif
