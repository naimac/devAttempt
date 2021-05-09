#ifndef PACKET_STRUCT_HPP
# define PACKET_STRUCT_HPP

// header recupere du header cpp de vision

namespace Packet
{

	struct headerEthernet
	{
		u_int8_t destinationHost[6];
		u_int8_t sourceHost[6];
		u_int16_t type;

		/**
		 * @brief convert little indiant to big indiant
		 * 
		 */
		void convert(void)
		{
			type = ntohs(type);
		}

		const char *typeToStr(void) const
		{
			switch (type)
			{
				case ETHERTYPE_PUP:
					return "PUP";
				case ETHERTYPE_SPRITE:
					return "SPRITE";
				case ETHERTYPE_IP:
					return "IP";
				case ETHERTYPE_ARP:
					return "ARP";
				case ETHERTYPE_REVARP:
					return "REVARP";
				case ETHERTYPE_AT:
					return "AT";
				case ETHERTYPE_AARP:
					return "AARP";
				case ETHERTYPE_VLAN:
					return "VLAN";
				case ETHERTYPE_IPX:
					return "IPX";
				case ETHERTYPE_IPV6:
					return "IPV6";
				case ETHERTYPE_LOOPBACK:
					return "LOOPBACK";
				default:
					return "unknown";
			}
		}
	};

	/**
	 * @brief header IP without options
	 * 
	 */
	struct headerIp
	{
		u_int8_t headerLength : 4,
				 version : 4;
		u_int8_t ecn : 2,
				 dscp : 6;
		u_int16_t totalLength;
		u_int16_t id;
		u_int16_t Fragment : 13,
				  flag : 3;
		u_int8_t timeToLeave;
		u_int8_t protocol;
		u_int16_t checksum;
		struct in_addr ipSource;
		struct in_addr ipDestination;

		/**
		 * @brief convert little indiant to big indiant
		 * 
		 */
		void convert(void)
		{
			totalLength = ntohs(totalLength);
			id = ntohs(id);
			checksum = ntohs(checksum);
		}

		const char *getIpSource(void) const
		{
			return inet_ntoa(ipSource);
		}

		const char *getIpDestination(void) const
		{
			return inet_ntoa(ipDestination);
		}

		const char *getStringDscp(void) const
		{
			switch ((u_char)dscp)
			{
				case IPTOS_DSCP_AF11 >> 2:
					return "AF11";
				case IPTOS_DSCP_AF12 >> 2:
					return "AF12";
				case IPTOS_DSCP_AF13 >> 2:
					return "AF13";
				case IPTOS_DSCP_AF21 >> 2:
					return "AF21";
				case IPTOS_DSCP_AF22 >> 2:
					return "AF22";
				case IPTOS_DSCP_AF23 >> 2:
					return "AF23";
				case IPTOS_DSCP_AF31 >> 2:
					return "AF31";
				case IPTOS_DSCP_AF32 >> 2:
					return "AF32";
				case IPTOS_DSCP_AF33 >> 2:
					return "AF33";
				case IPTOS_DSCP_AF41 >> 2:
					return "AF41";
				case IPTOS_DSCP_AF42 >> 2:
					return "AF42";
				case IPTOS_DSCP_AF43 >> 2:
					return "AF43";
				case IPTOS_DSCP_EF >> 2:
					return "EF";
				case IPTOS_CLASS_CS0 >> 2:
					return "CS0";
				case IPTOS_CLASS_CS1 >> 2:
					return "CS1";
				case IPTOS_CLASS_CS2 >> 2:
					return "CS2";
				case IPTOS_CLASS_CS3 >> 2:
					return "CS3";
				case IPTOS_CLASS_CS4 >> 2:
					return "CS4";
				case IPTOS_CLASS_CS5 >> 2:
					return "CS5";
				case IPTOS_CLASS_CS6 >> 2:
					return "CS6";
				case IPTOS_CLASS_CS7 >> 2:
					return "CS7";
				default:
					return "unknown";
			}
		}

