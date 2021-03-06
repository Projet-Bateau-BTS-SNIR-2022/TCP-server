#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>

#define PORT 2300

using namespace std;

int sendData(string message)
{
    int erreur = 0;
    SOCKET sock;
    SOCKADDR_IN sin;
    SOCKET csock;
    SOCKADDR_IN csin;
    socklen_t recsize = sizeof(csin);
    int sock_err;
    sock = socket(AF_INET, SOCK_STREAM, 0);
 
        /* Si la socket est valide */
        if(sock != INVALID_SOCKET)
        {
            printf("La socket %d est maintenant ouverte en mode TCP/IP\n", sock);
 
            /* Configuration */
            sin.sin_addr.s_addr    = htonl(INADDR_ANY);   /* Adresse IP automatique */
            sin.sin_family         = AF_INET;             /* Protocole IP*/
            sin.sin_port           = htons(PORT);         /* Listage du port */
            sock_err = bind(sock, (SOCKADDR*)&sin, sizeof(sin));

            /* Si la socket fonctionne */
            if(sock_err != SOCKET_ERROR)
            {
                /* Démarrage du listage (mode server) */
                sock_err = listen(sock, 5);
                printf("Listage du port %d...\n", PORT);
                /* Attente pendant laquelle le client se connecte */
                printf("Patientez pendant que le client se connecte sur le port %d...\n", PORT);

                csock = accept(sock, (SOCKADDR*)&csin, &recsize);
                printf("Un client se connecte avec la socket %d de %s:%d\n", csock, inet_ntoa(csin.sin_addr), htons(csin.sin_port));

                sock_err = send(csock, message.c_str(), strlen(message.c_str()), 0);

                if(sock_err != SOCKET_ERROR)
                    //printf("Chaine envoyée : %s\n", buffer);
                    cout<<"Chaine envoyée :"<<message<<endl;
                else
                    printf("Erreur de transmission\n");

                /* Il ne faut pas oublier de fermer la connexion (fermée dans les deux sens) */
                shutdown(csock, 2);
            }
            /* Fermeture de la socket */
            printf("Fermeture de la socket...\n");
            closesocket(sock);
            printf("Fermeture du serveur terminee\n");
        }
    return EXIT_SUCCESS;
}
