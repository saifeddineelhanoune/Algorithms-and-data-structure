/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FillData.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:59:43 by sel-hano          #+#    #+#             */
/*   Updated: 2023/08/20 07:34:26 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Students.h"

//the same as lst_new & lst_addfront
static t_StudentsInfo	*CreateStudent(char* ID, char* name, char* email, char* phone, int number_of_course) {
    t_StudentsInfo	*newNode = (t_StudentsInfo*)malloc(sizeof(t_StudentsInfo));
    if (newNode) 
	{
        strncpy(newNode->ID, ID, sizeof(newNode->ID) - 1);
        newNode->ID[sizeof(newNode->ID) - 1] = '\0';
        newNode->name = strdup(name);
        newNode->email = strdup(email);
        newNode->phone = strdup(phone);
        newNode->number_of_course = number_of_course;
        newNode->next = NULL;
    }
    return newNode;
}

static void AddStudentsToList(t_StudentsInfo** head, t_StudentsInfo* newNode) 
{
    if (newNode == NULL)
        return;

    newNode->next = *head;
    *head = newNode;
}

bool	isDuplicate(char ID[10], int size, char *newID)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(&ID[i], newID) == 0)
			return (true);// Duplicate found
	}
	return (false); // No duplicate found
}


// static void GenerateID(t_StudentsInfo *s, int size)
// {
//     const char set[] = SET;
//     srand(time(0));
// 	char ID[10] = {0};
//     char newID[10];
//     for (int i = 0; i < 10; i++)
//         newID[i] = set[random() % (sizeof(set) - 1)]; // Generate random value from charset
// 	newID[9] = '\0';
//     if (!isDuplicate(ID, size, newID))
//         strcpy(s->ID, newID); // Assign the unique ID to the ID field of the t_StudentsInfo structure
// }

static void ReadDataFromFile(t_StudentsInfo **students, const char* dir) 
{
    char* copied = strdup(dir); // Copy the directory path
    if (!copied)
        return;
    int fd = open(copied, O_RDONLY);
    free(copied);
    if (fd < 0)
        return;
    char* line = get_next_line(fd);
    int i = 0;
    while (line != NULL) 
	{
        char* tok = strtok(line, ",");
        if (!tok)
            break;
        char* ID = tok;
        tok = strtok(NULL, ",");
        if (!tok)
            break;
        char* name = tok;
        tok = strtok(NULL, ",");
        if (!tok)
            break;
        char* email = tok;
        tok = strtok(NULL, ",");
        if (!tok)
            break;
        char* phone = tok;
        tok = strtok(NULL, ",");
        if (!tok)
            break;
        int number_of_course = atoi(tok);
        t_StudentsInfo* NewStudent = CreateStudent(ID, name, email, phone, number_of_course);
        if (!NewStudent)
            break;
        AddStudentsToList(students, NewStudent);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    close(fd);
}

static void print_students(t_StudentsInfo *students)
{
	if (!students || !(students)->next)
		return ;
	while (students)
	{
		printf("student ID => %s\t", (students)->ID);
		printf("student NAME => %s\t", (students)->name);
		printf("student EMAIL => %s\t", (students)->email);
		printf("student PHONE => %s\t", (students)->phone);
		printf("student COURSE => %d\n", (students)->number_of_course);
		students = (students)->next;
	}
}

int main()
{
	t_StudentsInfo *s1 = NULL;
	// int count = 0;
	// printf("enter the count of students to set \n");
	// scanf("%d", &count);
	ReadDataFromFile(&s1, "./read/common/class1/students_data.csv");
	print_students(s1);
	return 0;
}
