#ifndef DATA_HPP
# define DATA_HPP

# include	<iostream>
# include	<fstream>
# include	"Define.hpp"

class Data
{
	public:
		str_	place;
		int		population;
		int		population_man;
		int		population_woman;
		double	gender_ratio;

		Data() {};
		~Data() {};

		Data	operator=(const Data& rhs)
		{
			this->place = rhs.place;
			this->population = rhs.population;
			this->population_man = rhs.population_man;
			this->population_woman = rhs.population_woman;
			this->gender_ratio = rhs.gender_ratio;
			return (*this);
		};

		bool	operator>(const Data& rhs) const {return (this->gender_ratio > rhs.gender_ratio);};
		bool	operator<(const Data& rhs) const {return (this->gender_ratio < rhs.gender_ratio);};
		bool	operator>=(const Data& rhs) const {return (this->gender_ratio >= rhs.gender_ratio);};
		bool	operator<=(const Data& rhs) const {return (this->gender_ratio <= rhs.gender_ratio);};
		bool	operator==(const Data& rhs) const {return (this->gender_ratio == rhs.gender_ratio);};
		bool	operator!=(const Data& rhs) const {return (this->gender_ratio != rhs.gender_ratio);};
};

std::ostream&	operator<<(std::ostream& os, const Data &data)
{
	os << std::right << std::setw(10) << data.population;
	os << std::right << std::setw(10) << data.population_man;
	os << std::right << std::setw(10) << data.population_woman;
	os << std::right << std::setw(10) << data.gender_ratio;
	os << "  " << data.place;
	return (os);
}

#endif
