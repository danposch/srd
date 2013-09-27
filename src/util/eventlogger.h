#ifndef EVENTLOGGER_H
#define EVENTLOGGER_H

#include <string>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdarg.h>

class EventLogger
{
public:
    EventLogger(const char* logfile_name);
    void log(const char *source_file, const char *function, const int line, const char *format, ...);

private:
    std::string lf_name;
};

#endif // EVENTLOGGER_H
