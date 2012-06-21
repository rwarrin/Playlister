/******************************************************************************
 * playlist_builder.cpp
 *
 * Rick W
 * 06/21/2012
 *
 * Implementation of playlist_builder.h function definitions.
 *
 *****************************************************************************/

#include "../include/playlist_builder.h"

int BuildPlaylist(char *filePath) {
    using namespace std;

    string path(filePath);
    string directoryName = GetDirectoryName(path);

    cout << "Path: " << path << endl;
    cout << "Directory name: " << fileName << endl;

    return 0;
}

std::string GetDirectoryName(std::string filePath) {
    using namespace std;

    string directoryName;

    size_t location = filePath.find_last_of("/\\");
    if(location != string::npos)
        directoryName = string(filePath, location + 1);
    else
        directoryName = string("Error");

    return fileName;
}

std::vector<std::string> BuildFileList(std::string filePath) {
    using namespace std;
    std::vector<std::string> fileList;

    return fileList;
}
