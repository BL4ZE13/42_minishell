/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:56:41 by diomari           #+#    #+#             */
/*   Updated: 2023/11/22 10:32:46 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//mudar para PATH_MAX
int	update_pwd(char *str)
{
	char	buff[_PC_PATH_MAX];
	t_env	*env_cur;
	char	*c_cur;
	char	*c_cur2;

	if (getcwd(buff, sizeof(buff)) != NULL)
	{
		env_cur = e_search_lst(str);
		if (env_cur)
		{
			free(env_cur->ct);
			c_cur = ft_strdup(buff);
			c_cur2 = ft_strjoin(str, "=");
			env_cur->ct = ft_strjoin(c_cur2, c_cur);
			free(c_cur2);
			free(c_cur);
		}
	}
	return (1);
}

int	change_dir(char *path)
{
	update_pwd("OLDPWD");
	if (!chdir(path) && update_pwd("PWD"))
		all.status = 0;
	else
	{
		if (access(path, F_OK) == -1)
			write(2, "minishell: cd: no such file or directory\n", 42);
		else if (access(path, R_OK | W_OK | X_OK) == -1)
			write(2, "minishell: cd: permission denied\n", 34);
		else
			write(2, "minishell: cd: not a directory\n", 32);
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
		all.status = 1;
	}
	return (1);
}

void	finish_cd(char **env)
{
	ft_free_matrix(&env);
	all.status = 0;
	return ;
}

void	cd_exec(t_list **lst)
{
	char	*home_p;
	char	**env;

	top_lst(lst);
	if (ft_matrixlen((*lst)->ct) > 2)
	{
		write(2, "minishell: cd: too many arguments\n", 34);
		all.status = 1;
		return ;
	}
	env = ft_env_lst_to_array(all.env);
	home_p = e_search(env, "HOME");
	if (!(*lst)->ct[1] && change_dir(home_p))
		return (finish_cd(env));
	else
	{
		if (!ft_strcmp((*lst)->ct[1], "--") && change_dir(home_p))
			return (finish_cd(env));
		change_dir((*lst)->ct[1]);
	}
	ft_free_matrix(&env);
	return ;
}
