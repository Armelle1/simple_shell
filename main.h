#ifndef SHELL
#define SHELL
char *_getline(void);
int shell(char ** argv, char **envp);
char *_getline1();
void _execve(char **, char **, char **);
int shell1(void);
#endif
