// Prints GPA's less than 2.

#include <stdio.h>
#include <string.h>

int main() {
    double gpa = 0.0;
    char studentID[10];
    
    File *fp;
    
    fp = fopen("student.txt", "r");
    
    while(!(feof(fp))) {
        
        fscanf(fp, "%s %lf", studentID, &gpa);
        
        if(gpa < 2.0) {
            printf("%s %d", studentID, gpa);
        }
    }
    
    return 0;
}
