#include "../include/apishm.hpp"

// methode de recuperation sur memoire partagee propre à detection
// par exemple, sur ce que propose la capture vision s'interesse au protocole
// tos
int		detectionFunc(const u_int8_t *packet, struct pcap_pkthdr packet_header, char *sharedMem)	
{
	(void)packet;
	(struct pcap_pkthdr)packet_header;
	(void)sharedMem;

	printf("detectionFunc\n");
	
	return 0;
}
