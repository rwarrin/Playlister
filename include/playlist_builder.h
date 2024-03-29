/******************************************************************************
 * playlist_builder.h
 *
 * Rick W
 * 06/21/2012
 *
 * Contains helper functions to automatically parse a directory to enumerate
 * files within and build a playlist.
 *
 *****************************************************************************/

#ifndef PLAYLIST_BUILDER_H
#define PLAYLIST_BUILDER_H

#include <iostream>
#include <string>
#include <vector>

// This function is used to call all other functions used to build a single
// playlist file. Returns 0 if a playlist is successfully created.
// filePath: C-String containing the path to the directory to be used.
void BuildPlaylist(char *filePath);

// Parses a filepath to extract the name of the directory to be enumerated.
// Returns a string containing the directory name.
// filePath: std::string containing the path to the directory.
std::string GetDirectoryName(std::string filePath);

// Iterates through a directory searching for all .mp3 files, adding them to a
// vector container. Returns a vector containing all .mp3 files.
// filePath: std::string containing the path to the directory to iterate.
std::vector<std::string> BuildFileList(std::string filePath);

// Creates a new playlist file in the filePath directory using the fileName name
// and populating it with the contents of the fileList vector.
// filePath: std::string containing path to create file in.
// fileName: std::string containing the name of the playlist to be created
// fileList: std::vector<std::string> reference to a container with all 
// .mp3 file names to add to the playlist.
void WritePlaylist(std::string filePath, std::string fileName, std::vector<std::string> &fileList);

#endif  // PLAYLIST_BUILDER_H
