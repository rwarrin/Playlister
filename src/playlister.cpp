/******************************************************************************
 * playlister.cpp
 *
 * Rick W
 * 06/21/2012
 *
 * Build a playlist by dragging and dropping one or more directories on the
 * application.
 *
 *****************************************************************************/

#include <iostream>
#include <string>
#include <windows.h>

#include "../include/playlist_builder.h"

int main(int argc, char *argv[]) {
    using namespace std;

    char *filepath = "C:\\Projects\\Playlister\\tests";
    BuildPlaylist(filepath);

    return 0;
}
