#include	"Algo.hpp"

int	main(void)
{
	Database	database;

	database.loadDataFile("./database/population.csv");

	vec_data_	vec_data = database.getDatabase();
	Sort		*sort;
	char		c;

	while (true) {
		std::cout << "input order > ";
		std::cin >> c;

		switch(c) {
			case 'b':
				sort = new Bubble(vec_data);
				break ;
			case 's':
				sort = new Shell(vec_data);
				break ;
			case 'i':
				sort = new Insertion(vec_data);
				break ;
			case 'e':
				sort = new Selection(vec_data);
				break ;
			case 'c':
				sort = new Count(vec_data);
				break ;
			default:
				continue ;
		}

		sort->sortAndOutput();
		delete sort;
	}
	return (0);
}
