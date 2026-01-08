/*
to store the students and quizzes using 2d array and pointers.
*/

#include <stdio.h>

#define STUDENTS 3 // Number of students
#define QUIZZES 4  // Number of quizzes

void calculateAverages(int (*scores)[QUIZZES], int students, int quizzes, float *averages)
{
    for (int i = 0; i < students; i++)
    {
        int sum = 0;
        for (int j = 0; j < quizzes; j++)
        {
            sum += *(*(scores + i) + j);
        }
        *(averages + i) = (float)sum / quizzes;
    }
}

int findHighestScoringStudent(float *averages, int students)
{
    int highestIndex = 0;
    for (int i = 1; i < students; i++)
    {
        if (*(averages + i) > *(averages + highestIndex))
        {
            highestIndex = i;
        }
    }
    return highestIndex;
}

int main()
{
    int scores[STUDENTS][QUIZZES] = {
        {75, 85, 95, 80},
        {88, 92, 78, 91},
        {83, 85, 88, 89}};
    float averages[STUDENTS];

    calculateAverages(scores, STUDENTS, QUIZZES, averages);

    for (int i = 0; i < STUDENTS; i++)
    {
        printf("Student %d average score: %.2f\n", i + 1, *(averages + i));
    }

    int highestScoringStudent = findHighestScoringStudent(averages, STUDENTS);
    printf("Highest scoring student is Student %d with an average score of %.2f\n",
           highestScoringStudent + 1, *(averages + highestScoringStudent));

    return 0;
}