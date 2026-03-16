#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 10

typedef struct {
    int id;
    char name[50];
    int marks[MAX_SUBJECTS];
    int total;
    float average;
    char grade;
} Student;

char calc_grade(float avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 75) return 'B';
    else if (avg >= 60) return 'C';
    else if (avg >= 50) return 'D';
    return 'F';
}

int main() {
    int n, m, i, j;
    Student students[MAX_STUDENTS];

    printf("Enter number of students: ");
    scanf("%d", &n);
    printf("Enter number of subjects: ");
    scanf("%d", &m);

    for (i = 0; i < n; ++i) {
        students[i].total = 0;
        printf("\nStudent %d ID: ", i+1);
        scanf("%d", &students[i].id);
        printf("Name: ");
        scanf(" %49[^\n]", students[i].name);
        for (j = 0; j < m; ++j) {
            printf("Mark for subject %d: ", j+1);
            scanf("%d", &students[i].marks[j]);
            students[i].total += students[i].marks[j];
        }
        students[i].average = (float)students[i].total / m;
        students[i].grade = calc_grade(students[i].average);
    }

    // Display report
    printf("\n\nID\tName\tTotal\tAverage\tGrade\n");
    for (i = 0; i < n; ++i) {
        printf("%d\t%s\t%d\t%.2f\t%c\n",
            students[i].id, students[i].name, students[i].total,
            students[i].average, students[i].grade);
    }

    // Find top performer
    int top = 0;
    for (i = 1; i < n; ++i)
        if (students[i].total > students[top].total) top = i;

    printf("\nTop Performer: %s (ID: %d) Total: %d Average: %.2f\n",
        students[top].name, students[top].id, students[top].total, students[top].average);

    return 0;
}