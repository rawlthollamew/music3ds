#pragma once

#include <stdio.h>
#include <dirent.h>
#include <string>
#include <strings.h>
#include <vector>

// i hope i fix this stupid issue of std::vector breaking intellisense for no real reason (everything else works).
const std::vector<std::string> allowedExtensions = { ".mp3", ".ogg", ".wav", ".opus", ".flac" };

class Library
{
public:
	Library(std::string _folder);
	std::vector<std::string> getFiles();
private:
	std::string folder;
	bool hasAllowedExtension(std::string _filename);
};