		const char *getStringOfProtocol(void) const
		{
			switch (protocol)
			{
				case IPPROTO_IP:
					return "IP";
				case IPPROTO_ICMP:
					return "ICMP";
				case IPPROTO_IPIP:
					return "IPIP";
				case IPPROTO_TCP:
					return "TCP";
				case IPPROTO_EGP:
					return "EGP";
				case IPPROTO_PUP:
					return "PUP";
				case IPPROTO_UDP:
					return "UDP";
				case IPPROTO_IDP:
					return "IDP";
				case IPPROTO_TP:
					return "TP";
				case IPPROTO_DCCP:
					return "DCCP";
				case IPPROTO_IPV6:
					return "IPV6";
				case IPPROTO_RSVP:
					return "RSVP";
				case IPPROTO_GRE:
					return "GRE";
				case IPPROTO_ESP:
					return "ESP";
				case IPPROTO_AH:
					return "AH";
				case IPPROTO_MTP:
					return "MTP";
				case IPPROTO_BEETPH:
					return "BEETPH";
				case IPPROTO_ENCAP:
					return "ENCAP";
				case IPPROTO_PIM:
					return "PIM";
				case IPPROTO_COMP:
					return "COMP";
				case IPPROTO_SCTP:
					return "SCTP";
				case IPPROTO_UDPLITE:
					return "UDPLITE";
				case IPPROTO_MPLS:
					return "MPLS";
				case IPPROTO_RAW:
					return "RAW";
				default:
					return "unknown";
			}
		}
	};

	struct headerIpv6
	{
	};

	/**
	 * @brief header GRE without options
	 * 
	 */
	struct headerGre
	{
		u_int16_t version : 3,
				  reserved : 9,
				  sequenceNumBit : 1,
				  keyBit : 1,
				  routingBit : 1,
				  checksumBit : 1;
		u_int16_t protocol;

		/**
		 * @brief convert little indiant to big indiant
		 * 
		 */
		void convert(void)
		{
			checksumBit = ntohs(checksumBit);
			routingBit = ntohs(routingBit);
			keyBit = ntohs(keyBit);
			sequenceNumBit = ntohs(sequenceNumBit);
			reserved = ntohs(reserved);
			version = ntohs(version);
			protocol = ntohs(protocol);
		}
	};

	/**
	 * @brief header TCP without options
	 * 
	 */
	struct headerTcp
	{
		u_int16_t sourcePort;
		u_int16_t destinationPort;
		u_int32_t sequenceNumber;
		u_int32_t acknowledgmentNumber; // if ACK set
		u_int8_t NS : 1,
				 reserved : 3,
				 dataOffset : 4;
		u_int8_t FIN : 1,
				 SYN : 1,
				 RST : 1,
				 PSH : 1,
				 ACK : 1,
				 URG : 1,
				 ECE : 1,
				 CWR : 1;
		u_int16_t windowSize;
		u_int16_t checksum;
		u_int16_t urgentPointer; // if URG set

		/**
		 * @brief convert little indiant to big indiant
		 * 
		 */
		void convert(void)
		{
			sourcePort = ntohs(sourcePort);
			destinationPort = ntohs(destinationPort);
			sequenceNumber = ntohl(sequenceNumber);
			acknowledgmentNumber = ntohl(acknowledgmentNumber);
			windowSize = ntohs(windowSize);
			checksum = ntohs(checksum);
			urgentPointer = ntohs(urgentPointer);
		}
	};

	/**
	 * @brief header UDP without options
	 * 
	 */
	struct headerUdp
	{
		u_int16_t sourcePort;
		u_int16_t destinationPort;
		u_int16_t length;
		u_int16_t checksum;

		/**
		 * @brief convert little indiant to big indiant
		 * 
		 */
		void convert(void)
		{
			sourcePort = ntohs(sourcePort);
			destinationPort = ntohs(destinationPort);
			length = ntohs(length);
			checksum = ntohs(checksum);
		}
	};

} // namespace Packet

#endif
