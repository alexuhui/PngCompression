#ifndef _PNG_COMPRESS_H
#define _PNG_COMPRESS_H

#include <string>
#include <filesystem>
#include <option.h>
#include "cmd.h"
#include "png_search.h"

bool findPngquant(const fs::path& curPath, string& pngquant);
void pngCompress(const fs::path& curPath, string& confFile, bool no_log = false);

#endif // _PNG_COMPRESS_H