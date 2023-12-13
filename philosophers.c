#include <stdio.h>
#include <stdlib.h>

typedef struct	s_philo
{
	int				id;
	struct s_philo	*next;
}				t_philo;


void	deletephilolist(t_philo *list)
{
	t_philo	*tmp;

	while (list->next)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	free(list);
}

t_philo	*lastphilo(t_philo *list)
{
	
	while (list->next)
	{
		list = list->next;
	}
	return (list);
}

void	addphilo(t_philo *list, t_philo *new_philo)
{
	t_philo	*philo;

	philo = lastphilo(list);
	if (!philo)
		list = new_philo;
	else
		philo->next = new_philo;
}

t_philo	*newphilo(int id)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
	{
		return (NULL);
	}
	philo->id = id;
	philo->next = NULL;
	return (philo);
}

int	main()
{
	t_philo *list;
	t_philo	*tmp;
	int		id;
	id = 1;
	list = NULL;
	list = newphilo(id);
	while (id++ < 4)
		addphilo(list, newphilo(id));
	tmp = list;
	while (tmp)
	{
		printf("philo id = %d\n", tmp->id);
		tmp = tmp->next;
	}
	deletephilolist(list);
	return 0;
}
