#include <stdio.h>
int main() {
	int x,y,i,n=90;
    FILE *apointer;
    if ((apointer = fopen("datasetLR2.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }

    // reads text until newline is encountered
    for(i=0;i<=n;i++){
    fscanf(apointer, "%d,%d\n", &x,&y);
    printf("%d,%d\n", x,y);
	}
    fclose(apointer);

    return 0;
}
