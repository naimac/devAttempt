#ifndef APISHM_HPP
# define APISHM_HPP

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <syslog.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <errno.h>
# include <pcap/pcap.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <net/ethernet.h>
# include <netinet/in.h>
# include <netinet/ip.h>
# include <netinet/if_ether.h>

#define SHM_MAXLEN 50
#define SHM_KEY 36

# include "packet_struct.hpp"

typedef struct s_memory_packet
{
	u_int32_t id;
	struct timeval timestamp;
	u_int32_t length;
	unsigned char t_memory_packet;
} t_memory_packet;

typedef struct s_capture_memory
{
	u_int32_t capture_id;
	u_int32_t table_size;
	u_int32_t table_index;
	u_int32_t table_size_packet;
	t_memory_packet table_packet[0];
} t_capture_memory;

struct gre_hdr
{
	u_int16_t version : 3,
		reserved : 9,
		sequenceNumBit : 1,
		keyBit : 1,
		routingBit : 1,
		checksumBit : 1;
	u_int16_t protocol;
};

// STATIC
static int indexShm = 0;

char *error_buffer[PCAP_ERRBUF_SIZE];

// u_int8_t == u_char
int		detectionFunc(const u_int8_t *packet, struct pcap_pkthdr packet_header, char *sharedMem);
int		sharedMem_handler(int key, size_t size, char *sharedMem);
char	*visionFunc(char *device, char *sharedMem, int indexShm, char *error_buffer);
char	*init_sharedMem(int key, int shm_maxlen);
int		pcap_manager(char *device, char	*error_buffer);

#endif
