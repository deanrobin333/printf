/**
 * handle_plus_space_hash - handles the +, space, and # flags for non-custom conversion specifiers
 * @format: the format string to check for flags
 * @specifier: the non-custom conversion specifier being handled
 * Return: a string representing the flags to be applied, or an empty string if no flags are present
 */
char *handle_plus_space_hash(const char *format, char specifier)
{
	char *flags = "";
	int i;

	for (i = 0; format[i] != specifier && format[i] != '\0'; i++)
	{
		if (format[i] == '+')
		{
			flags = "+";
		}
		else if (format[i] == ' ')
		{
			flags = " ";
		}
		else if (format[i] == '#')
		{
			flags = "#";
		}
	}

	return flags;
}

