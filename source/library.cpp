#include "library.h"

Library::Library(std::string _folder)
    : folder(_folder)
{
    ;
}

bool Library::hasAllowedExtension(std::string _filename)
{
	auto pos = _filename.rfind('.');

	if (pos == std::string::npos) return false;

	std::string extension = _filename.substr(pos);

	for (auto allowed : allowedExtensions)
	{
		if (strcasecmp(extension.c_str(), allowed.c_str()) == 0) return true;
	}

	return false;
}

std::vector<std::string> Library::getFiles()
{
    std::vector<std::string> songs;

	DIR* musicDirectory = opendir(folder.c_str());
	if (musicDirectory)
	{
		// c structure dirent
		struct dirent *entry;

		while ((entry = readdir(musicDirectory)) != NULL)
		{
			// printf("%s\n", entry->d_name);

			std::string currentFile(entry->d_name);
			
			if (currentFile == "." || currentFile == "..")
			{
				songs.push_back(currentFile);
			}
			else if (hasAllowedExtension(currentFile))
			{
				songs.push_back(currentFile);
			}
		}
		closedir(musicDirectory);
	}
	else
	{
		printf("Could not open directory.");
	}
    return songs;
}