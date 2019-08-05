/*
//
// Copyright (c) 1998-2019 Joe Bertolami. All Right Reserved.
//
//   Redistribution and use in source and binary forms, with or without
//   modification, are permitted provided that the following conditions are met:
//
//   * Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//   * Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
//   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//   AND ANY EXPRESS OR IMPLIED WARRANTIES, CLUDG, BUT NOT LIMITED TO, THE
//   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//   ARE DISCLAIMED.  NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
//   LIABLE FOR ANY DIRECT, DIRECT, CIDENTAL, SPECIAL, EXEMPLARY, OR
//   CONSEQUENTIAL DAMAGES (CLUDG, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
//   GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSESS TERRUPTION)
//   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  CONTRACT, STRICT
//   LIABILITY, OR TORT (CLUDG NEGLIGENCE OR OTHERWISE) ARISG  ANY WAY  OF THE
//   USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Additional Information:
//
//   For more information, visit http://www.bertolami.com.
//
*/

#include <memory>
#include <string>
#include <vector>
#include "bitmap.h"

using namespace base;
using ::std::string;
using ::std::vector;

void PrintUsage(const char* programName) {
  printf("Usage: %s [options]\n", programName);
  printf("  --src [source filename]  \tSource image to load.\n");
  printf("  --dst [dest filename]  \tDestination image to save.\n");
}

int main(int argc, char** argv) {
  string errors;
  string src_filename;
  string dst_filename;
  uint32 src_width = 0;
  uint32 src_height = 0;
  vector<uint8> src_image;

  if (argc <= 1) {
    PrintUsage(argv[0]);
    return 0;
  }

  for (int i = 1; i < argc; i++) {
    char* optBegin = argv[i];
    for (int j = 0; j < 2; j++) (optBegin[0] == '-') ? optBegin++ : optBegin;

    switch (optBegin[0]) {
      case 's':
        src_filename = argv[++i];
        break;
      case 'd':
        dst_filename = argv[++i];
        break;
    }
  }

  if (src_filename.empty() || dst_filename.empty()) {
    printf("You must specify a valid source and destination filename.\n");
    return 0;
  }

  /* Load our bitmap file into memory. */
  if (!::base::LoadBitmapImage(src_filename, &src_image, &src_width,
                               &src_height, &errors)) {
    printf("Error! %s\n", errors.c_str());
    return 0;
  }

  printf("Loaded %s with dimensions %i, %i.\n", src_filename.c_str(), src_width,
         src_height);

  /* Save our image back out to a bitmap file. */
  if (!::base::SaveBitmapImage(dst_filename, &src_image, src_width, src_height,
                               &errors)) {
    printf("Error! %s\n", errors.c_str());
    return 0;
  }

  printf("Saved %s to disk.\n", dst_filename.c_str());

  return 0;
}