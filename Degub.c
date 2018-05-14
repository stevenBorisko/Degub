#include "Degub.h"

#define ANSI_REDBLD "\33[31;1m"
#define ANSI_YLWBLD "\33[33;1m"
#define ANSI_WHTBLD "\33[37;1m"
#define ANSI_TXTRST "\33[0m"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void error(char* msg, int code) {
	#if DEGUB_ERROR_ON
	pthread_mutex_lock(&mutex);
	fprintf(stderr, ANSI_REDBLD "[ERROR]: " ANSI_TXTRST);
	fprintf(stderr,"%s\n",msg);
	fprintf(stderr,"\terror code: %d",code);
	if(code)
		fprintf(stderr," - %s",strerror(code));
	fprintf(stderr,"\n");
	pthread_mutex_unlock(&mutex);
	#endif
}

void warn(char* msg, int code) {
	#if DEGUB_WARN_ON
	pthread_mutex_lock(&mutex);
	fprintf(stderr, ANSI_YLWBLD " [WARN]: " ANSI_TXTRST);
	fprintf(stderr,"%s\n",msg);
	fprintf(stderr,"\twarning code: %d\n",code);
	pthread_mutex_unlock(&mutex);
	#endif
}

void info(char* msg, int code) {
	#if DEGUB_INFO_ON
	pthread_mutex_lock(&mutex);
	fprintf(stderr, ANSI_WHTBLD " [INFO]: " ANSI_TXTRST);
	fprintf(stderr,"%s\n",msg);
	fprintf(stderr,"\tinformation code: %d\n",code);
	pthread_mutex_unlock(&mutex);
	#endif
}
