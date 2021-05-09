#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <string.h>
#include <pcap/pcap.h>

int main()
{
    /**************************************************************************/
    //							SHARED_MEM
    /**************************************************************************/
    char *sharedMem;
    //	key_t	key = ftok(".", 36); // identifiant unique de la memoire paratagee
    key_t key = 36; // identifiant unique de la memoire paratagee
    size_t size = 50;
    int shmid; // return of shmget

    // creation memoire partagee avec droits d acces rxw
    if ((shmid = shmget(key, size, IPC_CREAT | 0666)) > 0)
    {
        // remplacer par un syslog
        printf("[capture] shmget: shmget returned %d\n", shmid);
    }

    // attach sharedmem to shmid
    if ((sharedMem = (char *)shmat(shmid, NULL, 0)) == (char *)(-1))
    {
        printf("erreur shmat\n");
        return 1;
    }
    // 6 au lieu de index_sharedMem
    memcpy(sharedMem, "toto_", 5);
    // printf(">>> sharedMem [%s]\n", sharedMem);

    /**************************************************************************/
    //							LIBPCAP
    /**************************************************************************/

    pcap_t *hdl;
    const u_int8_t *packet;
    char *device = NULL;
    char error_buffer[PCAP_ERRBUF_SIZE];
    int ret = 0;
    // histoire de tester pcap_lookupdev
    char ip[13];
    char subnet_mask[13];
    bpf_u_int32 ip_int;
    bpf_u_int32 subnet_mask_int;
    struct in_addr address;

    // histoire de tester lookupdev pour fetch devices

    if ((device = pcap_lookupdev(error_buffer)) == NULL) 
    {
        printf("%s\n", error_buffer);
        return 1;
    }

    ret = pcap_lookupnet("lo", &ip_int, &subnet_mask_int, error_buffer);

    if ((ret = pcap_lookupnet("lo", &ip_int, &subnet_mask_int, error_buffer)) == -1)
    {
        printf("%s\n", error_buffer);
        return 1;
    }

    address.s_addr = ip_int;
    strcpy(ip, inet_ntoa(address));

    // printf("Device : [%s] | IP address : [%s]\n", device, ip);
    // fflush(NULL);

    /**************************************************************************/
    //							LIBPCAP & SHM
    /**************************************************************************/
    // 5 au lieu de index_sharedMem
    memcpy((sharedMem + 5), ip, 13);

    printf("sharedmem : [%s]\n", sharedMem);

    shmdt(sharedMem);

    return 0;
}