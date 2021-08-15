#include "MRKLog.h"

#include <fstream>


namespace MRK
{
	std::string ms_LogPath;
	void MRKSetLogPath(std::string path) 
	{
		
		ms_LogPath = path;
		
	}
	void MRKLog(std::string log, bool clear, bool sep) 
	{
		
		/*_STD ofstream stream(ms_LogPath.c_str(), clear ? _STD ios_base::out : _STD ios_base::app);
		if (sep)
			stream << '\n';

		stream << log;
		stream.close();*/
		
	}
}
