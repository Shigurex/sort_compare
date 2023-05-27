#ifndef SORT_HPP
# define SORT_HPP

# include	<iostream>
# include	<vector>
# include	<iterator>
# include	"Data.hpp"
# include	"Database.hpp"
# include	"Define.hpp"

class Sort
{
	private:
		size_t	_num_copy;
		size_t	_num_compare;

	protected:
		vec_data_	_data;

		int				compare(Data& a, Data& b)
		{
			this->_num_compare++;
			return (a > b) ? 1 : (a < b) ? -1 : 0;
		};

		void			swap(Data *a, Data *b)
		{
			this->_num_copy += 3;
			Data	tmp = *a;
			*a = *b;
			*b = tmp;
		};

		void			copy(Data *src, Data *dst)
		{
			this->_num_copy++;
			*dst = *src;
		}

	public:

		Sort() : _num_copy(0), _num_compare(0) {};
		Sort(vec_data_ data) : _num_copy(0), _num_compare(0), _data(data) {};
		virtual ~Sort() {};

		void			setData(vec_data_ data) {_data = data;};
		vec_data_		getData(void) const {return (this->_data);};

		size_t			getNumSwap(void) {return (this->_num_copy);};
		size_t			getNumCompare(void) {return (this->_num_compare);};

		virtual void	sort(void) = 0;

		void			printData(void)
		{
			vec_data_::iterator	it_end = this->_data.end();
			for (vec_data_::iterator it = this->_data.begin(); it != it_end; it++)
				std::cout << *it << std::endl;
		}

		void			sortAndOutput(void)
		{
			std::cout << "Before:" << std::endl;
			printData();

			auto	start = std::chrono::system_clock::now();
			sort();
			auto end = std::chrono::system_clock::now();
			auto time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

			std::cout << "After:" << std::endl;
			printData();

			std::cout << "交換回数: " << getNumSwap() << " [回]" << std::endl;
			std::cout << "比較回数: " << getNumCompare() << " [回]" << std::endl;
			std::cout << "時間: " << time_ms << " [ms]" << std::endl;
		};
};

#endif
