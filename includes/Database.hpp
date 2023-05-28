#ifndef DATABASE_HPP
# define DATABASE_HPP

# include	<vector>
# include	<fstream>
# include	"Data.hpp"
# include	"Define.hpp"

typedef std::vector<Data>	vec_data_;

class Database
{
	private:
		vec_data_	_database;

	public:
		Database() {};
		~Database() {};

		vec_str_	split(str_ str, str_ delim)
		{
			vec_str_	vec_str;
			size_t		pos = 0;
			size_t		found;

			while (true)
			{
				found = str.find_first_not_of(delim, pos);
				if (found == str_::npos)
					break;
				pos = found;
				found = str.find_first_of(delim, pos);
				if (found == str_::npos)
					break;
				vec_str.push_back(str.substr(pos, found - pos));
				pos = found + 1;
			}
			vec_str.push_back(str.substr(pos));
			return (vec_str);
		}

		void		loadDataFile(std::string data_file)
		{
			std::ifstream	ifs(data_file);
			str_			line;
			vec_str_		split_line;

			if (ifs.fail())
				exit(EXIT_FAILURE);

			while (std::getline(ifs, line)) {
				split_line = split(line, ",");
				Data	data;

				std::cout << split_line[0] << std::endl;

				if (line.find("\"") != std::string::npos || split_line.size() != 6)
					continue ;

				data.name = split_line[0];
				data.score = std::stod(split_line[1]);
				data.name_jpn = split_line[2];
				data.type = split_line[3];
				data.favourites = std::stoi(split_line[4]);
				data.completed = std::stoi(split_line[5]);

				this->_database.push_back(data);
			}

			ifs.close();

			std::cout << data_file << " loaded" << std::endl;
		};

		vec_data_	getDatabase(void) {return (this->_database);};
};

#endif
