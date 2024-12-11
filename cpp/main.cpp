#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include "nlohmann/json.hpp" 

int main() {
    std::unordered_map<std::string, std::vector<std::string>> channelsMessages;
    std::string currentPath = std::filesystem::current_path().string();
    
    // Get all directories in the current path
    for (const auto& entry : std::filesystem::directory_iterator(currentPath)) {
        if (std::filesystem::is_directory(entry.status())) {
            std::string channel = entry.path().filename().string();
            std::string messagesFilePath = currentPath + "/" + channel + "/messages.json";
            
            // Open the json file
            std::ifstream messagesFiles(messagesFilePath);
            nlohmann::json messagesJSON;
            messagesFiles >> messagesJSON;
            std::vector<std::string> messages;
                
            // Extract message IDs as strings
            for (const auto& message : messagesJSON) {
                messages.push_back(std::to_string(message["ID"].get<uint64_t>()));
            }
                
            // Only add channels with non-empty messages
            if (!messages.empty()) {
                channelsMessages[channel] = messages;
            }
            
            messagesFiles.close();
        }
    }

    // Write IDs into sensitive.txt
    std::ofstream outputFile(currentPath + "/sensitive.csv");
    for (const auto& [channelIDs, messages] : channelsMessages) {
        outputFile << channelIDs << ":\n";
        for (size_t i = 0; i < messages.size(); ++i) {
            outputFile << messages[i];
            if (i < messages.size() - 1) {
                outputFile << ", ";
            }
        }
        outputFile << "\n\n";
    }
        outputFile.close();
    return 0;
}
