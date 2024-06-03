#pragma once

#include <vector>

class Logs {
private:
    std::vector<std::string> logs;

public:
    void writeLog(std::string log) {
        logs.push_back(log);
    };
    std::vector<std::string> readLog() const {
        return logs;
    };

    void clearLog() {
        logs.clear();
    }
};