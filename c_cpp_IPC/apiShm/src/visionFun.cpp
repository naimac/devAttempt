#include "../include/apishm.hpp"

// methode de recuperation sur memoire partagee propre à vision
// par exemple, sur ce que propose la capture vision s'interesse a l'addresse ip
char	*visionFunc(char *device, char *sharedMem, int indexShm, char *error_buffer)
{
	// histoire de tester pcap_lookupdev
	char			ip[13];
	bpf_u_int32		ip_int;
	bpf_u_int32		subnet_mask_int;
	int				ret;
	struct in_addr	address;
	
	device = pcap_lookupdev(error_buffer);

	if (device == NULL)
	{
		printf("%s\n", error_buffer);
		return NULL;
	}

	device = strdup("lo");

	ret = pcap_lookupnet(device, &ip_int, &subnet_mask_int, error_buffer);

	if (ret == -1)
	{
		printf("%s\n", error_buffer);
		return NULL;
	}

	address.s_addr = ip_int;
	strcpy(ip, inet_ntoa(address));

/*
	// ce test ci-dessous ne marche pas
	if (subnet_mask == NULL)
	{
		perror("inet_ntoa");
		return 1;
	}
*/

	printf("Device : [%s] | IP address : [%s]\n", device, ip);

	// 5 au lieu de index_sharedMem	
	memcpy((sharedMem + indexShm), ip, 13);

	return 0;
}
