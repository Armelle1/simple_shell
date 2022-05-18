#ifndef SHELL
#define SHELL
char *_getline(void);
int shell(char **argv, char **envp);
char *_getline1();
void _execve(char **arg, char **argv, char **envp);
int shell1(void);
#endif
