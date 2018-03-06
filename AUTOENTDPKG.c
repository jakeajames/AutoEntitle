#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/stat.h>

//this is not used on this build but I'm including on the code since people would see the binary has this and will freak out

/*void
dasys (const char *arg)
{
    char *const args[] = { "/bin/bash", "-c", arg, 0 };
    execv ("/bin/bash", args);
}*/

int
main (int argc, char *argv[])
{
    
    int pd = fork();
    int ret;
    
    if (argc == 8)
    {
        //more than 1 deb installed by Cydia
        if (strcmp(argv[6], "--recursive") == 0)
        {
            char cmd[1024];
            sprintf(cmd,
                     "for deb in %s/*deb*; do /bin/bash /usr/bin/autoentitle fixup $deb; done",
                     argv[7]); //iterate through debs
            if (pd == 0 && pd != -1)
            {
                system(cmd);
                system("rm /Library/dpkg/lock; /bin/bash autoentitle wait &"); //wait for installation to finish on background and then run autoentitle again
            }
            else
                wait(&ret);
        }
    }
    
    else if (argc == 7)
    {
        //only one deb installed by cydia
        if (strcmp(argv[4], "--unpack") == 0)
        {
            char cmdd[1024];
            sprintf(cmdd, "/bin/bash /usr/bin/autoentitle fixup %s", argv[6]); //fix only that deb
            if (pd == 0 && pd != -1)
            {
                system(cmdd);
                system("rm /Library/dpkg/lock; /bin/bash autoentitle wait &"); //wait for installation to finish on background and then run autoentitle again
            }
            else
                wait (&ret);
        }
    }
    else if (argc == 3)
    {
        if (strcmp (argv[1], "-i") == 0)
        {
            //one deb installed by user
            char cmdi[1024];
            sprintf(cmdi, "/bin/bash /usr/bin/autoentitle fixup %s", argv[2]); //fix only that deb
            if (pd == 0 && pd != -1)
            {
                system(cmdi);
                system("rm /Library/dpkg/lock; /bin/bash autoentitle wait &"); //wait for installation to finish on background and then run autoentitle again
            }
            else
                wait(&ret);
        }
    }
    
    
    if (pd != 0 && pd != -1)
    {
        execv("/usr/bin/dpkz", argv); //continue installation
    }
    
    return 0;
    
}

