#ifndef DEF_H_INCLUDED
#define DEF_H_INCLUDED

#include <stdint.h>

#define WELCOME_BANNER "     ____         ____                __\n" \
                       "    / __ \\ _  __ / __ ) ____   _____ / /__ _____\n" \
                       "   / / / /| |/_// __  |/ __ \\ / ___// //_// ___/\n" \
                       "  / /_/ /_>  < / /_/ // /_/ // /   / ,<  (__  )\n" \
                       " /_____//_/|_|/_____/ \\____//_/   /_/|_|/____/\n"

typedef enum e_kstat t_kstat;
enum e_kstat
{
  KSUCCESS = ((uint8_t)0),
  KFAILURE = ((uint8_t)-1)
};

/* When defined, prints out lots of useful information */
#define DEBUG

#endif
