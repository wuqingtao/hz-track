// main.cpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "host_parse.h"
#include "icmp_echo.h"
#include "icmp_tstamp.h"
#include "tcp_syn.h"
#include "tcp_ack.h"
#include "tcp_full.h"
#include "udp_full.h"

void usage();

int main(int argc, char** argv) {
	if (argc < 2) {
		usage();
		return 0;
	}
	
	if (strcmp(argv[1], "host_parse") == 0) {
		if (argc != 3) {
			usage();
			return 0;
		}
		const char* host = argv[2];
		host_parse hp;
		hp.action(host);
	} else if (strcmp(argv[1], "icmp_echo") == 0) {
		if (argc != 3) {
			usage();
			return 0;
		}
		const char* host = argv[2];
		icmp_echo ie;
		ie.action(host);
	} else if (strcmp(argv[1], "icmp_tstamp") == 0) {
		if (argc != 3) {
			usage();
			return 0;
		}
		const char* host = argv[2];
		icmp_tstamp it;
		it.action(host);
	} else if (strcmp(argv[1], "tcp_syn") == 0) {
		if (argc != 6) {
			usage();
			return 0;
		}
		const char* shost = argv[2];
		int sport = atoi(argv[3]);
		const char* dhost = argv[4];
		int dport = atoi(argv[5]);
		tcp_syn ts;
		ts.action(shost, sport, dhost, dport);
	} else if (strcmp(argv[1], "tcp_ack") == 0) {
		if (argc != 6) {
			usage();
			return 0;
		}
		const char* shost = argv[2];
		int sport = atoi(argv[3]);
		const char* dhost = argv[4];
		int dport = atoi(argv[5]);
		tcp_ack ta;
		ta.action(shost, sport, dhost, dport);
	} else if (strcmp(argv[1], "tcp_full") == 0) {
		if (argc != 4) {
			usage();
			return 0;
		}
		const char* host = argv[2];
		int port = atoi(argv[3]);
		tcp_full tf;
		tf.action(host, port);
	} else if (strcmp(argv[1], "udp_full") == 0) {
		if (argc != 6) {
			usage();
			return 0;
		}
		const char* shost = argv[2];
		int sport = atoi(argv[3]);
		const char* dhost = argv[4];
		int dport = atoi(argv[5]);
		udp_full uf;
		uf.action(shost, sport, dhost, dport);
	} else {
		usage();
	}
	
	return 0;
}

void usage() {
	printf("usage:\n");
	printf("  ./hztrack host_parse <host>\n");
	printf("  ./hztrack icmp_echo <host/ip>\n");
	printf("  ./hztrack icmp_tstamp <host/ip>\n");
	printf("  ./hztrack tcp_syn <local host/ip> <local port> <remote host/ip> <remote port>\n");
	printf("  ./hztrack tcp_ack <local host/ip> <local port> <remote host/ip> <remote port>\n");
	printf("  ./hztrack tcp_full <host/ip> <port>\n");
}
