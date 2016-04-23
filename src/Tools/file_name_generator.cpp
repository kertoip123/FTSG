#include "file_name_generator.hpp"

FileNameGenerator::FileNameGenerator(string file_name_prefix, string file_extension)
{
	this->file_name_prefix = file_name_prefix;
	this->file_extension = file_extension;
}

string FileNameGenerator::get_frame_name(int frame_id)
{
	string frame_name_mask = "000000";
	int name_offset = frame_name_mask.length() - 1;
	while(frame_id > 0 && name_offset >= 0)
	{
		int new_digit = frame_id % 10;
		frame_name_mask[name_offset] = (char)('0' + new_digit);
		frame_id /= 10;
		name_offset--;
	}

	if(frame_id == 0)
	{
		string frame_name = file_name_prefix;
		frame_name += frame_name_mask;
		frame_name += file_extension;
		return frame_name;
	}
	else
		return "";
}
