#ifndef SRC_FILE_NAME_GENERATOR_HPP_
#define SRC_FILE_NAME_GENERATOR_HPP_

#include <string>
using namespace std;

const string JPG = ".jpg";
const string PNG = ".png";

class FileNameGenerator
{
	private:
		string file_name_prefix;
		string file_extension;
		string extension;
	public:
		FileNameGenerator(string file_name_prefix, string file_extension);
		string get_frame_name(int frame_id);
};

#endif /* SRC_FILE_NAME_GENERATOR_HPP_ */
