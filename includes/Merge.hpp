#ifndef MERGE_HPP
# define MERGE_HPP

# include	"Sort.hpp"

class Merge : public Sort
{
	public:
		Merge() {};
		Merge(vec_data_ data) : Sort(data) {};
		virtual ~Merge() {};

		void	mergeSort(int left, int right, Data *work)
		{
			int center, i, j, num, base;
			if (left >= right)
				return;
			center = (left + right) / 2;
			mergeSort(left, center, work);
			mergeSort(center + 1, right, work);
			num = 0;
			for (i = left; i <= center; i++)
				this->copy(&this->_data[i], &work[num++]);
			j = 0; base = left;
			while (i <= right && j < num) {
				if (this->compare(work[j], this->_data[i]) == 1)
					this->copy(&this->_data[i++], &this->_data[base++]);
				else
					this->copy(&work[j++], &this->_data[base++]);
			}
			while (j < num)
				this->copy(&work[j++], &this->_data[base++]);
		}

		void	sort(void)
		{
			int		size = this->_data.size();
			Data	*data = (Data *)malloc(sizeof(Data) * size);
			mergeSort(0, size - 1, data);
		};
};

#endif
