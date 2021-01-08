/* Copyright (C) 2021 John Törnblom

This program is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 3, or (at your option) any
later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING. If not, see
<http://www.gnu.org/licenses/>.  */

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <limits.h>


/**
 *
 **/
int
main_mkdir(int argc, char **argv) {
  mode_t mode = 0777;
  char path[PATH_MAX];
  char *pwd = getenv("PWD");
  
  if(argc <= 1) {
    fprintf(stderr, "%s: missing operand\n", argv[0]);
    return -1;
  }

  for(int i=0; i<argc-1; i++) {
    if(argv[i+1][0] == '/') {
      strncpy(path, argv[i+1], sizeof(path));
    } else {
      snprintf(path, sizeof(path), "%s/%s", pwd, argv[i+1]);
    }

    if(mkdir(path, mode)) {
      perror(path);
    }
  }

  return 0;
}


