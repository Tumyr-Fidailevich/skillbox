#include <iostream>
#include <filesystem>
#include <vector>

auto recursiveGetFileNamesByExtension = [](std::filesystem::path &path,
										   const std::string &extension) {
	std::vector<std::string> fileNames;
	for(auto& p: std::filesystem::recursive_directory_iterator(path))
	{
		if(is_regular_file(p.path()) && p.path().extension().compare(extension))
		{
			fileNames.push_back(p.path().filename().string());
		}
	}
	return fileNames;
};

int main()
{
	const std::string targetExtension = ".txt";
	std::filesystem::path searchPath = R"(C:\Users\timur\Downloads)";
	auto fileNames = recursiveGetFileNamesByExtension(searchPath, targetExtension);
	for(auto &file : fileNames)
	{
		std::cout << file << " ";
	}
	std::cout << std::endl;
	return 0;
}
