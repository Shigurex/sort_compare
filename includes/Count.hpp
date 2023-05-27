#ifndef COUNT_HPP
# define COUNT_HPP

# include	"Sort.hpp"

class Count : public Sort
{
	public:
		Count() {};
		Count(vec_data_ data) : Sort(data) {};
		virtual ~Count() {};

		void	sort(void)
		{
			//int	i, key;
			//int	count[501]; /* Score ranges from 0 to 500 (501 key values) */
			//struct student *work;
			//if ((work = malloc(sizeof(struct student) * size)) == NULL) {
			//	printf("Cannot allocate memory \n"); exit(1);
			//}
			///* Clear counter */
			//for (i = 0; i <= 500; i++)
			//	count[i] = 0;
			///* Frequency distribution */
			//for (i = 0; i < size; i++) {
			//	key = table[i].score;
			//	count[key]++;
			//}
			///* Cumlative frequency distribution */
			//for (i = 0; i < 500; i++)
			//	count[i + 1] += count[i];
			//for (i = size - 1; i >= 0; i--) {
			//	key = table[i].score;
			//	/* Copy the data, based on cumlative frequency distribution */
			//	my_copy(&table[i], &work[--count[key]]);
			//}
			//for (i = 0; i < size; i++)
			//	my_copy(&work[i], &table[i]);
			//free(work);
		};
};

#endif
