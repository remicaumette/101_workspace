#include "minishell.h"


char		*process_getexec(t_shell *shell, char *file)
{
	char	*path;
	char	**paths;


	if (!ft_strncmp("./", file, 2) || !ft_strncmp("../", file, 3) || *file == '/')
	{
		if (!access(file, F_OK))
		{
			minishell_printerr(file, "No such file or directory");
			return (NULL);
		}
		else if (!access(file, X_OK))
		{
			minishell_printerr(file, "Permission denied");
			return (NULL);
		}
		return (ft_strdup(file));
	}
	if (!(path = shell_getenv(shell, "PATH")))
		return (NULL);
	if (!(paths = ft_strsplit(path, ':')))
		return (NULL);
	ft_strarr_del(paths);
	return (NULL);
}

int			process_run(t_shell *shell, t_cmd *cmd)
{
	t_builtin	builtin;
	pid_t		pid;
	char		*executable;
	int			status;
	char		**argv;


	if ((builtin = builtin_from_name(cmd->cmd)))
		return (builtin(shell, cmd));
	if (!(executable = process_getexec(shell, cmd->cmd)))
		return (1);
	if (!(argv = ft_strarr_add(NULL, executable)))
		return (1);
	status = -1;
	while (cmd->args && cmd->args[++status])
		if (!(argv = ft_strarr_add(argv, cmd->args[status])))
			return (1);
	pid = fork();
	if (pid)
		wait(&pid);
	else
	{
		if ((status = execve(executable, argv, shell->env)) == -1)
			return (1);
		ft_strarr_del(argv);
		return (status);
	}
	return (1);
}
