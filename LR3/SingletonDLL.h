#pragma once
#include <string>
#include <fstream>
#include <mutex>

class dbManager {
private:
    dbManager() {}
    dbManager(const dbManager&) = delete;
    dbManager& operator=(const dbManager&) = delete;

public:
    static dbManager& getInstance() {
        static dbManager instance;
        return instance;
    }

    void connect(const std::string& connectionString) {
        // Логіка підключення до бази даних
    }
};

class DocumentSaver {
private:
    DocumentSaver() {}
    DocumentSaver(const DocumentSaver&) = delete;
    DocumentSaver& operator=(const DocumentSaver&) = delete;

public:
    static DocumentSaver& getInstance() {
        static DocumentSaver instance;
        return instance;
    }

    void saveDocument(const std::string& documentPath) {
        // Логіка збереження документів
    }
};

// Логер
class Logger {
private:
    std::ofstream logFile;
    std::mutex mtx;

    Logger() {
        logFile.open("log.txt", std::ios::app);
    }
    ~Logger() {
        if (logFile.is_open()) logFile.close();
    }

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void log(const std::string& message) {
        std::lock_guard<std::mutex> lock(mtx);
        if (logFile.is_open()) {
            logFile << message << std::endl;
        }
    }
};
