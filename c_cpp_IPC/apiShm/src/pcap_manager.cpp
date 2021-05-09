#include "../include/apishm.hpp"

int		pcap_manager(char *device, char	*error_buffer, char *sharedMem)
{
	pcap_t				*hdl;
	const __u_char 		*packet;
	struct pcap_pkthdr	packet_header;
	int					packet_count_limit = 1;
	int					timeout_limit = 10000; // millisecond
	int					ret = 0;

	strcpy(device, "lo");

	hdl = pcap_create(device, error_buffer);
	ret = pcap_activate(hdl);
	
	hdl = pcap_open_live(device, BUFSIZ, packet_count_limit, timeout_limit, error_buffer);

	// lit le paquet suivant
	packet = pcap_next(hdl, &packet_header);

	if (packet == NULL)
	{
		printf("Absence de packet");
		return 2;
	}

	detectionFunc(packet, packet_header, sharedMem);	

	visionFunc(device, sharedMem, indexShm, error_buffer);

	printf("sharedmem : [%s]\n", sharedMem + 0);

	shmdt(sharedMem);

	return 0;
}
