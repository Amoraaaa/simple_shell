#include "main.h"

/**
<<<<<<< HEAD
 * run_command - forks a new process to run the command
 *
 * @args: array of arguments from the stdin
 * @env: environment of the current running process
 * @path: environment path
 *
 * Return: 0 (Success), negative number (Failure)
 */

int run_command(char *args[], char *env[], char *path)
=======
* main_shell - main shell function
*
* @x1: name of the executable file
*
* Return: 0 (Exit_Success), negative (Exit_Failure)
*/

int main_shell(char *x1)
>>>>>>> 83ea31a0f9f100e5bb64a56bf5d49d0bcc5c0454
{
	pid_t cpid = -1;
	int Wstatus, retStats = 0, f_accss;
	char *fpath = full_path(args[0], path);

<<<<<<< HEAD
	retStats = check_command(fpath, args);
	if (!fpath)
		return (ERR_NOT_FOUND);
=======
	signal(SIGINT, sigint_handler);
	if (e1)
		_puts(PROMPT);

	while ((c1 = getline(&y1, &d1, stdin)) != -1)
	{
		if (y1)
		{
			a1++;
			z1 = trim_string(y1);

			if (z1 && _strcmp(z1, "exit") == 0)
				free(z1), free(y1), _exit(EXIT_STATUS);
			if (z1)
				b1 = shell_handler(z1);

			if (b1 == ERROR_NOT_FOUND)
				not_found_err(x1, z1, a1);
			else if (b1 == PERM_DENIED)
				perm_denied_err(x1, z1, a1);
			else
				EXIT_STATUS = b1;

			if (z1)
				free(z1);
		}
			if (e1)
				_puts(PROMPT);
	}
	free(y1);
	if (e1)
		_putchar('\n');
	exit(EXIT_STATUS);
}

/*
* @f: array of arguments from the stdin
* @g: environment of the current running process
* @h: environment path
*
* Return: 0 (Success), negative number (Failure)
*/
int execute_command(char *f[], char *g[], char *h)
{
	pid_t i = -1;
	int j, k = 0, l;
	char *m = full_path(f[0], h);
>>>>>>> 83ea31a0f9f100e5bb64a56bf5d49d0bcc5c0454

	f_accss = access(fpath, F_OK);
	if (f_accss != -1)
		cpid = fork();
	else
		return (ERR_NOT_FOUND);

	if (cpid == -1)
		retStats = ERR_NO_FORK;
	else if (cpid == 0)
	{
		if (execve(fpath, args, env) != -1)
		{
			if (errno == EACCES)
				exit(PERM_DENIED);
			exit(1);
		}
	}
	else
	{
		waitpid(cpid, &Wstatus, 0);
		if (WIFEXITED(Wstatus) && WEXITSTATUS(Wstatus) == PERM_DENIED)
		{
			if (_strcmp(fpath, args[0]) != 0)
				free(fpath);
			return (PERM_DENIED);
		}
	}
	if (_strcmp(fpath, args[0]) != 0)
		free(fpath);

	return (retStats);
}

/**
 * shell_handler - process the inputs before running it
 *
 * @command: command from stdin before preprocessing
 *
 * Return: 0 (Success), negative number (Failure)
 */

int shell_handler(char command[])
{
	char *args[BUFF_SIZE], **ret, *env_path;
	int exec = 0, i = 0;

	ret = args_split(command);
	if (!ret)
		return (ERR_NO_SPLIT);
	env_path = _getenv(PATH);
	while (ret[i])
		args[i] = ret[i], i++;

	args[i] = NULL;
	free(ret);

	if (_strcmp(args[0], "env") == 0)
	{
		print_env();
		free(env_path);
		return (exec);
	}
	exec = run_command(args, __environ, env_path);
	free(env_path);
	return (exec);
}

/**
 * shell - main shell function
 *
 * @prog_name: name of the executable file
 *
 * Return: 0 (Exit_Success), negative (Exit_Failure)
 */

int shell(char *prog_name)
{
	char *command = NULL, *new_cmnd = NULL;
	unsigned int cnt = 0;
	int ret = 0, gtret = 0;
	size_t n = 0;
	const int IS_ATTY = isatty(STDIN_FILENO);

<<<<<<< HEAD
	signal(SIGINT, sigint_handler);
	if (IS_ATTY)
		_puts(PROMPT);
=======
	r = execute_command(o, __environ, q);
	free(q);
>>>>>>> 83ea31a0f9f100e5bb64a56bf5d49d0bcc5c0454

	while ((gtret = getline(&command, &n, stdin)) != -1)
	{
		if (command)
		{
			cnt++;
			new_cmnd = trim_string(command);
			if (new_cmnd && _strcmp(new_cmnd, "exit") == 0)
				free(new_cmnd), free(command), builtin_exit(EXIT_ST);
			if (new_cmnd)
				ret = shell_handler(new_cmnd);

			if (ret == ERR_NOT_FOUND)
				_puts_not_found(prog_name, new_cmnd, cnt);
			else if (ret == PERM_DENIED)
				_puts_denied(prog_name, new_cmnd, cnt);
			else
				EXIT_ST = ret;

			if (new_cmnd)
				free(new_cmnd);
		}
		if (IS_ATTY)
			_puts(PROMPT);
	}
	free(command);
	if (IS_ATTY)
		_putchar('\n');
	exit(EXIT_ST);
}

