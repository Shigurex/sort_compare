#ifndef DATA_HPP
# define DATA_HPP

# include	<iostream>
# include	<fstream>
# include	"Define.hpp"

class Data
{
	public:
		str_	name;
		double	score;
		str_	name_jpn;
		str_	type;
		int		favourites;
		int		completed;

		Data() {};
		~Data() {};

		Data	operator=(const Data& rhs)
		{
			this->name = rhs.name;
			this->score = rhs.score;
			this->name_jpn = rhs.name_jpn;
			this->type = rhs.type;
			this->favourites = rhs.favourites;
			this->completed = rhs.completed;

			return (*this);
		};

		bool	operator>(const Data& rhs) const {return (this->score > rhs.score);};
		bool	operator<(const Data& rhs) const {return (this->score < rhs.score);};
		bool	operator>=(const Data& rhs) const {return (this->score >= rhs.score);};
		bool	operator<=(const Data& rhs) const {return (this->score <= rhs.score);};
		bool	operator==(const Data& rhs) const {return (this->score == rhs.score);};
		bool	operator!=(const Data& rhs) const {return (this->score != rhs.score);};
};

std::ostream&	operator<<(std::ostream& os, const Data &data)
{
	os << std::left << std::setw(80) << data.name;
	os << std::right << std::setw(10) << data.score;
	os << std::right << std::setw(10) << data.favourites;
	os << std::right << std::setw(10) << data.completed;
	os << std::left << "  " << std::setw(10) << data.type;
	return (os);
}

#endif
