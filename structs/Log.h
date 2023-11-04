// Includes
#include "Post.h"


struct Log{
    Human * human;
    string message;

    Log(Human * _human, string _message){
        human = _human;
        message = _message;
    }

};

struct Record{
    Log * logs[humanitySize];
    int totalLogs;
    string fileRoute;

    Record(string _fileRoute){
        totalLogs = 0;
        fileRoute = _fileRoute;
        for (int i = 0; i < humanitySize; i++)
            logs[i] = NULL;
    }

    void insertLog(Human * human, string message){
        logs[totalLogs++] = new Log(human, message);
    }

    void generateFile(){
        ofstream file(fileRoute);
        if (!file.is_open()) {
            cout << "Error opening log file with route: " + fileRoute << endl;
            return;
        }
        for (int i = 0; i < totalLogs; i++)
        {
            string logInfo;
            auto currentTime = std::chrono::system_clock::now();
            time_t time = std::chrono::system_clock::to_time_t(currentTime);
            std::tm* timeinfo = std::localtime(&time);
            if (timeinfo) {
                std::stringstream ss;
                ss << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S");
                logInfo += ss.str() + "\t";
                logInfo += "Human ";
                logInfo += to_string(logs[i]->human->id);
                logInfo += ", " + logs[i]->human->name;
                logInfo += " " + logs[i]->human->lastName;
                logInfo += ", " + logs[i]->human->country;
                logInfo += ", " + logs[i]->message + "\n";
            }
            file << logInfo;
        }
    }
};