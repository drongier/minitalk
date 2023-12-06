#include "minitalk.h"

void handle_signal(int signal)
{
    static int  bit_count;
    static int  received_char;

    if (signal == SIGUSR1) 
    {
        received_char |= (1 << bit_count); //sert a conserver les bits en place
    }
    bit_count++;

    if (bit_count == 8)
    {
        ft_printf("%c", received_char);
        bit_count = 0;
        received_char = 0;
    }
}

int main(void)
{
    int pid;

    signal(SIGUSR1, handle_signal);
    signal(SIGUSR2, handle_signal);
    pid = getpid();
	ft_printf("PID -> %d\n", pid);
	ft_printf("Waiting for a message... \n");
    while(1)
        sleep(1);
    return(0);
}