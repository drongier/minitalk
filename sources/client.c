#include "minitalk.h"

void send_bit(int bit, pid_t server_pid) {
    if (bit)
        kill(server_pid, SIGUSR1);
    else
        kill(server_pid, SIGUSR2);
}

void send_string(const char *str, pid_t server_pid) 
{
    int i;
    int j;
    int bit;
    int len;
    char    c;

    i = 0;
    len = strlen(str);
    while (i < len)
    {
        c = str[i];
        j = 0;
        while (j < 8)
        {
            bit = (c >> j) & 1;
            send_bit(bit, server_pid);
            usleep(50);
            j++;
        }
        i++;
    }
    
}

int main(int argc, char *argv[]) 
{
    if (argc != 3)
    {
        ft_printf("Use: %s <server_pid> <message>\n", argv[0]);
        return (1);
    }

    pid_t server_pid = atoi(argv[1]);
    const char *message = (argv[2]);
    printf("Sending message: %s\n", message);
    send_string(message, server_pid);
    send_string("\n", server_pid);

    return (0);
}