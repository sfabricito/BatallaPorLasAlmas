// Includes
#include "Post.h"

// Prototypes
string changeEmptySpacesUnderscores(string text);

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
    string filename;

    Record(string _filename){
        totalLogs = 0;
        filename = _filename;
        for (int i = 0; i < humanitySize; i++)
            logs[i] = NULL;
    }

    void insertLog(Human * human, string message){
        logs[totalLogs++] = new Log(human, message);
    }

    void generateFile(){
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Error opening log file with route: " + filename << endl;
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

    void sendRecord(string emailSubject, string emailBody){
        string subjectWithSpaces = changeEmptySpacesUnderscores(emailSubject);
        const char* subject = subjectWithSpaces.c_str();
        
        string bodyWithSpaces = changeEmptySpacesUnderscores(emailBody);
        const char* body = bodyWithSpaces.c_str();
        
        const char* _filename = (filename).c_str();

        char command[500];
        std::snprintf(command, sizeof(command), "python3 Mail/sendMail.py %s %s %s", subject, body, _filename);
        std::system(command);
    }
};

string changeEmptySpacesUnderscores(string text){
    for (size_t i = 0; i < text.length(); i++) {
        if (text[i] == ' ') {
            text[i] = '_';
        }
    }
    return text;
}