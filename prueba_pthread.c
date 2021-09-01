#include "philo/platon.h"

/*int main(void)
{
    struct timeval ti, tf;

    double tiempo;

    gettimeofday(&ti, NULL);   // Instante inicial

    printf("Lee este mensaje y pulsa ENTER\n");

    getchar();

    gettimeofday(&tf, NULL);   // Instante final

    tiempo= (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0;

    printf("Has tardado: %g milisegundos\n", tiempo);
}*/


static void	*good_bye(void *inf)
{
	char *text = (char *)inf;

	while(1)
	{
		printf("%s\n", text);
		usleep(100000);
	}
}

int main(void)
{
	pthread_t p1;
	pthread_t p2;

	pthread_create(&p1, NULL, &good_bye, "hola");
	pthread_create(&p2, NULL, &good_bye, "adios");
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	return(0);
}

