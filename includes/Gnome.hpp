#ifndef GNOME_HPP
# define GNOME_HPP

# include	"Sort.hpp"

class Gnome : public Sort
{
	public:
		Gnome() {};
		Gnome(vec_data_ data) : Sort(data) {};
		virtual ~Gnome() {};

		void	sort(void)
		{
			int	size = this->_data.size();
			int	base = 0;

			while (base < size - 1) {
				if (this->compare(this->_data[base], this->_data[base + 1]) == 1) {
					this->swap(&this->_data[base], &this->_data[base + 1]);
					if (base > 0)
						base--;
				}
				else
					base++;
			}
		};
};

#endif
