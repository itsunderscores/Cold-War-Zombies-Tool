#pragma once

#include <string>

namespace MRK {
    void MRKSetLogPath(std::string path);
    void MRKLog(std::string log, bool clear = false, bool sep = true);
}
