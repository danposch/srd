#include "eventlogger.h"

EventLogger::EventLogger(const char *logfile_name)
{
    lf_name = std::string(logfile_name);

    //clear the file
    FILE *lf = fopen(lf_name.c_str(), "w");
    fprintf(lf,"#Logging Output: Timestamp - _File_, _Function_, _Line_ : MESSAGE\n\n");
    fclose(lf);
}

void EventLogger::log(const char *source_file, const char *function, const int line, const char *format, ...)
{

    FILE *lf = fopen(lf_name.c_str(), "a");

    if (lf != NULL)
    {
        struct timeval t;
        gettimeofday(&t, NULL);
        fprintf(lf,"%ld.%06u - %s, %s, %d :",(long)t.tv_sec , (unsigned)t.tv_usec , source_file , function , line);
        va_list args;
        va_start(args, format);
        vfprintf(lf, format, args);
        fclose(lf);
        va_end(args);
    }
}
