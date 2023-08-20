/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetTime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 05:05:32 by sel-hano          #+#    #+#             */
/*   Updated: 2023/08/19 21:35:37 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operation.h"

void redirect_time(char *path, char *file_name)
{
    // Append the filename to the directory path
    char filepath[256];
    snprintf(filepath, sizeof(filepath), "%s/%s", path, file_name);
    // Open the file for writing
    int fd = open(filepath, O_WRONLY | O_CREAT , S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd == -1)
    {
        perror("Error opening file");
        return;
    }
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    // Write the date and time to the file
    dprintf(fd, "Date and time: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900,
            tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    // Close the file
    close(fd);
    printf("Date and time have been written to %s\n", filepath);
}

int main(void)
{
	redirect_time("DB/attendance/", "date_time.csv");
	return 0;
}