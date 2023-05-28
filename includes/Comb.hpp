#ifndef COMB_HPP
# define COMB_HPP

# include	"Sort.hpp"

class Comb : public Sort
{
	public:
		Comb() {};
		Comb(vec_data_ data) : Sort(data) {};
		virtual ~Comb() {};

		void	sort(void)
		{
			int		size = this->_data.size();
			int		h = size;
			bool	need_swap = false;

			while (h > 1 || need_swap) {
				need_swap = false;
				if (h > 1)
					h /= 1.3;
				for (int i = 0; i < size - h; i++) {
					if (this->compare(this->_data[i], this->_data[i + h]) == 1) {
						this->swap(&this->_data[i], &this->_data[i + h]);
						need_swap = true;
					}
				}
			}
		};
};

#endif
