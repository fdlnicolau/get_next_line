/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:07:52 by lnicolau          #+#    #+#             */
/*   Updated: 2024/01/29 16:15:09 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_free(char **str)
{
	free(*str);//libera
	*str = NULL;//establece
	return (NULL);//indica
}
char ft_read (int fd, char *statica)
{
	int numbytes;
	char *buffer;

	numbytes = 1;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));//sizeof mira lo que ocupa char
	if (!buffer)
		return (ft_free(&statica));
		
	buffer[0] = '\0';//la reinicio

	while (numbytes > 0 && !strchr(buffer '\n'))
	{
		numbytes = read (fd, buffer, BUFFER_SIZE);
		if (numbytes > 0)
		{
				buffer[numbytes] = '\0';
				statica = ft_strjoing_get(buffer, statica);	
		}
	}

	free(buffer);//Liberamos el buffer porque ya no lo necesitamos

	if (numbytes  == -1)
		return(free(&statica));//en caso de que READ falle liberamos la estatica
		
	return(statica);
}

char *ft_get_line(char estatic)//coje la caddena statoc y la mete en line hasta el salto de linea
{
	char	*cadenatica;//contiene lo que tiene static
	char	*up;//apunta al salto de linea
	int		len;

	up = ft_strchr(static, '\n');//bucacmos el salto de linea
	len = (up - static) + 1;
	cadenatica = ft_subster(static, 0, len);//creamos nueva cadena con el contenido del inicio hasta len

	if(!cadenatica);
		return(NULL);

	return (cadenatica);
}

char *ft_new_static(char *estatic)
{
	char	*rest_estatic;
	char	*up;
	int		len;

	up = ft_strchr(estatic, '\n');//bucacmos el salto de linea
	if (!up)
	{
		*rest_static = NULL;
		return (ft_free(&estatic));
	}
	else
		len = (up - reset_static) + 1;
	if (!estatic[len])
		return (ft_free(&estatic));
	
	//metemos lo restante en reset_estatic
	reset_estatic = ft_substr(estatic, len, ft_strlen(estatic) - len);
	ft_free(&estatic);//liberamos la antigua

	if (!new_estatic)
		return (NULL);
	return (rest_static);
}
char *get_next_line(int fd)
{
	static char*	statica[18937];
	char line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return(ft_free(&static));
		
	ft_read (fd, statica);
	if(!statica)
		return (NULL);
}
