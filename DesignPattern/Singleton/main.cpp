#include <bits/stdc++.h>
using namespace std;

class Logger
{
public:
    static Logger &GetInstance()
    {
        /* Global function creating instance. as we are maintaining a static Logger
        only one copy of the logger will be cerated. */
        static Logger logger_instance;
        return logger_instance;
    }
    void printNotes()
    {
        for (const string &note : m_notes)
            cout << "Note: " << note << endl;
    }
    void addNotes(string note)
    {
        m_notes.push_back(note);
    }

private:
    Logger()
    {
        cout << "Logger created!" << endl;
    }
    ~Logger()
    {
        cout << "Logger destroyed!" << endl;
    }
    vector<string> m_notes;
};

int main()
{
    Logger &logger = Logger::GetInstance(); // Recieving Logger refernce.
    logger.addNotes("Hello");
    logger.addNotes("World!, ");
    logger.addNotes("How are you?");
    logger.printNotes();

    return 0;
}