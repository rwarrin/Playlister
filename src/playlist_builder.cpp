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
#include <fstream>

// BuildPlaylist takes a C-String containing a directory path. Then the 
// function converts the C-String to a std::string, next it parses out then
// name of the directory from the path. Next it iterates over all files in the
// path and stores all .mp3 file names in a vector. Finally a playlist is
// created at the directory path and populated with the contents of the vector.
void BuildPlaylist(char *filePath) {
    using namespace std;

    string path(filePath);
    string directoryName = GetDirectoryName(path);
    vector<string> fileList = BuildFileList(path);
    WritePlaylist(path, directoryName, fileList);
}

// Takes a string containing a directory path and extracts the directory name
// from it. Returns a string containing the name of the directory.
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

// Iterates through all files in the directory contained in filePath, for all
// .mp3 files found they are stored in a vector. Once the function is done
// scanning through the directory the vector containing files names of all .mp3
// files is returned.
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
        fileList.push_back(string(findData.cFileName));
        result = FindNextFile(handle, &findData);
    }

    return fileList;
}

// Creates a new file at filePath using the directory name for the name of the
// playlist to be created. The contents of the fileList vector are written to
// the file.
void WritePlaylist(std::string filePath, std::string fileName, std::vector<std::string> &fileList) {
    using namespace std;

    // build a filename to use for the playlist
    string playlist(filePath);
    playlist += "\\00-";
    playlist += fileName;
    playlist += ".m3u";

    ofstream fileOut(playlist.c_str());

    vector<string>::const_iterator iter;
    for(iter = fileList.begin(); iter != fileList.end(); iter++)
        fileOut << *iter << endl;
    
    fileOut.close();
}
