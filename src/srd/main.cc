#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

#include <../util/eventlogger.h>

int daemonize()
{
    pid_t pid, sid;

    pid = fork();
    if (pid < 0)
        exit(EXIT_FAILURE);

    // parent exit
    if (pid > 0)
        exit(EXIT_SUCCESS);

    umask(0);

    /* Open any logs here */

    // id daemon
    sid = setsid();
    if (sid < 0)
    {
            /* Log the failure */
            exit(EXIT_FAILURE);
    }

    if ((chdir("/tmp")) < 0)
    {
            /* Log the failure */
            exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    return sid;
}

int main(void)
{
    int sid = daemonize();
    EventLogger logger("/tmp/SDR_LOG");
    logger.log(__FILE__,__FUNCTION__,__LINE__,"SDR is daemonized. Daemon's id is %d.\n",sid);

    while (1)
    {
        sleep(30); /* wait 30 seconds */
    }

    exit(EXIT_SUCCESS);
}
