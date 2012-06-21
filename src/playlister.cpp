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

#include "../include/playlist_builder.h"

int main(int argc, char *argv[]) {
    using namespace std;

    for(int i = 1; i < argc; i++)
        BuildPlaylist(argv[i]);

    return 0;
}
