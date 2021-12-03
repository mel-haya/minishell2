#ifndef EXECUTION_H
# define EXECUTION_H
# include <stdio.h>
# include <sys/errno.h>
# include "../libft/libft.h"
# include "../minishell.h"

// typedef struct	s_env
// {
// 	char			*key; 
// 	char			*value; 
// 	struct s_env	*next;
// }                   t_env;

//--------------NODE UTILS----------------//

// void	delete_node(t_env *lst, t_env *target);

// //------- MINISHELL UTILS FUNCTIONS --------//
FILE *foo;
char    *get_path();
int     is_builtin(char *cmd);
int	exec_builtin(char **cmd);
int     arr_lenght(char **arr);
// void	free_arr(char **arr);

// //------ KEY VALUE FUNCTIONS ------------//
// int	find_key(t_env *env, char *target);
// char	*get_key_value(t_env *env, char *key_target);
// void	change_key_value(t_env *env, char *key_target, char *new_value);
// void	add_key_value(t_env *env, char *key, char *value);

// //------- LIST CONSTRUCTOR FUNCTIONS --------//

// t_env	*init_node(char *key, char *value);
// t_env	*get_lastnode(t_env *lst);
// void	add_node(t_env **lst, t_env *new_node);

// //------- LIST DESTRUCTOR FUNCTIONS --------//

// void	free_lst(t_env **lst);
void	exit_err(char *msg, char *output, int fd);

// //------- BUILTINS FUNCTIONS --------//

int	exec_echo(char **cmd);
int	exec_pwd();
int	exec_cd(char **cmd);
int	exec_export(char **cmd);
int	exec_unset(char **cmd);
int	exec_env(char **cmd);
void	exec_exit(char **cmd);

//merged version
void	execution();

// REDIRECTIONS

int    filter_redir();
char	*path_case_error();
void	pipes();
int	get_exitvalue(int ret);

#endif