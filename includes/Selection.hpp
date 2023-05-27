#ifndef SELECTION_HPP
# define SELECTION_HPP

# include	"Sort.hpp"

class Selection : public Sort
{
	public:
		Selection() {};
		Selection(vec_data_ data) : Sort(data) {};
		virtual ~Selection() {};

		void	sort(void)
		{
			int	size = this->_data.size();
			int	i, j;

			for (i = 0; i < size - 1; i++) {
				int	min = i;
				for (j = i + 1; j < size; j++)
					if (this->compare(this->_data[min], this->_data[j]) == 1)
						min = j;
				this->swap(&this->_data[i], &this->_data[min]);
			}
		};
};

#endif
