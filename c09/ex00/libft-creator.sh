# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_sreator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 15:17:27 by sungwopa          #+#    #+#              #
#    Updated: 2021/03/11 15:51:10 by sungwopa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

rm -f libft.a
find . -name "*.c" -type f -maxdepth 1 -exec gcc -Wall -Werror -Wextra -c {} \;
ar -rc libft.a *.o
find . -name "*.o" -type f -maxdepth 1 -exec rm -rf {} \;
