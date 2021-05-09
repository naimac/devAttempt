#include "../include/apishm.hpp"

char	*init_sharedMem(int key, int size, int index_sharedMem)
{
	char	*sharedMem;
	int		shmid; // return of shmget
//	key_t	key = ftok(".", 36); // identifiant unique de la memoire paratagee

	shmid = sharedMem_handler(key, size, sharedMem);

	// 6 au lieu de index_sharedMem
	memcpy(sharedMem, "toto_", index_sharedMem);
	printf("sharedMem [%s]\n", sharedMem);

	return (sharedMem);
}
