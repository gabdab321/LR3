#include <iostream>
#include "SingletonDLL.h"

int main() {
    dbManager& db = dbManager::getInstance();
    db.connect("Server=localhost;Database=testdb;");

    DocumentSaver& saver = DocumentSaver::getInstance();
    saver.saveDocument("document.txt");

    Logger& logger = Logger::getInstance();
    logger.log("Connected to database.");
    logger.log("Saved document.");

    std::cout << "Програма завершена успішно!" << std::endl;
    return 0;
}
