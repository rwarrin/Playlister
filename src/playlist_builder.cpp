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

#include <windows.h>

int BuildPlaylist(char *filePath) {
    using namespace std;

    string path(filePath);
    string directoryName = GetDirectoryName(path);
    vector<string> fileList = BuildFileList(path);

    cout << "Path: " << path << endl;
    cout << "Directory name: " << directoryName << endl;

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

    return directoryName;
}

std::vector<std::string> BuildFileList(std::string filePath) {
    using namespace std;

    vector<string> fileList;
    WIN32_FIND_DATA findData;
    HANDLE handle = NULL;
    ZeroMemory(&findData, sizeof(WIN32_FIND_DATA));

    // build search string
    string searchString(filePath);
    searchString += "\\*.mp3";

    // find the first file that matches our *.mp3 file
    handle = FindFirstFile(searchString.c_str(), &findData);
    if(handle == INVALID_HANDLE_VALUE)
        return fileList;  // if not .mp3 is found return the empty list

    // iterate through all files in the directory
    int result = 1;
    while(result != 0) {
        cout << findData.cFileName << endl;
        fileList.push_back(string(findData.cFileName));
        result = FindNextFile(handle, &findData);
    }

    return fileList;
}
