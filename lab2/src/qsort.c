#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000 /* max #lines to be sorted */
#define MAXLEN 50 /*max length of each line */

char *lineptr[MAXLINES]; /* pointers to text lines */

// utility functions for reading/writing lines
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

// function for doing quick sort 
void quick_sort(void *lineptr[], int left, int right,
	// declaring a function pointer called comp
	int (*comp)(void *, void *));

// function that numerically compares two strings
int numcmp(char *, char *);

// swap function
void swap(void *v[], int, int);

/* sort input lines */
main(int argc, char *argv[])
{
	int nlines; /* number of input lines read */
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		quick_sort((void**) lineptr, 0, nlines-1, (int (*)(void*,void*))(strcmp));
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("input too big to sort\n");
		return 1;
	}
}

/* quick_sort: sort v[left]...v[right] into increasing order */
void quick_sort(void *v[], int left, int right, int (*comp)(void *, void *))
{
	int i, last;
	if (left >= right) 	/* do nothing if array contains */
		return; 		/* fewer than two elements */
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	quick_sort(v, left, last-1, comp);
	quick_sort(v, last+1, right, comp);
}

void swap(void *v[], int i, int j)
{
	void *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/* get_line: get line into s, return length */
int get_line(char *s, int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 &&(c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = get_line(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = malloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}

