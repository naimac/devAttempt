#include "../include/apishm.hpp"

int		sharedMem_handler(int key, size_t size, char *sharedMem)
{
	int shmid;

	// creation memoire partagee avec droits d acces rxw
	if ((shmid = shmget (key, size, IPC_CREAT | 0666)) < 0)
	{
		// remplacer par un syslog
		printf("[capture] shmget: shmget returned %d\n", shmid);
	}

	// attach sharedmem to shmid
	sharedMem = (char *) shmat(shmid, NULL, 0);

	return shmid;
}
