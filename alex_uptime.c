#include <stdio.h>
#include <errno.h>
#include <sys/sysinfo.h>

int main(void)
{
    struct sysinfo s_info;//this is using sysinfo.h
    int error = sysinfo(&s_info);
    if(error != 0)
    {
        printf("code error = %d\n", error);
        return 1;
    }

    double uptime = (double)s_info.uptime;

    // Convert the system uptime from seconds to days, hours, and minutes
    int days    = (int)(uptime / (60 * 60 * 24));
    int hours   = (int)((uptime - (days * 60 * 60 * 24)) / (60 * 60));
    int minutes = (int)((uptime - (days * 60 * 60 * 24) - (hours * 60 * 60)) / 60);
    int seconds = (int)( uptime - (days * 60 * 60 * 24) - (hours * 60 * 60) - minutes * 60);

    // Print the system uptime
    printf("System uptime: %d days, %d hours, %d minutes, %d seconds\n", days, hours, minutes, seconds);
    // printf("%li",s_info.uptime);//s_info.uptime;

    return 0;
}